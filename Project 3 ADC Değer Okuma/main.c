
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h> // sprintf ve string iþlemleri için
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/adc.h"
#include "lcd.h" // Sizin lcd.h dosyanýz

// Deðiþkenler
uint32_t ui32ADC0Value[1]; // ADC'den okunan ham deðer dizisi
float voltaj;              // Hesaplanmýþ voltaj
char buffer[16];           // Ekrana yazýlacak yazý dizisi

void Setup_ADC(void) {
    // 1. ADC0 ve GPIO Port E modüllerini aktif et
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);

    // Modüllerin hazýr olmasýný bekle
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_ADC0));

    // 2. PE3 pinini ADC giriþi olarak ayarla
    GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_3);

    // 3. ADC Örnekleyici (Sequencer) Ayarlarý
    // ADC0, Sequencer 3 (tek örnekleme için), Ýþlemci tetiklemeli, Öncelik 0
    ADCSequenceConfigure(ADC0_BASE, 3, ADC_TRIGGER_PROCESSOR, 0);

    // 4. Sequencer Adýmlarý
    // Adým 0: Kanal 0'ý (PE3) oku, Kesme bayraðýný set et (IE), Ýþlemi bitir (END)
    ADCSequenceStepConfigure(ADC0_BASE, 3, 0, ADC_CTL_CH0 | ADC_CTL_IE | ADC_CTL_END);

    // 5. ADC Sequencer'ý aktif et
    ADCSequenceEnable(ADC0_BASE, 3);

    // Ýlk baþta gürültüyü temizlemek için ADC kesmesini temizle
    ADCIntClear(ADC0_BASE, 3);
}

int main(void) {
    // Sistem Saatini Ayarla (Opsiyonel ama önerilir - 40 MHz)
    SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);

    // Sizin LCD fonksiyonlarýnýzla baþlatma
    Lcd_Init();

    // ADC Kurulumu
    Setup_ADC();

    // Açýlýþ Ekraný
    Lcd_Temizle();
    Lcd_Konum(1, 1);
    Lcd_Yaz_String("ADC Uygulamasi");
    Lcd_Konum(2, 1);
    Lcd_Yaz_String("Baslatiliyor...");

    SysCtlDelay(40000000); // Yaklaþýk 1-2 saniye bekleme
    Lcd_Temizle();

    while(1) {
        // --- ADC OKUMA ÝÞLEMÝ ---
        // ADC dönüþümünü tetikle
        ADCProcessorTrigger(ADC0_BASE, 3);

        // Dönüþümün bitmesini bekle
        while(!ADCIntStatus(ADC0_BASE, 3, false));

        // ADC kesme bayraðýný temizle
        ADCIntClear(ADC0_BASE, 3);

        // Veriyi oku (Sequencer 3'ten)
        ADCSequenceDataGet(ADC0_BASE, 3, ui32ADC0Value);

        // --- HESAPLAMA ---
        // Okunan deðer (0-4095) -> Voltaja çevir (3.3V referans)
        voltaj = (ui32ADC0Value[0] * 3.3) / 4095.0;

        // --- LCD YAZDIRMA ---

        // 1. Satýr: Ham ADC Deðeri
        Lcd_Konum(1, 1);
        sprintf(buffer, "ADC Deger: %4u", ui32ADC0Value[0]);
        Lcd_Yaz_String(buffer);

        // 2. Satýr: Voltaj Deðeri
        Lcd_Konum(2, 1);
        sprintf(buffer, "Voltaj: %.2f V", voltaj);
        Lcd_Yaz_String(buffer);

        // Okuma hýzýný ayarla (Çok hýzlý olursa ekran titrer)
        SysCtlDelay(SysCtlClockGet() / 10); // Yaklaþýk 300ms gecikme
    }
}
