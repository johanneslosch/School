using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace WindowsFormsApplication3
{
    public partial class Form1 : Form
    {
        
        public Form1()
        {
            InitializeComponent();
            txtKind.Visible = false;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int one = Convert.ToInt16(txt1.Text);
            int two = Convert.ToInt16(txt2.Text);

            if (txtKind.Text == "__")
            {
                MessageBox.Show("RECHENZEICHEN DRÜCKEN!", "FEHLER!", MessageBoxButtons.OK);
            }
            else
            {
                
                if (txtKind.Text == "+")
                {
                    textBox3.Text = Convert.ToString(one + two);
                }
                else if (txtKind.Text == "-")
                {
                    textBox3.Text = Convert.ToString(one - two);
                }
                else if (txtKind.Text == "*")
                {
                    textBox3.Text = Convert.ToString(one * two);
                }
                else
                {
                    if (Handler.thoughZero(one, two))
                    {
                        textBox3.Text = Convert.ToString(one / two);
                    }
                    else
                    {
                        if (one == null || two == null)
                        {
                            txt2.BackColor = Color.Red;
                        }

                        MessageBox.Show("Zahl 2 darf nicht 0 sein", "Fehler", MessageBoxButtons.OK);
                    }
                }
            }

            /*
            if (rdAd.Checked)
            {
                textBox3.Text = Convert.ToString(one + two);
            }
            else if (rdSub.Checked)
            {
                textBox3.Text = Convert.ToString(one - two);
            }
            else if (rdMult.Checked)
            {
                textBox3.Text = Convert.ToString(one*two);
            }
            else if (rdDiv.Checked)
            {
                textBox3.Text = Convert.ToString(one / two);
            }
             */
        }
        //Adition
        private void button3_Click(object sender, EventArgs e)
        {
            txtKind.Text = "+";
            txtKind.Visible = true;
        }
        //-
        private void button5_Click(object sender, EventArgs e)
        {
            txtKind.Text = "-"; 
            txtKind.Visible = true;
        }

        //*
        private void button4_Click(object sender, EventArgs e)
        {
            txtKind.Text = "*"; 
            txtKind.Visible = true;
        }
        // /
        private void button6_Click(object sender, EventArgs e)
        {
            txtKind.Text = "/"; 
            txtKind.Visible = true;
        }
    }
}
