#include "stdint.h"
#include "stdbool.h"
#include "inc/hw_ints.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "Lcd.h"

void Lcd_init() {

    SysCtlPeripheralEnable(LCDPORTENABLE);
    GPIOPinTypeGPIOOutput(LCDPORT, 0xFF); // RS, E ve Datalar (PB0-PB7) çýkýþ

    // Gerekli baþlangýç gecikmesi (en az 15ms)
    SysCtlDelay(SysCtlClockGet() / 3 / 50); // ~20ms bekle

    // 4-bit moda geçiþ sekansý
    GPIOPinWrite(LCDPORT, RS, 0x00 ); // RS = 0 (Komut modu)

    // --- BAÞLANGIÇ SEKANSI DÜZELTMESÝ ---
    // LCD 8-bit modda baþlar. 4-bit moda geçmek için 0x3 nibble'ý gönderilir.
    // Pinleriniz D4=PB2, D5=PB3 olduðundan 0x3 (0011) göndermek için
    // Porta 0x0C (0000 1100) yazýlmalýdýr.

    // 1. Gönderim
    GPIOPinWrite(LCDPORT, D4 | D5 | D6 | D7, 0x0C ); // 0x3 nibble'ý gönder
    GPIOPinWrite(LCDPORT, E, 0x02); // E=1
    SysCtlDelay(100);
    GPIOPinWrite(LCDPORT, E, 0x00); // E=0

    SysCtlDelay(SysCtlClockGet() / 3 / 200); // ~5ms bekle

    // 2. Gönderim
    GPIOPinWrite(LCDPORT, D4 | D5 | D6 | D7, 0x0C ); // 0x3 nibble'ý gönder
    GPIOPinWrite(LCDPORT, E, 0x02); // E=1
    SysCtlDelay(100);
    GPIOPinWrite(LCDPORT, E, 0x00); // E=0

    SysCtlDelay(SysCtlClockGet() / 3 / 1000); // ~1ms bekle

    // 3. Gönderim
    GPIOPinWrite(LCDPORT, D4 | D5 | D6 | D7, 0x0C ); // 0x3 nibble'ý gönder
    GPIOPinWrite(LCDPORT, E, 0x02); // E=1
    SysCtlDelay(100);
    GPIOPinWrite(LCDPORT, E, 0x00); // E=0

    SysCtlDelay(SysCtlClockGet() / 3 / 1000); // ~1ms bekle

    // --- BÝTÝÞ ---

    // Artýk 4-bit moda geçmek için 0x2 (Binary 0010) gönder
    // Pinleriniz D4=PB2, D5=PB3 olduðundan 0x2 (0010) göndermek için
    // Porta 0x08 (0000 1000) yazýlmalýdýr (Sadece D5=1).

    GPIOPinWrite(LCDPORT, D4 | D5 | D6 | D7, 0x08 ); // 4-bit modu ayarla
    GPIOPinWrite(LCDPORT, E, 0x02); // E=1
    SysCtlDelay(100);
    GPIOPinWrite(LCDPORT, E, 0x00); // E=0

    SysCtlDelay(SysCtlClockGet() / 3 / 1000); // ~1ms bekle

    // 4-bit mod ayarlandý, artýk Lcd_Komut fonksiyonu kullanýlabilir
    Lcd_Komut(0x28); // 4-bit mod, 2 satýr, 5x8 font
    Lcd_Komut(0x0C); // Ekran açýk, imleç kapalý
    Lcd_Komut(0x06); // Giriþ modu: Otomatik artýrma (imleç saða kaysýn)

    Lcd_Temizle();
}

void Lcd_Komut(unsigned char c) {

    // Üst 4 bit gönder
    GPIOPinWrite(LCDPORT, D4 | D5 | D6 | D7, (c & 0xf0) >> 2 ); // D7-D4 verisi D5-D2 pinlerine kaydýrýlýr
    GPIOPinWrite(LCDPORT, RS, 0x00);
    GPIOPinWrite(LCDPORT, E, 0x02);
    SysCtlDelay(100);
    GPIOPinWrite(LCDPORT, E, 0x00);

    SysCtlDelay(50000);

    // Alt 4 bit gönder
    GPIOPinWrite(LCDPORT, D4 | D5 | D6 | D7, (c & 0x0f) << 2 ); // D3-D0 verisi D5-D2 pinlerine kaydýrýlýr
    GPIOPinWrite(LCDPORT, RS, 0x00);
    GPIOPinWrite(LCDPORT, E, 0x02);
    SysCtlDelay(100);
    GPIOPinWrite(LCDPORT, E, 0x00);

    SysCtlDelay(50000);
}

void Lcd_Putch(unsigned char d) {

    // Üst 4 bit gönder (RS=1)
    GPIOPinWrite(LCDPORT, D4 | D5 | D6 | D7, (d & 0xf0) >> 2 );
    GPIOPinWrite(LCDPORT, RS, 0x01);
    GPIOPinWrite(LCDPORT, E, 0x02);
    SysCtlDelay(100);
    GPIOPinWrite(LCDPORT, E, 0x00);

    SysCtlDelay(50000);

    // Alt 4 bit gönder (RS=1)
    GPIOPinWrite(LCDPORT, D4 | D5 | D6 | D7, (d & 0x0f) << 2 );
    GPIOPinWrite(LCDPORT, RS, 0x01);
    GPIOPinWrite(LCDPORT, E, 0x02);
    SysCtlDelay(100);
    GPIOPinWrite(LCDPORT, E, 0x00);

    SysCtlDelay(50000);
}

void Lcd_Goto(char x, char y){
    unsigned char add;
    if(x==1)
        add = 0x80 + y;
    else
        add = 0xC0 + y;
    Lcd_Komut(add);
}

void Lcd_Temizle(void){
    Lcd_Komut(0x01); // Ekraný temizle komutu
    SysCtlDelay(SysCtlClockGet() / 3 / 200); // Temizleme için uzun bekleme (yaklaþýk 2ms)
}

void Lcd_Puts( char* s){
    while(*s)
        Lcd_Putch(*s++);
}
