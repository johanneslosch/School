namespace Test3_Losch
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
            this.btnCalc = new System.Windows.Forms.Button();
            this.btnClose = new System.Windows.Forms.Button();
            this.btnReDo = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.rbP = new System.Windows.Forms.RadioButton();
            this.rbQ = new System.Windows.Forms.RadioButton();
            this.rbW = new System.Windows.Forms.RadioButton();
            this.lS1 = new System.Windows.Forms.Label();
            this.lS2 = new System.Windows.Forms.Label();
            this.lS3 = new System.Windows.Forms.Label();
            this.txtS1 = new System.Windows.Forms.TextBox();
            this.txtS2 = new System.Windows.Forms.TextBox();
            this.txtS3 = new System.Windows.Forms.TextBox();
            this.lErgeb = new System.Windows.Forms.Label();
            this.txtErgeb = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // btnCalc
            // 
            this.btnCalc.Location = new System.Drawing.Point(22, 201);
            this.btnCalc.Name = "btnCalc";
            this.btnCalc.Size = new System.Drawing.Size(75, 23);
            this.btnCalc.TabIndex = 0;
            this.btnCalc.Text = "Berechnen";
            this.btnCalc.UseVisualStyleBackColor = true;
            this.btnCalc.Click += new System.EventHandler(this.btnCalc_Click);
            // 
            // btnClose
            // 
            this.btnClose.Location = new System.Drawing.Point(103, 201);
            this.btnClose.Name = "btnClose";
            this.btnClose.Size = new System.Drawing.Size(75, 23);
            this.btnClose.TabIndex = 1;
            this.btnClose.Text = "Beenden";
            this.btnClose.UseVisualStyleBackColor = true;
            this.btnClose.Click += new System.EventHandler(this.btnClose_Click);
            // 
            // btnReDo
            // 
            this.btnReDo.Location = new System.Drawing.Point(184, 201);
            this.btnReDo.Name = "btnReDo";
            this.btnReDo.Size = new System.Drawing.Size(75, 23);
            this.btnReDo.TabIndex = 2;
            this.btnReDo.Text = "Wiederholen";
            this.btnReDo.UseVisualStyleBackColor = true;
            this.btnReDo.Click += new System.EventHandler(this.btnReDo_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.rbP);
            this.groupBox1.Controls.Add(this.rbQ);
            this.groupBox1.Controls.Add(this.rbW);
            this.groupBox1.Location = new System.Drawing.Point(12, 19);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(223, 51);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Körperauswahl";
            // 
            // rbP
            // 
            this.rbP.AutoSize = true;
            this.rbP.Location = new System.Drawing.Point(148, 19);
            this.rbP.Name = "rbP";
            this.rbP.Size = new System.Drawing.Size(68, 17);
            this.rbP.TabIndex = 2;
            this.rbP.TabStop = true;
            this.rbP.Text = "Pyramide";
            this.rbP.UseVisualStyleBackColor = true;
            this.rbP.CheckedChanged += new System.EventHandler(this.rbP_CheckedChanged);
            // 
            // rbQ
            // 
            this.rbQ.AutoSize = true;
            this.rbQ.Location = new System.Drawing.Point(82, 19);
            this.rbQ.Name = "rbQ";
            this.rbQ.Size = new System.Drawing.Size(60, 17);
            this.rbQ.TabIndex = 1;
            this.rbQ.TabStop = true;
            this.rbQ.Text = "Quader";
            this.rbQ.UseVisualStyleBackColor = true;
            this.rbQ.CheckedChanged += new System.EventHandler(this.rbQ_CheckedChanged);
            // 
            // rbW
            // 
            this.rbW.AutoSize = true;
            this.rbW.Location = new System.Drawing.Point(20, 19);
            this.rbW.Name = "rbW";
            this.rbW.Size = new System.Drawing.Size(56, 17);
            this.rbW.TabIndex = 0;
            this.rbW.TabStop = true;
            this.rbW.Text = "Würfel";
            this.rbW.UseVisualStyleBackColor = true;
            this.rbW.CheckedChanged += new System.EventHandler(this.rbW_CheckedChanged);
            // 
            // lS1
            // 
            this.lS1.AutoSize = true;
            this.lS1.Location = new System.Drawing.Point(33, 84);
            this.lS1.Name = "lS1";
            this.lS1.Size = new System.Drawing.Size(40, 13);
            this.lS1.TabIndex = 4;
            this.lS1.Text = "Seite 1";
            // 
            // lS2
            // 
            this.lS2.AutoSize = true;
            this.lS2.Location = new System.Drawing.Point(33, 106);
            this.lS2.Name = "lS2";
            this.lS2.Size = new System.Drawing.Size(40, 13);
            this.lS2.TabIndex = 5;
            this.lS2.Text = "Seite 2";
            // 
            // lS3
            // 
            this.lS3.AutoSize = true;
            this.lS3.Location = new System.Drawing.Point(33, 136);
            this.lS3.Name = "lS3";
            this.lS3.Size = new System.Drawing.Size(40, 13);
            this.lS3.TabIndex = 6;
            this.lS3.Text = "Seite 3";
            // 
            // txtS1
            // 
            this.txtS1.Location = new System.Drawing.Point(105, 76);
            this.txtS1.Name = "txtS1";
            this.txtS1.Size = new System.Drawing.Size(100, 20);
            this.txtS1.TabIndex = 7;
            // 
            // txtS2
            // 
            this.txtS2.Location = new System.Drawing.Point(105, 106);
            this.txtS2.Name = "txtS2";
            this.txtS2.Size = new System.Drawing.Size(100, 20);
            this.txtS2.TabIndex = 8;
            // 
            // txtS3
            // 
            this.txtS3.Location = new System.Drawing.Point(105, 133);
            this.txtS3.Name = "txtS3";
            this.txtS3.Size = new System.Drawing.Size(100, 20);
            this.txtS3.TabIndex = 9;
            // 
            // lErgeb
            // 
            this.lErgeb.AutoSize = true;
            this.lErgeb.Location = new System.Drawing.Point(30, 166);
            this.lErgeb.Name = "lErgeb";
            this.lErgeb.Size = new System.Drawing.Size(48, 13);
            this.lErgeb.TabIndex = 10;
            this.lErgeb.Text = "Ergebnis";
            // 
            // txtErgeb
            // 
            this.txtErgeb.Location = new System.Drawing.Point(105, 166);
            this.txtErgeb.Name = "txtErgeb";
            this.txtErgeb.Size = new System.Drawing.Size(100, 20);
            this.txtErgeb.TabIndex = 11;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(-3, 3);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(325, 13);
            this.label1.TabIndex = 12;
            this.label1.Text = "BITTE SOFORT DAS RICHTIGE AUSWÄHLEN; oder NEUSTART";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(211, 79);
            this.label2.Name = "label2";
            this.label2.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.label2.Size = new System.Drawing.Size(21, 13);
            this.label2.TabIndex = 13;
            this.label2.Text = "cm";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(210, 113);
            this.label3.Name = "label3";
            this.label3.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.label3.Size = new System.Drawing.Size(21, 13);
            this.label3.TabIndex = 14;
            this.label3.Text = "cm";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(211, 140);
            this.label4.Name = "label4";
            this.label4.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.label4.Size = new System.Drawing.Size(21, 13);
            this.label4.TabIndex = 15;
            this.label4.Text = "cm";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(210, 169);
            this.label5.Name = "label5";
            this.label5.RightToLeft = System.Windows.Forms.RightToLeft.Yes;
            this.label5.Size = new System.Drawing.Size(21, 13);
            this.label5.TabIndex = 16;
            this.label5.Text = "cm";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(319, 246);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.txtErgeb);
            this.Controls.Add(this.lErgeb);
            this.Controls.Add(this.txtS3);
            this.Controls.Add(this.txtS2);
            this.Controls.Add(this.txtS1);
            this.Controls.Add(this.lS3);
            this.Controls.Add(this.lS2);
            this.Controls.Add(this.lS1);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.btnReDo);
            this.Controls.Add(this.btnClose);
            this.Controls.Add(this.btnCalc);
            this.Name = "Form1";
            this.Text = "Volumenberechnung";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btnCalc;
        private System.Windows.Forms.Button btnClose;
        private System.Windows.Forms.Button btnReDo;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton rbP;
        private System.Windows.Forms.RadioButton rbQ;
        private System.Windows.Forms.RadioButton rbW;
        private System.Windows.Forms.Label lS1;
        private System.Windows.Forms.Label lS2;
        private System.Windows.Forms.Label lS3;
        private System.Windows.Forms.TextBox txtS1;
        private System.Windows.Forms.TextBox txtS2;
        private System.Windows.Forms.TextBox txtS3;
        private System.Windows.Forms.Label lErgeb;
        private System.Windows.Forms.TextBox txtErgeb;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
    }
}

