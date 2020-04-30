namespace WindowsFormsApplication4
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
            this.button1 = new System.Windows.Forms.Button();
            this.txtBmi = new System.Windows.Forms.Label();
            this.tBKG = new System.Windows.Forms.TextBox();
            this.tBM = new System.Windows.Forms.TextBox();
            this.txtMsg = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(13, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(75, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Gewicht in KG";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(13, 58);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(77, 13);
            this.label2.TabIndex = 1;
            this.label2.Text = "Größe in Meter";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(63, 101);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 2;
            this.button1.Text = "BMI Berechnen";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // txtBmi
            // 
            this.txtBmi.AutoSize = true;
            this.txtBmi.Location = new System.Drawing.Point(60, 162);
            this.txtBmi.Name = "txtBmi";
            this.txtBmi.Size = new System.Drawing.Size(31, 13);
            this.txtBmi.TabIndex = 3;
            this.txtBmi.Text = "____";
            // 
            // tBKG
            // 
            this.tBKG.Location = new System.Drawing.Point(95, 13);
            this.tBKG.Name = "tBKG";
            this.tBKG.Size = new System.Drawing.Size(100, 20);
            this.tBKG.TabIndex = 4;
            // 
            // tBM
            // 
            this.tBM.Location = new System.Drawing.Point(93, 51);
            this.tBM.Name = "tBM";
            this.tBM.Size = new System.Drawing.Size(100, 20);
            this.tBM.TabIndex = 5;
            // 
            // txtMsg
            // 
            this.txtMsg.AutoSize = true;
            this.txtMsg.Location = new System.Drawing.Point(57, 195);
            this.txtMsg.Name = "txtMsg";
            this.txtMsg.Size = new System.Drawing.Size(31, 13);
            this.txtMsg.TabIndex = 6;
            this.txtMsg.Text = "____";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(239, 238);
            this.Controls.Add(this.txtMsg);
            this.Controls.Add(this.tBM);
            this.Controls.Add(this.tBKG);
            this.Controls.Add(this.txtBmi);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Form1";
            this.Text = "BMI";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label txtBmi;
        private System.Windows.Forms.TextBox tBKG;
        private System.Windows.Forms.TextBox tBM;
        private System.Windows.Forms.Label txtMsg;
    }
}

