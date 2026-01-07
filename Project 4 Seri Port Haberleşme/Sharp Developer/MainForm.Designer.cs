/*
 * Created by SharpDevelop.
 * User: kubil
 * Date: 21.12.2025
 * Time: 19:30
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
namespace Tivason
{
	partial class MainForm
	{
		/// <summary>
		/// Designer variable used to keep track of non-visual components.
		/// </summary>
		private System.ComponentModel.IContainer components = null;
		
		/// <summary>
		/// Disposes resources used by the form.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing) {
				if (components != null) {
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}
		
		/// <summary>
		/// This method is required for Windows Forms designer support.
		/// Do not change the method contents inside the source code editor. The Forms designer might
		/// not be able to load this method if it was changed manually.
		/// </summary>
		private void InitializeComponent()
		{
			this.txtGonderSaat = new System.Windows.Forms.TextBox();
			this.btnSaatGonder = new System.Windows.Forms.Button();
			this.txtGonderMetin = new System.Windows.Forms.TextBox();
			this.btnMetinGonder = new System.Windows.Forms.Button();
			this.textBoxSaat = new System.Windows.Forms.TextBox();
			this.textBoxADC = new System.Windows.Forms.TextBox();
			this.textBoxButon = new System.Windows.Forms.TextBox();
			this.textBox1 = new System.Windows.Forms.TextBox();
			this.textBox2 = new System.Windows.Forms.TextBox();
			this.textBox3 = new System.Windows.Forms.TextBox();
			this.SuspendLayout();
			// 
			// txtGonderSaat
			// 
			this.txtGonderSaat.Location = new System.Drawing.Point(49, 13);
			this.txtGonderSaat.Multiline = true;
			this.txtGonderSaat.Name = "txtGonderSaat";
			this.txtGonderSaat.Size = new System.Drawing.Size(160, 52);
			this.txtGonderSaat.TabIndex = 0;
			// 
			// btnSaatGonder
			// 
			this.btnSaatGonder.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btnSaatGonder.Location = new System.Drawing.Point(260, 12);
			this.btnSaatGonder.Name = "btnSaatGonder";
			this.btnSaatGonder.Size = new System.Drawing.Size(274, 53);
			this.btnSaatGonder.TabIndex = 1;
			this.btnSaatGonder.Text = "Saati Senkronize Et";
			this.btnSaatGonder.UseVisualStyleBackColor = true;
			this.btnSaatGonder.Click += new System.EventHandler(this.BtnSaatGonderClick);
			// 
			// txtGonderMetin
			// 
			this.txtGonderMetin.Location = new System.Drawing.Point(49, 93);
			this.txtGonderMetin.MaxLength = 32500;
			this.txtGonderMetin.Multiline = true;
			this.txtGonderMetin.Name = "txtGonderMetin";
			this.txtGonderMetin.Size = new System.Drawing.Size(160, 53);
			this.txtGonderMetin.TabIndex = 2;
			this.txtGonderMetin.TextChanged += new System.EventHandler(this.TxtGonderMetinTextChanged);
			// 
			// btnMetinGonder
			// 
			this.btnMetinGonder.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btnMetinGonder.Location = new System.Drawing.Point(260, 93);
			this.btnMetinGonder.Name = "btnMetinGonder";
			this.btnMetinGonder.Size = new System.Drawing.Size(274, 53);
			this.btnMetinGonder.TabIndex = 3;
			this.btnMetinGonder.Text = "Metni Yaz";
			this.btnMetinGonder.UseVisualStyleBackColor = true;
			this.btnMetinGonder.Click += new System.EventHandler(this.BtnMetinGonderClick);
			// 
			// textBoxSaat
			// 
			this.textBoxSaat.Location = new System.Drawing.Point(49, 179);
			this.textBoxSaat.Multiline = true;
			this.textBoxSaat.Name = "textBoxSaat";
			this.textBoxSaat.Size = new System.Drawing.Size(160, 53);
			this.textBoxSaat.TabIndex = 4;
			// 
			// textBoxADC
			// 
			this.textBoxADC.Location = new System.Drawing.Point(49, 280);
			this.textBoxADC.Multiline = true;
			this.textBoxADC.Name = "textBoxADC";
			this.textBoxADC.Size = new System.Drawing.Size(160, 53);
			this.textBoxADC.TabIndex = 5;
			// 
			// textBoxButon
			// 
			this.textBoxButon.Location = new System.Drawing.Point(49, 376);
			this.textBoxButon.Multiline = true;
			this.textBoxButon.Name = "textBoxButon";
			this.textBoxButon.Size = new System.Drawing.Size(160, 53);
			this.textBoxButon.TabIndex = 6;
			// 
			// textBox1
			// 
			this.textBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.textBox1.Location = new System.Drawing.Point(260, 376);
			this.textBox1.Multiline = true;
			this.textBox1.Name = "textBox1";
			this.textBox1.Size = new System.Drawing.Size(274, 53);
			this.textBox1.TabIndex = 7;
			this.textBox1.Text = "Buton Durumu";
			this.textBox1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
			this.textBox1.TextChanged += new System.EventHandler(this.TextBox1TextChanged);
			// 
			// textBox2
			// 
			this.textBox2.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.textBox2.Location = new System.Drawing.Point(260, 280);
			this.textBox2.Multiline = true;
			this.textBox2.Name = "textBox2";
			this.textBox2.Size = new System.Drawing.Size(274, 53);
			this.textBox2.TabIndex = 8;
			this.textBox2.Text = "Saat Göstergesi";
			this.textBox2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
			// 
			// textBox3
			// 
			this.textBox3.Font = new System.Drawing.Font("Microsoft Sans Serif", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.textBox3.Location = new System.Drawing.Point(260, 179);
			this.textBox3.Multiline = true;
			this.textBox3.Name = "textBox3";
			this.textBox3.Size = new System.Drawing.Size(274, 53);
			this.textBox3.TabIndex = 9;
			this.textBox3.Text = "ADC VERİSİ";
			this.textBox3.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(578, 472);
			this.Controls.Add(this.textBox3);
			this.Controls.Add(this.textBox2);
			this.Controls.Add(this.textBox1);
			this.Controls.Add(this.textBoxButon);
			this.Controls.Add(this.textBoxADC);
			this.Controls.Add(this.textBoxSaat);
			this.Controls.Add(this.btnMetinGonder);
			this.Controls.Add(this.txtGonderMetin);
			this.Controls.Add(this.btnSaatGonder);
			this.Controls.Add(this.txtGonderSaat);
			this.Name = "MainForm";
			this.Text = "Tivason";
			this.ResumeLayout(false);
			this.PerformLayout();

		}
		private System.Windows.Forms.TextBox textBoxButon;
		private System.Windows.Forms.TextBox textBoxADC;
		private System.Windows.Forms.TextBox textBoxSaat;
		private System.Windows.Forms.Button btnMetinGonder;
		private System.Windows.Forms.TextBox txtGonderMetin;
		private System.Windows.Forms.Button btnSaatGonder;
		private System.Windows.Forms.TextBox txtGonderSaat;
		private System.Windows.Forms.TextBox textBox1;
		private System.Windows.Forms.TextBox textBox2;
		private System.Windows.Forms.TextBox textBox3;
	}
}
