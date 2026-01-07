#ifndef LCD_H_
#define LCD_H_

// LCD baðlantý makrolarý: C kodundaki kaydýrma mantýðý ile uyumlu pinler
#define LCDPORT       GPIO_PORTB_BASE
#define LCDPORTENABLE SYSCTL_PERIPH_GPIOB
#define RS            GPIO_PIN_0    // Register Select
#define E             GPIO_PIN_1    // Enable
#define D4            GPIO_PIN_2    // Data Pin 4
#define D5            GPIO_PIN_3    // Data Pin 5
#define D6            GPIO_PIN_4    // Data Pin 6
#define D7            GPIO_PIN_5    // Data Pin 7

// Fonksiyon prototipleri
void Lcd_Komut(unsigned char);
void Lcd_Temizle(void);
void Lcd_Puts(char*);
void Lcd_Goto(char, char);
void Lcd_init(void);
void Lcd_Putch(unsigned char);

#endif /* LCD_H_ */
