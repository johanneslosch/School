using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Max3zahlen
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void btnBerechnen_Click(object sender, EventArgs e)
        {
            errechnen();
        }
        
        private void btnRepeat_Click(object sender, EventArgs e)
        {
            repeat();
        }

        private void errechnen()
        {
            double z1, z2, z3;
            z1 = Convert.ToDouble(txtZ1.Text);
            z2 = Convert.ToDouble(txtZ2.Text);
            z3 = Convert.ToDouble(txtZ3.Text);

            if (z1 < z2 && z2 < z3)
            {
                txtErgebnis.Text =  "Zahl 3";
            }
            else if (z1 < z2 && z3 < z2)
            {
                txtErgebnis.Text = "Zahl 2";
            }
            else
            {
                txtErgebnis.Text = "Zahl 1";
            }
        }

        private void repeat()
        {
            txtZ1.Clear();
            txtZ2.Clear();
            txtZ3.Clear();
            txtErgebnis.Clear();
        }

        

        

    }
}
