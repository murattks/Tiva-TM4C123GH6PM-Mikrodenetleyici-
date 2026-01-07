
#ifndef LCD_H_
#define LCD_H_

#include <stdint.h>
#include <stdbool.h>

// baðlantýlara göre Port ve Pin tanýmlarý
#define LCD_PORT_BASE   GPIO_PORTB_BASE
#define LCD_PERIPH      SYSCTL_PERIPH_GPIOB

// Kontrol Pinleri
#define LCD_RS          GPIO_PIN_0  // RS -> PB0
#define LCD_E           GPIO_PIN_1  // E  -> PB1

// Veri Pinleri (D4-D7 -> PB4-PB7)
#define LCD_D4          GPIO_PIN_4
#define LCD_D5          GPIO_PIN_5
#define LCD_D6          GPIO_PIN_6
#define LCD_D7          GPIO_PIN_7

// Main dosyasýnýn göreceði komutlar
void Lcd_Init(void);                    // LCD'yi baþlat
void Lcd_Komut(unsigned char komut);    // LCD'ye komut gönder (Ekraný sil, imleci kapat vs.)
void Lcd_Yaz_Char(unsigned char data);  // Tek bir karakter yaz
void Lcd_Yaz_String(char *str);         // Kelime/Cümle yaz
void Lcd_Temizle(void);                 // Ekraný temizle
void Lcd_Konum(int satir, int sutun);   // Ýmleci istediðin yere koy (1,1 veya 2,1 gibi)

#endif /* LCD_H_ */


