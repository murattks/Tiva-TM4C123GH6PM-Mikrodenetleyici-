#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "driverlib/adc.h"

// --- PIN TANIMLARI ---
#define LCD_PORT_BASE   GPIO_PORTB_BASE
#define LCD_PERIPH      SYSCTL_PERIPH_GPIOB
#define LCD_RS          GPIO_PIN_0
#define LCD_E           GPIO_PIN_1

// --- GLOBAL DEÐÝÞKENLER ---
int saat = 0, dakika = 0, saniye = 0;
uint32_t adcVerisi[1];
char gelenBuffer[50];
int gelenIndex = 0;
char lcdMetin[4] = "   "; // 3 Karakterlik metin alaný

// --- YARDIMCI FONKSÝYONLAR ---
void IntToString(char *buffer, int sayi, int basamak) {
    int i;
    for(i = basamak - 1; i >= 0; i--) {
        buffer[i] = (sayi % 10) + '0';
        sayi /= 10;
    }
    buffer[basamak] = '\0';
}

void UART_Yaz(char *s) {
    while(*s) { UARTCharPut(UART0_BASE, *s); s++; }
}

// --- LCD PARÇALARI ---
void Lcd_Pulse(void) {
    GPIOPinWrite(LCD_PORT_BASE, LCD_E, LCD_E); SysCtlDelay(400);
    GPIOPinWrite(LCD_PORT_BASE, LCD_E, 0);     SysCtlDelay(400);
}
void Lcd_Gonder(unsigned char d, unsigned char t) {
    if(t==0) GPIOPinWrite(LCD_PORT_BASE, LCD_RS, 0); else GPIOPinWrite(LCD_PORT_BASE, LCD_RS, LCD_RS);
    GPIOPinWrite(LCD_PORT_BASE, 0xF0, (d & 0xF0)); Lcd_Pulse();
    GPIOPinWrite(LCD_PORT_BASE, 0xF0, ((d<<4) & 0xF0)); Lcd_Pulse();
    if(t==0 && d<4) SysCtlDelay(50000); else SysCtlDelay(2000);
}
void Lcd_Komut(unsigned char c) { Lcd_Gonder(c, 0); }
void Lcd_Yaz(char *s) { while(*s) { Lcd_Gonder(*s, 1); s++; } }
void Lcd_Konum(int x, int y) { Lcd_Komut((x==1?0x80:0xC0)+(y-1)); }

void Lcd_Init(void) {
    SysCtlPeripheralEnable(LCD_PERIPH); while(!SysCtlPeripheralReady(LCD_PERIPH));
    HWREG(LCD_PORT_BASE+GPIO_O_LOCK)=0x4C4F434B; HWREG(LCD_PORT_BASE+GPIO_O_CR)|=0x80;
    GPIOPinTypeGPIOOutput(LCD_PORT_BASE, 0xFF); SysCtlDelay(50000);
    GPIOPinWrite(LCD_PORT_BASE, LCD_RS, 0);
    GPIOPinWrite(LCD_PORT_BASE, 0xF0, 0x30); Lcd_Pulse(); SysCtlDelay(100000);
    GPIOPinWrite(LCD_PORT_BASE, 0xF0, 0x30); Lcd_Pulse(); SysCtlDelay(5000);
    GPIOPinWrite(LCD_PORT_BASE, 0xF0, 0x30); Lcd_Pulse(); SysCtlDelay(5000);
    GPIOPinWrite(LCD_PORT_BASE, 0xF0, 0x20); Lcd_Pulse(); SysCtlDelay(5000);
    Lcd_Komut(0x28); Lcd_Komut(0x0C); Lcd_Komut(0x06); Lcd_Komut(0x01); SysCtlDelay(50000);
}

// --- DONANIM AYARLARI ---
void Setup(void) {
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);

    // ADC (PE3)
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_ADC0));
    GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_3);
    ADCSequenceConfigure(ADC0_BASE, 3, ADC_TRIGGER_PROCESSOR, 0);
    ADCSequenceStepConfigure(ADC0_BASE, 3, 0, ADC_CTL_CH0 | ADC_CTL_IE | ADC_CTL_END);
    ADCSequenceEnable(ADC0_BASE, 3);
    ADCIntClear(ADC0_BASE, 3);

    // Buton & LED (PF4 & PF2)
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF));
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= 0x10;
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);

    // UART
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART0));
    GPIOPinConfigure(GPIO_PA0_U0RX); GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0|GPIO_PIN_1);
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 9600, (UART_CONFIG_WLEN_8|UART_CONFIG_STOP_ONE|UART_CONFIG_PAR_NONE));

    Lcd_Init();
}

int main(void) {
    char tempStr[10];
    int zamanSayaci = 0;

    Setup();
    Lcd_Konum(1,1); Lcd_Yaz("Sistem Basliyor");

    while(1) {
        // --- 1. PC'DEN VERÝ OKUMA (KESÝNTÝSÝZ) ---
        while(UARTCharsAvail(UART0_BASE)) {
            char c = UARTCharGet(UART0_BASE);
            if(c == '*') { gelenIndex = 0; }
            else if(c == '#') {
                gelenBuffer[gelenIndex] = 0;

                // SAAT AYARI (PC'den Gerçek Zaman Geldi)
                if(gelenBuffer[0] == 'S') {
                    saat = (gelenBuffer[1]-'0')*10 + (gelenBuffer[2]-'0');
                    dakika = (gelenBuffer[4]-'0')*10 + (gelenBuffer[5]-'0');
                    saniye = (gelenBuffer[7]-'0')*10 + (gelenBuffer[8]-'0');
                }
                // METÝN AYARI
                else if(gelenBuffer[0] == 'M') {
                    lcdMetin[0] = gelenBuffer[1];
                    lcdMetin[1] = gelenBuffer[2];
                    lcdMetin[2] = gelenBuffer[3];
                    lcdMetin[3] = 0;
                }
            }
            else { if(gelenIndex < 40) gelenBuffer[gelenIndex++] = c; }
        }

        // --- 2. ZAMANLAYICI (1 Saniye Kontrolü) ---
        SysCtlDelay(SysCtlClockGet() / 300);
        zamanSayaci++;

        if(zamanSayaci >= 100) {
            zamanSayaci = 0;

            // Saati Ýlerlet
            saniye++;
            if(saniye >= 60) { saniye = 0; dakika++; }
            if(dakika >= 60) { dakika = 0; saat++; }
            if(saat >= 24) saat = 0;

            // Sensör ve Buton Oku
            ADCProcessorTrigger(ADC0_BASE, 3);
            while(!ADCIntStatus(ADC0_BASE, 3, false));
            ADCIntClear(ADC0_BASE, 3);
            ADCSequenceDataGet(ADC0_BASE, 3, adcVerisi);
            int btn = (GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4) & GPIO_PIN_4) ? 0 : 1;

            // --- PC'YE RAPOR GÖNDER ---
            UARTCharPut(UART0_BASE, '*');
            IntToString(tempStr, saat, 2); UART_Yaz(tempStr); UARTCharPut(UART0_BASE, ':');
            IntToString(tempStr, dakika, 2); UART_Yaz(tempStr); UARTCharPut(UART0_BASE, ':');
            IntToString(tempStr, saniye, 2); UART_Yaz(tempStr);
            UARTCharPut(UART0_BASE, ',');

            if(adcVerisi[0] < 1000) IntToString(tempStr, adcVerisi[0], 3);
            else IntToString(tempStr, adcVerisi[0], 4);
            UART_Yaz(tempStr);

            UARTCharPut(UART0_BASE, ',');
            UARTCharPut(UART0_BASE, btn + '0');
            UARTCharPut(UART0_BASE, '#');
            UARTCharPut(UART0_BASE, '\n');

            // --- LCD GÜNCELLE (DÜZELTME BURADA) ---
            IntToString(tempStr, saat, 2); Lcd_Konum(1,1); Lcd_Yaz(tempStr); Lcd_Yaz(":");
            IntToString(tempStr, dakika, 2); Lcd_Yaz(tempStr); Lcd_Yaz(":");
            IntToString(tempStr, saniye, 2); Lcd_Yaz(tempStr);

            // BURASI ESKÝ YAZIYI SÝLER:
            Lcd_Yaz("       ");

            Lcd_Konum(2,1); Lcd_Yaz("Metin: "); Lcd_Yaz(lcdMetin);

            // LED Göz Kýrp
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);
            SysCtlDelay(SysCtlClockGet() / 300);
            GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0);
        }
    }
}

// Kukla Fonksiyonlar (Hata önleyici)
void UART0IntHandler(void){}
void Timer0IntHandler(void){}
