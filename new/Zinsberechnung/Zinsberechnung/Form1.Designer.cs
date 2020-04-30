namespace Zinsberechnung
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.txtKapital = new System.Windows.Forms.TextBox();
            this.txtAiD = new System.Windows.Forms.TextBox();
            this.txtZinsen = new System.Windows.Forms.TextBox();
            this.txtZinssatz = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(100, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(84, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Zinsberechnugn";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(36, 67);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(39, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Kapital";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(36, 97);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(46, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Zinssatz";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(36, 128);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(112, 13);
            this.label4.TabIndex = 3;
            this.label4.Text = "Anlagedauer in Tagen";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(36, 168);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(39, 13);
            this.label5.TabIndex = 4;
            this.label5.Text = "Zinsen";
            // 
            // txtKapital
            // 
            this.txtKapital.Location = new System.Drawing.Point(180, 67);
            this.txtKapital.Name = "txtKapital";
            this.txtKapital.Size = new System.Drawing.Size(100, 20);
            this.txtKapital.TabIndex = 5;
            // 
            // txtAiD
            // 
            this.txtAiD.Location = new System.Drawing.Point(180, 128);
            this.txtAiD.Name = "txtAiD";
            this.txtAiD.Size = new System.Drawing.Size(100, 20);
            this.txtAiD.TabIndex = 6;
            // 
            // txtZinsen
            // 
            this.txtZinsen.Location = new System.Drawing.Point(180, 165);
            this.txtZinsen.Name = "txtZinsen";
            this.txtZinsen.Size = new System.Drawing.Size(100, 20);
            this.txtZinsen.TabIndex = 7;
            // 
            // txtZinssatz
            // 
            this.txtZinssatz.Location = new System.Drawing.Point(180, 102);
            this.txtZinssatz.Name = "txtZinssatz";
            this.txtZinssatz.Size = new System.Drawing.Size(100, 20);
            this.txtZinssatz.TabIndex = 8;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(109, 213);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 9;
            this.button1.Text = "Berechnen";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(334, 261);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.txtZinssatz);
            this.Controls.Add(this.txtZinsen);
            this.Controls.Add(this.txtAiD);
            this.Controls.Add(this.txtKapital);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox txtKapital;
        private System.Windows.Forms.TextBox txtAiD;
        private System.Windows.Forms.TextBox txtZinsen;
        private System.Windows.Forms.TextBox txtZinssatz;
        private System.Windows.Forms.Button button1;
    }
}

