using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using System.IO.Ports;

namespace Tivason // Proje isminle aynı olduğundan emin ol!
{
    public partial class MainForm : Form
    {
        SerialPort serialPort1 = new SerialPort();

        public MainForm()
        {
            InitializeComponent();
            CheckForIllegalCrossThreadCalls = false; 

            try 
            {
                if(serialPort1.IsOpen) serialPort1.Close();
                serialPort1.PortName = "COM3"; // Portu Kontrol Et
                serialPort1.BaudRate = 9600;
                serialPort1.DataReceived += new SerialDataReceivedEventHandler(VeriGeldi);
                serialPort1.Open();
            }
            catch(Exception ex) { MessageBox.Show("Port Hatası: " + ex.Message); }
        }

        // --- GÖREV 1: PC SAATİNİ GÖNDERME (SENKRONİZASYON) ---
        // Bu butona basınca PC'nin o anki gerçek saati gider.
        void BtnSaatGonderClick(object sender, EventArgs e)
        {
            if(serialPort1.IsOpen) 
            {
                // Bilgisayarın anlık saatini al (HH:mm:ss formatında)
                // Örnek: "14:53:20"
                string pcSaati = DateTime.Now.ToString("HH:mm:ss");
                
                // Ekranda kullanıcı ne gönderildiğini görsün (Opsiyonel)
                txtGonderSaat.Text = pcSaati; 
                
                // Tiva'ya gönder (*S14:53:20#)
                string paket = "*S" + pcSaati + "#";
                serialPort1.Write(paket);
            }
        }

        // --- GÖREV 1 (Devam): METİN GÖNDERME ---
        void BtnMetinGonderClick(object sender, EventArgs e)
        {
            if(serialPort1.IsOpen) 
            {
                string metin = txtGonderMetin.Text;
                if(metin.Length > 3) metin = metin.Substring(0,3); // Max 3 harf
                string paket = "*M" + metin + "#";
                serialPort1.Write(paket);
            }
        }

        // --- GÖREV 2: TIVA'DAN GELEN RAPORU OKUMA ---
        void VeriGeldi(object sender, SerialDataReceivedEventArgs e)
        {
            try
            {
                // Gelen: *12:30:00,4095,1#
                string gelen = serialPort1.ReadLine(); 
                
                int bas = gelen.IndexOf('*');
                int son = gelen.IndexOf('#');

                if (bas != -1 && son != -1 && son > bas)
                {
                    string temiz = gelen.Substring(bas + 1, son - bas - 1);
                    string[] parcalar = temiz.Split(',');

                    if (parcalar.Length == 3)
                    {
                        // Gelen verileri kutulara yaz
                        textBoxSaat.Text = parcalar[0];
                        textBoxADC.Text = parcalar[1];

                        // Buton Kontrolü
                        if (parcalar[2] == "1")
                        {
                            textBoxButon.Text = "BASILDI";
                            textBoxButon.BackColor = Color.Red;
                            textBoxButon.ForeColor = Color.White;
                        }
                        else
                        {
                            textBoxButon.Text = "Beklemede";
                            textBoxButon.BackColor = Color.White;
                            textBoxButon.ForeColor = Color.Black;
                        }
                    }
                }
            }
            catch {}
        }
        
        protected override void OnFormClosing(FormClosingEventArgs e)
        {
            if(serialPort1.IsOpen) serialPort1.Close();
            base.OnFormClosing(e);
        }
		void TxtGonderMetinTextChanged(object sender, EventArgs e)
		{
	
		}
		void TextBox1TextChanged(object sender, EventArgs e)
		{
	
		}
    }
}