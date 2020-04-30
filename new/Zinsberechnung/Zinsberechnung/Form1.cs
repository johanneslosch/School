using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Zinsberechnung
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
        //System.Windows.Forms.TextBox, Text: 
        private void button1_Click(object sender, EventArgs e)
        {
            double kapital, zinssatz, zinsen;
            int days;
            kapital = Convert.ToDouble(txtKapital.Text);
            zinssatz = Convert.ToDouble(txtZinssatz.Text);
            days = Convert.ToInt16(txtAiD.Text);
            zinsen = kapital * days * zinssatz / (100*360);
            txtZinsen.Text = Convert.ToString(txtZinsen);
        }
    }
}
