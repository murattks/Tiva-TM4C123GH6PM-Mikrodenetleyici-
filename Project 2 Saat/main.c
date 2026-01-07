
#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"


// 1. PIN VE LIMIT TANIMLAMALARI
// Pin Maskeleri (Port F'nin ilgili bitleri)
#define SW1 (1U << 4) // PF4 (Hizi Artir/Azalt)
#define SW2 (1U << 0) // PF0 (Hizi Artir/Cogalt)
#define LED_KIRMIZI (1U << 1) // PF1 (Kirmizi LED)

// GPIO Port F Veri Yazmacinin Bit Addressi icin temel adresi
// Adres = GPIO_PORTF_BASE + (PIN_MASK << 2)
#define GPIO_PORTF_BASE 0x40025000U

// Global Gecikme Sayaci
volatile int GecikmeSayaci = 100000;

// Gecikme limitleri
#define MIN_GECIKME 10000  // Minimum bekleme süresi (En hizli)
#define MAX_GECIKME 500000 // Maksimum bekleme süresi (En yavas)
#define GECIKME_ADIMI 50000 // Her basista degisim miktari


//  FONKSIYON PROTOTIPLERI
void init();
void GecikmeKontrol();
void Bekle();


void init()
{
    // 1. Port F'yi enerjilendirdik
    SYSCTL_RCGCGPIO_R |= (1U << 5);

    // Port F'nin hazir olmasini bekler (Birkaç döngü zamaný kazandýrýr)
    volatile int gecikme = 0;
    while ((SYSCTL_PRGPIO_R & (1U << 5)) == 0) {
        gecikme++;
    }

    // 2. PF0 Kilidi Kaldirma (PF0 kilitlidir ve SW2'ye baglidir)
    GPIO_PORTF_LOCK_R = 0x4C4F434B; // Kilit anahtari
    GPIO_PORTF_CR_R |= SW2;         // PF0'in degismesine izin ver (0x01)

    // 3. Yon Ayari: PF1 Output (LED), PF0/PF4 Input (Butonlar)
    GPIO_PORTF_DIR_R |= LED_KIRMIZI; // PF1'i ÇIKIÞ yapar

    // 4. Pull-Up Direnci (PF0 ve PF4 için - Butonlar)
    GPIO_PORTF_PUR_R |= (SW1 | SW2); // Butonlara Pull-Up direnci ekle

    // 5. Dijital Etkinlestirme (PF0, PF1 ve PF4)
    GPIO_PORTF_DEN_R |= (SW1 | SW2 | LED_KIRMIZI);
}


void GecikmeKontrol()
{
    // SW1 (PF4) kontrolü: Basildiysa LOW (0) verir -> Süreyi Azalt (Hizlan)
    if ((GPIO_PORTF_DATA_R & SW1) == 0)
    {
        if (GecikmeSayaci > MIN_GECIKME) {
             GecikmeSayaci -= GECIKME_ADIMI;
        }
        // DEBOUNCING: Butondan el çekilene kadar bekle
        while ((GPIO_PORTF_DATA_R & SW1) == 0);
    }

    // SW2 (PF0) kontrolü: Basildiysa LOW (0) verir -> Süreyi Artir (Yavasla)
    else if ((GPIO_PORTF_DATA_R & SW2) == 0)
    {
        if (GecikmeSayaci < MAX_GECIKME) {
             GecikmeSayaci += GECIKME_ADIMI;
        }
        // DEBOUNCING: Butondan el çekilene kadar bekle
        while ((GPIO_PORTF_DATA_R & SW2) == 0);
    }
}

void Bekle()
{
    // Bit-Specific Addressing kullanarak LED'i YAK (HIGH yap)
    // Sadece PF1 pinini etkiler
    *(volatile uint32_t *)(GPIO_PORTF_BASE + (LED_KIRMIZI << 2)) = LED_KIRMIZI;

    // Yanik kalma süresi kadar bekle
    volatile int i;
    for (i = 0; i < GecikmeSayaci; i++);

    // LED'i SÖNDÜR (LOW yap)
    // Sadece PF1 pinini etkiler, 0 yazar.
    *(volatile uint32_t *)(GPIO_PORTF_BASE + (LED_KIRMIZI << 2)) = 0;

    // Sönük kalma süresi kadar bekle
    for (i = 0; i < GecikmeSayaci; i++);
}


// MAIN FONKSIYONU (Ana Program)

void main(void)
{
    init();

    // Baslangicta kirmizi LED'i söndür (LOW yap)
    // Bit-Specific Addressing
    *(volatile uint32_t *)(GPIO_PORTF_BASE + (LED_KIRMIZI << 2)) = 0;

    while(1)
    {
        // 1. Buton durumunu kontrol et ve hizi ayarla
        GecikmeKontrol();

        // 2. Mevcut hizda LED'i yakip söndür
        Bekle();
    }
}
