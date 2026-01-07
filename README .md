---

## 🇬🇧 ENGLISH 


# Tiva C Series TM4C123G LaunchPad Projects

This repository contains various projects developed using the **Tiva C Series TM4C123G LaunchPad**. The projects focus on microcontroller applications such as LCD usage, floating point mathematical operations, hibernate mode, and serial communication.

---

## 📋 Project List

### 1. **Using a 16x2 LCD**
- **Description:** A project designed to learn the basics of using a **16x2 LCD screen** with Tiva C. The LCD is controlled via GPIO pins.
- **Features:**
  - The LCD operates in 4-bit mode.
  - Text display and basic LCD commands were tested.
- **Hardware Used:**
  - Tiva C Series LaunchPad  
  - 16x2 LCD display  
- [Click here for more details.](./Projects/Project%201)

---

### 2. **Basic Clock Application with Microcontroller**
- **Description:** A clock application that starts from **00:00:00** and continuously increments seconds using a timer on the microcontroller.
- **Features:**
  - Seconds are counted using the Timer module.
  - Time (hours, minutes, seconds) is displayed on the LCD.
- **Hardware Used:**
  - Tiva C Series LaunchPad  
  - 16x2 LCD display  
- [Click here for more details.](./Projects/Project%202)

---

### 3. **Sending Time via Serial Port**
- **Description:** Time is sent from SharpDevelop via serial communication and displayed on the LCD.
- **Features:**
  - Time information is sent from SharpDevelop.
  - Time is displayed on the LCD and updated continuously.
- **Hardware Used:**
  - Tiva C Series LaunchPad  
  - 16x2 LCD display  
- [Click here for more details.](./Projects/Project%203)

---

### 4. **Sending Time and Text via Serial Port**
- **Description:** Both time and text information are sent to the LCD via serial communication using SharpDevelop.
- **Features:**
  - Time and temperature information is shown on the first row of the LCD.
  - Custom text entered in SharpDevelop is displayed on the second row.
- **Hardware Used:**
  - Tiva C Series LaunchPad  
  - LM35DZ temperature sensor  
  - 16x2 LCD display  
- [Click here for more details.](./Projects/Project%204)

---

## 🚀 How to Use?

1. Navigate to the related folder for each project and check the **README.md** file.
2. To download and run the code:
   - Clone the repository:
     ```bash
     git clone https://github.com/murattks/Tiva-TM4C123GH6PM-Mikrodenetleyici-.git
     ```
   - Go to the corresponding project folder and review the source code.
3. Use **Code Composer Studio** to compile and upload the code to your Tiva C LaunchPad.


---

## 🇹🇷 TÜRKÇE 

---

# Tiva C Serisi TM4C123G LaunchPad Projeleri

Bu repo, **Tiva C Serisi TM4C123G LaunchPad** kullanılarak geliştirilmiş çeşitli projeleri içermektedir. Projeler, mikrodenetleyici uygulamaları, LCD kullanımı, floating point matematiksel işlemler, hibernate modu ve seri haberleşme gibi konulara odaklanmaktadır.

---

## 📋 Proje Listesi

### 1. **16x2 LCD Kullanımı**
   - **Açıklama:** Tiva C ile **16x2 LCD ekranın** temellerini öğrenmek için tasarlanmış bir projedir. GPIO pinleri ile LCD ekran kontrol edilmiştir.
   - **Özellikler:**
     - LCD ekran, 4-bit modda çalıştırılmıştır.
     - Metin yazdırma ve temel LCD komutları test edilmiştir.
   - **Kullanılan Donanım:**
     - Tiva C Serisi LaunchPad
     - 16x2 LCD ekran
   - [Detaylar için buraya tıklayın.](./Projects/Project%201)

---

### 2. **Mikrodenetleyici ile Temel Saat Uygulaması**
   - **Açıklama:** Mikrodenetleyici üzerinde bir timer kullanılarak **00:00:00**'dan itibaren başlayan ve sürekli olarak saniyeyi artıran bir saat uygulaması gerçekleştirilmiştir.
   - **Özellikler:**
     - Timer modülü ile saniye sayımı yapılmıştır.
     - Saat, dakika ve saniye değerleri LCD ekranında gösterilmiştir.
   - **Kullanılan Donanım:**
     - Tiva C Serisi LaunchPad
     - 16x2 LCD ekran
   - [Detaylar için buraya tıklayın.](./Projects/Project%202)

---

### 3. **Seri Port ile Saat Gönderimi**
   - **Açıklama:** SharpDevelop ile seri haberleşme gerçekleştirilerek LCD'de saat gösterimi sağlanmıştır.
   - **Özellikler:**
     - SharpDevelop üzerinden saat bilgisi gönderilir.
     - Saat LCD'de gösterilir ve sürekli sayar.
   - **Kullanılan Donanım:**
     - Tiva C Serisi LaunchPad
     - 16x2 LCD ekran
   - [Detaylar için buraya tıklayın.](./Projects/Project%203)

---

### 4. **Seri Port ile Saat ve Metin Gönderimi**
   - **Açıklama:** SharpDevelop ile seri haberleşme yapılarak hem saat hem de metin bilgisi LCD'de gösterilmiştir.
   - **Özellikler:**
     - Saat ve sıcaklık bilgisi LCD'nin ilk satırında gösterilir.
     - SharpDevelop üzerinden girilen metin LCD'nin ikinci satırında görüntülenir.
   - **Kullanılan Donanım:**
     - Tiva C Serisi LaunchPad
     - LM35DZ sıcaklık sensörü
     - 16x2 LCD ekran
   - [Detaylar için buraya tıklayın.](./Projects/Project%204)

---

## 🚀 Nasıl Kullanılır?

1. Her bir proje için ilgili klasöre giderek **README.md** dosyasını inceleyebilirsiniz.
2. Kodları indirmek ve çalıştırmak için:
   - Repo'yu klonlayın:
     ```bash
     https://github.com/murattks/Tiva-TM4C123GH6PM-Mikrodenetleyici-.git
     ```
   - İlgili proje klasörüne gidin ve kodları inceleyin.
3. Kodları derlemek ve Tiva C LaunchPad'e yüklemek için **Code Composer Studio** kullanın.

---
