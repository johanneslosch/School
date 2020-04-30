namespace WindowsFormsApplication2
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
            this.addOne = new System.Windows.Forms.Button();
            this.remOne = new System.Windows.Forms.Button();
            this.txtint = new System.Windows.Forms.TextBox();
            this.btnExIt = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // addOne
            // 
            this.addOne.Location = new System.Drawing.Point(30, 58);
            this.addOne.Name = "addOne";
            this.addOne.Size = new System.Drawing.Size(114, 23);
            this.addOne.TabIndex = 0;
            this.addOne.Text = "+ 1";
            this.addOne.UseVisualStyleBackColor = true;
            this.addOne.Click += new System.EventHandler(this.addOne_Click);
            // 
            // remOne
            // 
            this.remOne.Location = new System.Drawing.Point(30, 87);
            this.remOne.Name = "remOne";
            this.remOne.Size = new System.Drawing.Size(114, 23);
            this.remOne.TabIndex = 1;
            this.remOne.Text = "- 1";
            this.remOne.UseVisualStyleBackColor = true;
            this.remOne.Click += new System.EventHandler(this.remOne_Click);
            // 
            // txtint
            // 
            this.txtint.Location = new System.Drawing.Point(30, 32);
            this.txtint.Name = "txtint";
            this.txtint.Size = new System.Drawing.Size(114, 20);
            this.txtint.TabIndex = 2;
            // 
            // btnExIt
            // 
            this.btnExIt.Location = new System.Drawing.Point(30, 116);
            this.btnExIt.Name = "btnExIt";
            this.btnExIt.Size = new System.Drawing.Size(114, 205);
            this.btnExIt.TabIndex = 3;
            this.btnExIt.Text = "EXIT";
            this.btnExIt.UseVisualStyleBackColor = true;
            this.btnExIt.Click += new System.EventHandler(this.btnExIt_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(185, 348);
            this.Controls.Add(this.btnExIt);
            this.Controls.Add(this.txtint);
            this.Controls.Add(this.remOne);
            this.Controls.Add(this.addOne);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button addOne;
        private System.Windows.Forms.Button remOne;
        private System.Windows.Forms.TextBox txtint;
        private System.Windows.Forms.Button btnExIt;
    }
}

