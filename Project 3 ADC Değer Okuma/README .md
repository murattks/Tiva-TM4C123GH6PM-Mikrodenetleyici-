---

## 🇬🇧 ENGLISH 

# Project 3: ADC Reading on LCD Display with Tiva C Series TM4C123G

This project displays analog data read from a potentiometer on a 16x2 LCD screen by using the internal ADC (Analog-to-Digital Converter) of the **Tiva C Series TM4C123G LaunchPad**. It shows both the raw digital value and the calculated voltage value in real-time.

---

## 📋 Project Summary

- **ADC Configuration:**
  - The system reads analog voltage from a potentiometer connected to pin **PE3**.
  - The internal ADC converts this analog signal into a 12-bit digital value (0-4095).
- **Data Processing & Display:**
  - The code calculates the actual voltage based on the 3.3V reference.
  - The LCD displays the raw value on the first row and the calculated voltage on the second row.

---

## 🛠 Requirements

### Hardware:
- Tiva C Series TM4C123G LaunchPad  
- 16x2 LCD Display  
- 10kΩ Potentiometer (for ADC Input)
- 10kΩ Potentiometer or Trimpot (for LCD contrast adjustment)  
- Jumper wires  
- Breadboard

### Software:
- **Code Composer Studio (CCS)** or **Keil uVision**
- **TivaWare Peripheral Driver Library**

---

## ⚙️ Hardware Connections

### LCD Connections (Port B):

| LCD Pin  | TM4C123G LaunchPad Pin |
|----------|-------------------------|
| VSS      | GND                     |
| VDD      | VBUS (5V)               |
| V0       | Potentiometer (Contrast)|
| RS       | PB0                     |
| RW       | GND                     |
| E        | PB1                     |
| D4       | PB4                     |
| D5       | PB5                     |
| D6       | PB6                     |
| D7       | PB7                     |
| A        | 5V (or 3.3V)            |
| K        | GND                     |

> **Note:** **PB7** is a locked pin (NMI) on the TM4C123G. The code includes a specific unlocking sequence (`GPIO_LOCK_KEY`) to use it as a GPIO output.

### ADC Connections (Port E):

| Component       | TM4C123G LaunchPad Pin |
|-----------------|-------------------------|
| Potentiometer Signal | PE3 (AIN0)         |
| Potentiometer VCC    | 3.3V               |
| Potentiometer GND    | GND                |

---

## 📂 Project Logic

1. **ADC Sampling:**
   - The ADC0 module is configured on Sequencer 3 (SS3) to take a single sample from channel **AIN0 (PE3)**.
   - The sampling is triggered by the processor in the main loop.

2. **Calculation:**
   - The 12-bit ADC value ($0 - 4095$) is converted to voltage using the formula: 
     $$Voltage = \frac{ADC\_Value \times 3.3}{4095}$$

3. **Display Update:**
   - The LCD is cleared and updated continuously with the new values.
   - Row 1: `ADC Value: [xxxx]`
   - Row 2: `Voltage: [x.xx] V`

---

## 📄 File Structure

- **main.c:** Main control code for ADC setup, reading, and calculation logic.  
- **lcd.h:** Header file for LCD control and pin definitions.  
- **lcd.c:** Functions to control the LCD via GPIO (includes PB7 unlock mechanism).  

---

## 🚀 Setup and Execution

1. **Connect the Hardware:**
   Connect the LCD and the Potentiometer to the Tiva C LaunchPad according to the tables above.

2. **Compile and Upload the Code:**
   - Open the project in your IDE (CCS/Keil).  
   - Ensure `TivaWare` library is included in the build path.
   - Compile and upload it to the Tiva C.  

3. **Run:**
   - Turn the potentiometer knob.
   - Observe the changing values on the LCD screen.
   - If the screen is blank, adjust the contrast potentiometer connected to V0.




---

## 🇹🇷 TÜRKÇE 

---


# Tiva C Serisi TM4C123G ile LCD Üzerinde ADC Değer Okuma

Bu proje, **Tiva C Serisi TM4C123G LaunchPad** kartının dahili ADC (Analog-Dijital Dönüştürücü) modülünü kullanarak bir potansiyometreden gelen analog veriyi okur ve 16x2 LCD ekranda gösterir. Ekranda hem ham dijital değer hem de hesaplanan voltaj değeri gerçek zamanlı olarak sunulur.

---

## 📋 Proje Özeti

- **ADC Yapılandırması:**
  - Sistem, **PE3** pinine bağlı bir potansiyometreden analog voltajı okur.
  - Dahili ADC modülü bu sinyali 12-bitlik dijital bir değere (0-4095) çevirir.
- **Veri İşleme ve Gösterim:**
  - Kod, 3.3V referans voltajına göre gerçek voltaj değerini hesaplar.
  - LCD ekranın ilk satırında ham ADC değeri, ikinci satırında ise hesaplanan voltaj değeri gösterilir.

---

## 🛠 Gereksinimler

### Donanım:
- Tiva C Serisi TM4C123G LaunchPad
- 16x2 LCD Ekran
- 10kΩ Potansiyometre (ADC Girişi için)
- 10kΩ Potansiyometre veya Trimpot (LCD kontrast ayarı için)
- Bağlantı kabloları ve Breadboard

### Yazılım:
- **Code Composer Studio (CCS)** veya **Keil uVision**
- **TivaWare Peripheral Driver Library**

---

## ⚙️ Donanım Bağlantıları

### LCD Bağlantıları (Port B):

| LCD Pin  | TM4C123G LaunchPad Pin |
|----------|-------------------------|
| VSS      | GND                     |
| VDD      | VBUS (5V)               |
| V0       | Potansiyometre (Kontrast)|
| RS       | PB0                     |
| RW       | GND                     |
| E        | PB1                     |
| D4       | PB4                     |
| D5       | PB5                     |
| D6       | PB6                     |
| D7       | PB7                     |
| A        | 5V (veya 3.3V)          |
| K        | GND                     |

> **Not:** **PB7** pini TM4C123G üzerinde kilitli bir pindir (NMI). Kod içerisinde bu pini çıkış olarak kullanmak için özel bir kilit açma (`GPIO_LOCK_KEY`) mekanizması bulunur.

### ADC Bağlantıları (Port E):

| Bileşen         | TM4C123G LaunchPad Pin |
|-----------------|-------------------------|
| Potansiyometre Sinyal | PE3 (AIN0)      |
| Potansiyometre VCC    | 3.3V            |
| Potansiyometre GND    | GND             |

---

## 📂 Proje Çalışma Mantığı

1. **ADC Örnekleme:**
   - ADC0 modülü, **AIN0 (PE3)** kanalından tek bir örnek almak üzere Sequencer 3 (SS3) ile yapılandırılır.
   - Örnekleme ana döngü içerisinde işlemci tarafından tetiklenir.

2. **Hesaplama:**
   - Okunan 12-bitlik ADC değeri ($0 - 4095$), aşağıdaki formül ile voltaja çevrilir:
     $$Voltaj = \frac{ADC\_Degeri \times 3.3}{4095}$$

3. **Ekran Güncelleme:**
   - LCD sürekli temizlenir ve yeni değerlerle güncellenir.
   - 1. Satır: `ADC Deger: [xxxx]`
   - 2. Satır: `Voltaj: [x.xx] V`

---

## 📄 Dosya Yapısı

- **main.c:** ADC kurulumu, okuma ve hesaplama mantığını içeren ana kod dosyası.
- **lcd.h:** LCD kontrolü ve pin tanımlamaları için başlık dosyası.
- **lcd.c:** LCD'nin GPIO üzerinden sürülmesini sağlayan fonksiyonlar (PB7 kilidini açma dahil).

---

## 🚀 Kurulum ve Çalıştırma

1. **Donanımı Bağla:**
   LCD ve potansiyometreyi yukarıdaki tablolara göre Tiva C LaunchPad'e bağla.

2. **Kodları Derle ve Yükle:**
   - Proje dosyalarını IDE'de (CCS/Keil) aç.
   - `TivaWare` kütüphanesinin projeye dahil edildiğinden emin ol.
   - Kodu derle ve Tiva C'ye yükle.

3. **Çalıştır:**
   - Potansiyometreyi çevir.
   - LCD ekrandaki değerlerin değişimini gözlemle.
   - Eğer ekranda görüntü yoksa, V0 pinine bağlı kontrast potansiyometresini ayarla.