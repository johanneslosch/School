namespace Max3zahlen
{
    partial class Form1
    {
        /// <summary>
        /// Erforderliche Designervariable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Verwendete Ressourcen bereinigen.
        /// </summary>
        /// <param name="disposing">True, wenn verwaltete Ressourcen gelöscht werden sollen; andernfalls False.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Vom Windows Form-Designer generierter Code

        /// <summary>
        /// Erforderliche Methode für die Designerunterstützung.
        /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
        /// </summary>
        private void InitializeComponent()
        {
            this.txtZ1 = new System.Windows.Forms.TextBox();
            this.txtZ2 = new System.Windows.Forms.TextBox();
            this.txtZ3 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.btnBerechnen = new System.Windows.Forms.Button();
            this.btnRepeat = new System.Windows.Forms.Button();
            this.btnClose = new System.Windows.Forms.Button();
            this.label4 = new System.Windows.Forms.Label();
            this.txtErgebnis = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // txtZ1
            // 
            this.txtZ1.Location = new System.Drawing.Point(123, 28);
            this.txtZ1.Name = "txtZ1";
            this.txtZ1.Size = new System.Drawing.Size(100, 20);
            this.txtZ1.TabIndex = 0;
            // 
            // txtZ2
            // 
            this.txtZ2.Location = new System.Drawing.Point(123, 71);
            this.txtZ2.Name = "txtZ2";
            this.txtZ2.Size = new System.Drawing.Size(100, 20);
            this.txtZ2.TabIndex = 1;
            // 
            // txtZ3
            // 
            this.txtZ3.Location = new System.Drawing.Point(123, 107);
            this.txtZ3.Name = "txtZ3";
            this.txtZ3.Size = new System.Drawing.Size(100, 20);
            this.txtZ3.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 34);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(37, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "Zahl 1";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(13, 77);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(37, 13);
            this.label2.TabIndex = 4;
            this.label2.Text = "Zahl 2";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(13, 113);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(37, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Zahl 3";
            
            // 
            // btnBerechnen
            // 
            this.btnBerechnen.Location = new System.Drawing.Point(16, 223);
            this.btnBerechnen.Name = "btnBerechnen";
            this.btnBerechnen.Size = new System.Drawing.Size(75, 23);
            this.btnBerechnen.TabIndex = 6;
            this.btnBerechnen.Text = "Berechnen";
            this.btnBerechnen.UseVisualStyleBackColor = true;
            this.btnBerechnen.Click += new System.EventHandler(this.btnBerechnen_Click);
            // 
            // btnRepeat
            // 
            this.btnRepeat.Location = new System.Drawing.Point(97, 223);
            this.btnRepeat.Name = "btnRepeat";
            this.btnRepeat.Size = new System.Drawing.Size(75, 23);
            this.btnRepeat.TabIndex = 7;
            this.btnRepeat.Text = "Nochmal";
            this.btnRepeat.UseVisualStyleBackColor = true;
            this.btnRepeat.Click += new System.EventHandler(this.btnRepeat_Click);
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(178, 223);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(75, 23);
            this.btnClose.TabIndex = 8;
            this.btnClose.Text = "Beenden";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(13, 154);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(48, 13);
            this.label4.TabIndex = 10;
            this.label4.Text = "Ergebnis";
            // 
            // txtErgebnis
            // 
            this.txtErgebnis.Location = new System.Drawing.Point(123, 148);
            this.txtErgebnis.Name = "txtErgebnis";
            this.txtErgebnis.Size = new System.Drawing.Size(100, 20);
            this.txtErgebnis.TabIndex = 9;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(272, 346);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.txtErgebnis);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.btnRepeat);
            this.Controls.Add(this.btnBerechnen);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txtZ3);
            this.Controls.Add(this.txtZ2);
            this.Controls.Add(this.txtZ1);
            this.Name = "Form1";
            this.Text = "Maximum von 3 Zahlen";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtZ1;
        private System.Windows.Forms.TextBox txtZ2;
        private System.Windows.Forms.TextBox txtZ3;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button btnBerechnen;
        private System.Windows.Forms.Button btnRepeat;
        private System.Windows.Forms.Button btnClose;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtErgebnis;
    }
}

