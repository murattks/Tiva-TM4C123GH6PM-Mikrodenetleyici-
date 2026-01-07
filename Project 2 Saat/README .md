
---

## 🇬🇧 ENGLISH 

# Serial Port Clock Display with Tiva C Series TM4C123G LaunchPad

This project displays clock data on a 16x2 LCD screen by enabling serial communication between **Tiva C Series TM4C123G LaunchPad** and **SharpDevelop**. The user sends time data from SharpDevelop, and the Tiva C begins counting from the specified time.

---

## 📋 Project Summary

- **Clock Setup:**
  - The user sends time information (e.g., 12:34:56) via the SharpDevelop interface.
  - Tiva C receives and processes this data and displays the time on the 16x2 LCD.
  - The clock starts counting from the received value and updates every second.

---

## 🛠 Requirements

### Hardware:
- Tiva C Series TM4C123G LaunchPad  
- 16x2 LCD Display  
- Potentiometer (for LCD contrast adjustment)  
- Jumper wires  

### Software:
- **Code Composer Studio (CCS)**  
- **SharpDevelop**  
- **TivaWare API Library**

---

## ⚙️ Hardware Connections

### LCD Connections:

| LCD Pin  | TM4C123G LaunchPad Pin |
|----------|-------------------------|
| VSS      | GND                     |
| VDD      | VBUS                    |
| V0       | Potentiometer           |
| RS       | PB0                     |
| RW       | GND                     |
| E        | PB1                     |
| D4       | PB4                     |
| D5       | PB5                     |
| D6       | PB6                     |
| D7       | PB7                     |
| A        | 5V                      |
| K        | GND                     |

---

## 📂 Project Logic

1. **Communication with SharpDevelop:**
   - The user sends time data in `HH:MM:SS` format through the SharpDevelop interface.
   - Tiva C receives the time and displays it on the first row of the LCD.

2. **Time Counting:**
   - A timer module on the Tiva C increments the time every second.
   - The LCD continuously displays the updated time.

---

## 📄 File Structure

- **main.c:** Main control code for Tiva C  
- **lcd.h:** Header file for LCD control  
- **lcd.c:** Functions to control the LCD via GPIO  
- **uart.c:** UART communication functions  
- **sharpdevelop_ui.sln:** Project file for the SharpDevelop interface  

---

## 🚀 Setup and Execution

1. **Connect the Hardware:**
   Connect the LCD to the Tiva C LaunchPad according to the table above.

2. **Compile and Upload the Code:**
   - Open the project in Code Composer Studio.  
   - Compile and upload it to the Tiva C.  

3. **SharpDevelop Interface:**
   - Open and run the SharpDevelop project.  
   - Select the correct COM port for the connected Tiva C.  

4. **Run:**
   - Send the time data from SharpDevelop.  
   - Observe the clock starting and counting on the LCD.




---

## 🇹🇷 TÜRKÇE 

---


# Tiva C Serisi TM4C123G LaunchPad ile Seri Port Saat Gösterimi

Bu proje, **Tiva C Serisi TM4C123G LaunchPad** ile **SharpDevelop** arasında seri haberleşme sağlayarak saat verilerini LCD ekran üzerinde göstermeyi amaçlar. Kullanıcı, SharpDevelop üzerinden saat bilgilerini gönderir ve Tiva C üzerinde saat saymaya başlar.

---

## 📋 Proje Özeti

- **Saat Ayarı:**
  - Kullanıcı, SharpDevelop arayüzünden saat bilgisi (örneğin, 12:34:56) gönderir.
  - Tiva C bu veriyi alır, işlemlerden geçirir ve 16x2 LCD ekran üzerinde saat bilgisi gösterilir.
  - Saat, gönderilen değer üzerinden saymaya başlar ve her saniye güncellenir.

---

## 🛠 Gereksinimler

### Donanım:
- Tiva C Serisi TM4C123G LaunchPad
- 16x2 LCD Ekran
- Potansiyometre (LCD kontrast ayarı için)
- Bağlantı kabloları

### Yazılım:
- **Code Composer Studio (CCS)**
- **SharpDevelop**
- **TivaWare API Kütüphanesi**

---

## ⚙️ Donanım Bağlantıları

### LCD Bağlantıları:
| LCD Pin  | TM4C123G LaunchPad Pin |
|----------|-------------------------|
| VSS      | GND                     |
| VDD      | VBUS                    |
| V0       | Potansiyometre          |
| RS       | PB0                     |
| RW       | GND                     |
| E        | PB1                     |
| D4       | PB4                     |
| D5       | PB5                     |
| D6       | PB6                     |
| D7       | PB7                     |
| A        | 5V                      |
| K        | GND                     |

---

## 📂 Proje Çalışma Mantığı

1. **SharpDevelop ile Haberleşme:**
   - Kullanıcı, SharpDevelop arayüzünden saat bilgisi (örneğin, `HH:MM:SS` formatında) gönderir.
   - Saat bilgisi, Tiva C tarafından alınır ve LCD'nin ilk satırında gösterilir.

2. **Saat Saydırma:**
   - Tiva C üzerindeki bir zamanlayıcı (timer) kullanılarak saat bilgisi her saniye artırılır.
   - LCD ekran, sürekli olarak güncellenen saati gösterir.

---

## 📄 Dosya Yapısı

- **main.c:** Tiva C ana kontrol kodu.
- **lcd.h:** LCD kontrolü için kullanılan header dosyası.
- **lcd.c:** LCD'nin GPIO ile haberleşmesini sağlayan fonksiyonlar.
- **uart.c:** Seri port haberleşmesi için gerekli UART fonksiyonları.
- **sharpdevelop_ui.sln:** SharpDevelop kullanıcı arayüzü için proje dosyası.

---

## 🚀 Kurulum ve Çalıştırma

1. **Donanımı Bağla:**
   Yukarıdaki tabloya göre LCD'yi Tiva C LaunchPad'e bağla.

2. **Kodları Derle ve Yükle:**
   - Code Composer Studio'da proje dosyalarını aç.
   - Kodu derle ve Tiva C'ye yükle.

3. **SharpDevelop Arayüzü:**
   - SharpDevelop projesini aç ve çalıştır.
   - Tiva C'nin bağlı olduğu COM portunu seç.

4. **Çalıştır:**
   - SharpDevelop üzerinden saat bilgisi gönder.
   - LCD'de saatin başladığını ve saymaya devam ettiğini gözlemle.

---
