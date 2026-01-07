# Project 4: Serial Port and GUI Communication (UART)

**[🇺🇸 English](#description)** | **[🇹🇷 Türkçe](#proje-4-seri-port-ve-gui-haberleşmesi)**

---

## 📖 Description

This project demonstrates two-way serial communication (UART) between the **Tiva C Series TM4C123G LaunchPad** and a PC interface (GUI) developed using **SharpDevelop (C#)**. 

The system allows the user to control the microcontroller functionalities via buttons on the computer screen and receive sensor/status data from the microcontroller back to the PC interface.

## 🛠 Functionality & GUI Features

Based on the interface design, the project performs the following tasks:

1.  **Sync Clock:** Sends time data from PC to Tiva C to start the internal timer.
2.  **Write Text:** Sends a text string from the PC to be displayed on the LCD screen connected to the Tiva C.
3.  **ADC Data:** Requests analog data from the potentiometer connected to the Tiva C; the value is sent back and displayed on the GUI.
4.  **Button Status:** Checks the status of the onboard switches (SW1/SW2) on the LaunchPad.

##⚙️ Hardware Connections

To use all features of the GUI (ADC reading, Text writing, etc.), connect the hardware as follows:

### 1. UART Connection (USB / Serial)
Communication is handled via the LaunchPad's USB Debug port (Virtual COM Port).

| Function | Tiva C Pin | Connected to |
| :--- | :--- | :--- |
| **UART0 RX** | PA0 | PC Transmit (via USB) |
| **UART0 TX** | PA1 | PC Receive (via USB) |

### 2. LCD Connections (Port B)
Required for the "Write Text" and "Clock Display" features.

| LCD Pin | TM4C123G Pin | Function |
| :--- | :--- | :--- |
| **VSS** | GND | Ground |
| **VDD** | VBUS (5V) | Power Supply |
| **V0** | Potentiometer | Contrast Adjustment |
| **RS** | PB0 | Register Select |
| **RW** | GND | Read/Write (Write Mode) |
| **E** | PB1 | Enable Signal |
| **D4** | PB4 | Data Bit 4 |
| **D5** | PB5 | Data Bit 5 |
| **D6** | PB6 | Data Bit 6 |
| **D7** | PB7 | Data Bit 7 |
| **A** | +5V (or 3.3V) | Backlight Anode |
| **K** | GND | Backlight Cathode |

> **Note:** **PB7** is a locked pin (NMI). The code includes an unlocking sequence to use it.

### 3. ADC / Potentiometer Connection (Port E)
Required for the "ADC Data" feature.

| Component | TM4C123G Pin | Function |
| :--- | :--- | :--- |
| **Potentiometer (Middle)** | PE3 | Analog Input (AIN0) |
| **Potentiometer (Left)** | 3.3V | VCC |
| **Potentiometer (Right)** | GND | Ground |

### 4. Onboard Buttons (Port F)
Required for the "Button Status" feature.

| Component | Tiva C Pin | Note |
| :--- | :--- | :--- |
| **SW1 (Left Button)** | PF4 | Internal Pull-up |
| **SW2 (Right Button)** | PF0 | Internal Pull-up (Locked Pin) |

---

## 💻 Software Requirements

* **Embedded:** Code Composer Studio (CCS) or Keil uVision
* **GUI:** SharpDevelop (C# Windows Forms Application)
* **Library:** TivaWare Peripheral Driver Library

## 🚀 How to Run

1.  **Setup:** Connect the LCD and Potentiometer to the board as shown in the tables.
2.  **Flash:** Upload the C code to the Tiva C LaunchPad.
3.  **Run GUI:** Open the SharpDevelop project, compile, and run.
4.  **Connect:** Ensure the board is plugged in via USB and click buttons on the interface.

---

<br>

# Proje 4: Seri Port ve GUI Haberleşmesi

## 📖 Açıklama

Bu proje, **Tiva C Serisi TM4C123G LaunchPad** ile **SharpDevelop (C#)** kullanılarak geliştirilmiş bir bilgisayar arayüzü (GUI) arasında iki yönlü seri haberleşmeyi (UART) gösterir.

Sistem, kullanıcının bilgisayar ekranındaki butonlar aracılığıyla mikrodenetleyiciyi kontrol etmesini ve mikrodenetleyiciden gelen sensör/durum verilerini arayüzde görmesini sağlar.

## 🛠 İşlevsellik ve Arayüz Özellikleri

Arayüz tasarımına dayanarak proje aşağıdaki görevleri yerine getirir:

1.  **Saati Senkronize Et:** Bilgisayardan Tiva C'ye zaman verisi gönderir ve sayacı başlatır.
2.  **Metni Yaz:** Arayüzden gönderilen metni, Tiva C'ye bağlı LCD ekrana yazdırır.
3.  **ADC Verisi:** Potansiyometreden okunan analog değeri ister ve arayüzde gösterir.
4.  **Buton Durumu:** Kart üzerindeki butonların (SW1/SW2) basılı olup olmadığını kontrol eder.

## ⚙️ Donanım Bağlantıları

Arayüzdeki tüm özellikleri (ADC okuma, Metin yazma vb.) kullanabilmek için aşağıdaki bağlantıları yapınız:

### 1. UART Bağlantısı (USB / Seri)
Haberleşme, LaunchPad'in kendi USB portu (Sanal COM Port) üzerinden sağlanır.

| Fonksiyon | Tiva C Pini | Bağlantı Yeri |
| :--- | :--- | :--- |
| **UART0 RX** | PA0 | PC Gönderim Hattı (USB üzerinden) |
| **UART0 TX** | PA1 | PC Alım Hattı (USB üzerinden) |

### 2. LCD Bağlantıları (Port B)
"Metni Yaz" ve "Saat Göstergesi" özellikleri için gereklidir.

| LCD Pini | TM4C123G Pini | Görevi |
| :--- | :--- | :--- |
| **VSS** | GND | Toprak |
| **VDD** | VBUS (5V) | Güç Beslemesi |
| **V0** | Potansiyometre | Kontrast Ayarı |
| **RS** | PB0 | Register Seçimi |
| **RW** | GND | Yazma Modu |
| **E** | PB1 | Enable Sinyali |
| **D4** | PB4 | Veri Biti 4 |
| **D5** | PB5 | Veri Biti 5 |
| **D6** | PB6 | Veri Biti 6 |
| **D7** | PB7 | Veri Biti 7 |
| **A** | +5V (veya 3.3V) | Arka Işık (+) |
| **K** | GND | Arka Işık (-) |

> **Not:** **PB7** kilitli bir pindir (NMI). Kod içerisinde bu pini kullanmak için kilit açma komutları mevcuttur.

### 3. ADC / Potansiyometre Bağlantısı (Port E)
"ADC Verisi" özelliği için gereklidir.

| Bileşen | TM4C123G Pini | Görevi |
| :--- | :--- | :--- |
| **Potansiyometre (Orta)** | PE3 | Analog Giriş (AIN0) |
| **Potansiyometre (Sol)** | 3.3V | VCC |
| **Potansiyometre (Sağ)** | GND | Toprak |

### 4. Dahili Butonlar (Port F)
"Buton Durumu" özelliği için gereklidir.

| Bileşen | Tiva C Pini | Not |
| :--- | :--- | :--- |
| **SW1 (Sol Buton)** | PF4 | Dahili Pull-up |
| **SW2 (Sağ Buton)** | PF0 | Dahili Pull-up (Kilitli Pin) |

---

## 💻 Yazılım Gereksinimleri

* **Gömülü:** Code Composer Studio (CCS) veya Keil uVision
* **Arayüz:** SharpDevelop (C# Windows Forms Uygulaması)
* **Kütüphane:** TivaWare Peripheral Driver Library

## 🚀 Nasıl Çalıştırılır?

1.  **Kurulum:** LCD ve Potansiyometreyi tablodaki gibi karta bağlayın.
2.  **Yükleme:** C kodunu derleyin ve Tiva C kartına yükleyin.
3.  **Arayüz:** SharpDevelop projesini açın, derleyin ve çalıştırın (Run).
4.  **Bağlantı:** Kartın USB ile bağlı olduğundan emin olun ve arayüzdeki butonları test edin.

---
**Author / Yazar:** Muratali KUŞ G210100041  
**Department:** Electrical and Electronics Engineering, Sakarya University