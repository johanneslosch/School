using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace rechentrainer
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            getDoubleForForm(19);
        }

        private void btnnew_Click(object sender, EventArgs e)
        {
            if(isRadiobuttonChecked()){
                getDoubleForForm(getCheckedRadioButton());
            }
            else
            {
                MessageBox.Show("ZAHLENBEREICH AUSWÄHLEN!", "FEHLER", MessageBoxButtons.OK);
            }
        }

        private Boolean isRadiobuttonChecked()
        {
            if (radioButton1.Checked || radioButton2.Checked || radioButton3.Checked)
            {
                return true;
            }
            else
            {
                return false; 
            }
        }

        private void getDoubleForForm(int max)
        {
            lOne.Text = GetRandomNumber(max) + "";
            lTwo.Text = GetRandomNumber(max*max) + "";
        }

        public double GetRandomNumber(int max)
        {
            Random random = new Random();
            return (int)(random.Next(0, max)); //* 1000.0) / 100.0;
        }
        
        private int getCheckedRadioButton()
        {
            if (radioButton1.Checked)
            {
                return 9;
            }
            if (radioButton2.Checked)
            {
                return 19;
            }
            if (radioButton3.Checked)
            {
                return 49;
            }
            return 10000;
        }
    }
}
