#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/rom_map.h"
#include "lcd.h"


// LCD'ye sinyal göndermek için Enable ucunu tetikler
// High yap -> Bekle -> Low yap
void Lcd_Pulse_Enable(void) {
    GPIOPinWrite(LCD_PORT_BASE, LCD_E, LCD_E);
    SysCtlDelay(1000); // Biraz bekle
    GPIOPinWrite(LCD_PORT_BASE, LCD_E, 0);
    SysCtlDelay(1000); // Biraz bekle
}

// LCD'ye veri veya komut gönderen ana fonksiyon
// type: 0 ise KOMUT (RS=0), 1 ise VERÝ (RS=1)
void Lcd_Gonder(unsigned char data, unsigned char type) {
    // 1. RS Pinini ayarla
    if (type == 0)
        GPIOPinWrite(LCD_PORT_BASE, LCD_RS, 0); // Komut modu
    else
        GPIOPinWrite(LCD_PORT_BASE, LCD_RS, LCD_RS); // Veri modu

    // 2. Üst 4 biti gönder
    //D4-D7 pinleri PB4-PB7'ye baðlý olduðu için
    // datayý maskeleyip direkt porta yazabiliriz.
    GPIOPinWrite(LCD_PORT_BASE, 0xF0, (data & 0xF0));
    Lcd_Pulse_Enable();

    // 3. Alt 4 biti gönder
    // Alt 4 biti sola kaydýrarak PB4-PB7 hizasýna getiriyoruz
    GPIOPinWrite(LCD_PORT_BASE, 0xF0, ((data << 4) & 0xF0));
    Lcd_Pulse_Enable();

    // LCD iþlem yapabilsin diye kýsa bir gecikme
    if(type == 0 && data < 4)
        SysCtlDelay(50000); // Clear komutu uzun sürer
    else
        SysCtlDelay(2000);
}

void Lcd_Komut(unsigned char komut) {
    Lcd_Gonder(komut, 0); // 0 = Komut
}

void Lcd_Yaz_Char(unsigned char data) {
    Lcd_Gonder(data, 1);  // 1 = Veri
}

void Lcd_Yaz_String(char *str) {
    while(*str) {
        Lcd_Yaz_Char(*str);
        str++;
    }
}

void Lcd_Temizle(void) {
    Lcd_Komut(0x01); // Ekran temizleme komutu
    SysCtlDelay(50000);
}

void Lcd_Konum(int satir, int sutun) {
    unsigned char adres;
    if (satir == 1)
        adres = 0x80 + (sutun - 1); // 1. Satýr baþlangýcý 0x80
    else
        adres = 0xC0 + (sutun - 1); // 2. Satýr baþlangýcý 0xC0 (veya 0xC0)

    Lcd_Komut(adres);
}

void Lcd_Init(void) {
    // 1. Port B'nin saatini aktif et
    SysCtlPeripheralEnable(LCD_PERIPH);
    while(!SysCtlPeripheralReady(LCD_PERIPH)); // Hazýr olana kadar bekle

    // PB7 KÝLÝDÝNÝ AÇMA ---
    //PB7 pini korumalýdýr. LCD D7 pini buraya baðlý olduðu için
    // kilidi açmazsak çalýþmaz.
    HWREG(LCD_PORT_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY; // Kilidi açma þifresi
    HWREG(LCD_PORT_BASE + GPIO_O_CR) |= 0x80;           // PB7 (8. bit) için register onayla
    HWREG(LCD_PORT_BASE + GPIO_O_LOCK) = 0;             // Tekrar kilitle
    // ----------------------------------------

    // 2. Pinleri ÇIKIÞ olarak ayarla (PB0, PB1, PB4, PB5, PB6, PB7)
    GPIOPinTypeGPIOOutput(LCD_PORT_BASE, LCD_RS | LCD_E | LCD_D4 | LCD_D5 | LCD_D6 | LCD_D7);

    // LCD Açýlýþ Beklemesi (LCD'nin elektriði oturana kadar bekle)
    SysCtlDelay(500000);

    // 3. LCD Baþlatma Sekansý (4-bit mod resetleme adýmlarý)
    // Manuel olarak RS=0 yap
    GPIOPinWrite(LCD_PORT_BASE, LCD_RS, 0);

    // Baþlatma "sihirli" reset komutlarý (Datasheet standardý)
    GPIOPinWrite(LCD_PORT_BASE, 0xF0, 0x30); Lcd_Pulse_Enable(); SysCtlDelay(150000);
    GPIOPinWrite(LCD_PORT_BASE, 0xF0, 0x30); Lcd_Pulse_Enable(); SysCtlDelay(5000);
    GPIOPinWrite(LCD_PORT_BASE, 0xF0, 0x30); Lcd_Pulse_Enable(); SysCtlDelay(5000);

    // 4-Bit moduna geçiþ komutu (0x20)
    GPIOPinWrite(LCD_PORT_BASE, 0xF0, 0x20); Lcd_Pulse_Enable(); SysCtlDelay(5000);

    // Artýk normal komutlarý gönderebiliriz
    Lcd_Komut(0x28); // 4-bit mod, 2 satýr, 5x8 font
    Lcd_Komut(0x0C); // Ekran AÇIK, Ýmleç KAPALI (Yanýp sönmesin)
    Lcd_Komut(0x06); // Yazdýkça imleç saða kaysýn
    Lcd_Temizle();   // Ekraný temizle

}

