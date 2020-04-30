using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            txtBmi.Visible = false;
            txtMsg.Visible = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            setText();
        }

        private double getBMI(double kg, double m)
        {
            return kg / (m * m);
        }

        private void setText()
        {
            double bmi = getBMI(Convert.ToDouble(tBKG.Text), Convert.ToDouble(tBM.Text));
            txtBmi.Text = Convert.ToString(bmi);
            if (bmi > 25.0)
            {
                txtMsg.Text = "ZU DICK";
            }
            else if (bmi < 20.0)
            {
                txtMsg.Text = "ZU DÜNN";
            }
            else
            {
                txtMsg.Text = "JOAR";
            }
            txtBmi.Visible = true;
            txtMsg.Visible = true;
        }
    }
}
