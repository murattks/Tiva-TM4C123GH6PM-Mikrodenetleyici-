
---

## 🇬🇧 ENGLISH 

# 16x2 LCD Interface with Tiva C Series LaunchPad

This project was developed to demonstrate the basic functions of a **16x2 LCD display** using the **Tiva C Series TM4C123G LaunchPad**. It provides control of the LCD via GPIO pins and teaches fundamental LCD commands through practical application. The code was written and tested in the **Code Composer Studio** environment.

---

## 📋 Project Summary

- **LCD Control:**
  - The LCD is operated in **4-bit mode**.
  - Characters and commands are sent to the LCD using GPIO pins.
- **Main Functions:**
  - Printing text on the LCD.
  - Clearing the LCD and controlling the cursor.
  - Adjusting the LCD contrast.

---

## 🛠 Required Components

- **16x2 LCD Display**
- **10kΩ Potentiometer** (for contrast adjustment)
- **Breadboard**
- **Jumper Wires**
- **Tiva C Series TM4C123G LaunchPad**

---

## ⚙️ Connections

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

## 🚀 Running the Project

1. **Connect the Hardware:**
   - Connect the LCD and potentiometer to the Tiva C LaunchPad according to the table above.
   - Use the potentiometer on the V0 pin of the LCD to adjust contrast.

2. **Compile and Upload the Code:**
   - Open the project files in **Code Composer Studio**.
   - Compile the code and upload it to the Tiva C microcontroller.

3. **Run:**
   - Power the Tiva C LaunchPad.
   - Observe the text and basic commands working on the LCD display.

---

## 📝 Notes

- The LCD is used in **4-bit mode**, which reduces the number of GPIO pins required.
- The potentiometer allows for easy contrast adjustment of the LCD.
- The RW pin is connected to GND, meaning the LCD operates in **write-only mode**.

---





---

## 🇹🇷 TÜRKÇE 

---


# Tiva C Serisi LaunchPad ile 16x2 LCD Arayüzü

Bu proje, **Tiva C Serisi TM4C123G LaunchPad** kullanılarak **16x2 LCD ekranın** temel işlevlerini göstermek amacıyla geliştirilmiştir. Proje, GPIO pinleri aracılığıyla LCD ekranın kontrolünü sağlar ve temel LCD komutlarını uygulamalı olarak öğretir. Kodlar **Code Composer Studio** ortamında yazılmış ve test edilmiştir.

---

## 📋 Proje Özeti

- **LCD Kontrolü:**
  - LCD, **4-bit modda** çalıştırılmıştır.
  - GPIO pinleri kullanılarak karakterler ve komutlar LCD'ye gönderilmiştir.
- **Başlıca İşlevler:**
  - LCD'ye metin yazdırma.
  - LCD'nin temizlenmesi ve imleç kontrolü.
  - LCD ekranın kontrast ayarı.

---

## 🛠 Gerekli Malzemeler

- **16x2 LCD Ekran**
- **10kΩ Potansiyometre** (LCD kontrast ayarı için)
- **Breadboard**
- **Bağlantı Kabloları**
- **Tiva C Serisi TM4C123G LaunchPad**

---

## ⚙️ Bağlantılar

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

## 🚀 Projenin Çalıştırılması

1. **Donanımı Bağla:**
   - Yukarıdaki tabloya göre LCD ekranı ve potansiyometreyi Tiva C LaunchPad'e bağlayın.
   - LCD'nin V0 pini ile potansiyometreyi bağlayarak kontrast ayarını yapabilirsiniz.

2. **Kodları Derle ve Yükle:**
   - **Code Composer Studio**'da proje dosyalarını açın.
   - Kodu derleyip Tiva C mikrodenetleyiciye yükleyin.

3. **Çalıştır:**
   - Tiva C'nin güç bağlantısını sağlayın.
   - LCD üzerinde metinlerin ve temel komutların çalıştığını gözlemleyin.

---

## 📝 İlgili Notlar

- LCD ekran **4-bit modda** çalıştırılmıştır. Bu, daha az GPIO pini kullanarak ekran kontrolü sağlar.
- Potansiyometre kullanılarak LCD kontrastı kolayca ayarlanabilir.
- RW pini GND'ye bağlanmıştır, bu nedenle LCD sadece **yazma modu**nda çalışır.

---


