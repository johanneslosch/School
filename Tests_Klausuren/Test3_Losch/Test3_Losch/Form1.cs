using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Test3_Losch
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            lErgeb.Visible = false;
            txtErgeb.Visible = false;
            txtS1.Visible = false;
            txtS2.Visible = false;
            txtS3.Visible = false;
          
            lS1.Visible = false;
            lS2.Visible = false;
            lS3.Visible = false;
            label2.Visible = false;
            label3.Visible = false;
            label4.Visible = false;
            label5.Visible = false;
        }

        private void checkRB()
        {
            if (rbP.Checked)
            {
                pyramid();
                txtErgeb.Visible = true;
                lErgeb.Visible = true;
                label5.Visible = true;
            }
            else if (rbQ.Checked)
            {
                quad();
                txtErgeb.Visible = true;
                lErgeb.Visible = true;
                label5.Visible = true;
            }
            else
            {
                wuerfel();
                txtErgeb.Visible = true;
                lErgeb.Visible = true;
                label5.Visible = true;
            }
        }

        private void pyramid()
        {

            txtErgeb.Text = Convert.ToString(((1/3) * (Convert.ToDouble(txtS1.Text) * Convert.ToDouble(txtS1.Text))) * Convert.ToDouble(txtS2.Text));
        }

        private void quad()
        {
            txtErgeb.Text = Convert.ToString(Convert.ToDouble(txtS1.Text) * Convert.ToDouble(txtS2.Text) * Convert.ToDouble(txtS3.Text));
        }

        private void wuerfel()
        {
            txtErgeb.Text = Convert.ToString(Convert.ToDouble(txtS1.Text) * Convert.ToDouble(txtS1.Text) * Convert.ToDouble(txtS1.Text));
        }

        private void btnCalc_Click(object sender, EventArgs e)
        {
                if (txtS1.TextLength > 0)
                {
                    checkRB();
                }
                else
                {
                    MessageBox.Show("Bitte geben Sie Werte ein!", "FEHLER!", MessageBoxButtons.OK);
                }
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            Close();
        }

        private void btnReDo_Click(object sender, EventArgs e)
        {
            txtErgeb.Text = null;
            txtS1.Text = null;
            txtS2.Text = null;
            txtS3.Text = null;

            lErgeb.Visible = false;
            txtErgeb.Visible = false;
            txtS1.Visible = false;
            txtS2.Visible = false;
            txtS3.Visible = false;

            lS1.Visible = false;
            lS2.Visible = false;
            lS3.Visible = false;
            label2.Visible = false;
            label3.Visible = false;
            label4.Visible = false;
            label5.Visible = false;
        }

        private void rbW_CheckedChanged(object sender, EventArgs e)
        {
            if (lS1.Visible == false)
            {
                lS1.Visible = true;
                txtS1.Visible = true;
                label2.Visible = true;
            }
            if (lS2.Visible == true)
            {
                txtS2.Visible = false;
                txtS3.Visible = false;

                lS2.Visible = false;
                lS3.Visible = false;
            }

            if (rbW.Checked == false)
            {
                lS1.Visible = false;
                txtS1.Visible = false;
                label2.Visible = false;
            }
        }

        private void rbQ_CheckedChanged(object sender, EventArgs e)
        {
            if (lS1.Visible == false && lS2.Visible == false)
            {
                lS1.Visible = true;
                txtS1.Visible = true;
                lS2.Visible = true;
                txtS2.Visible = true;
                label2.Visible = true;
                label3.Visible = true;
                label4.Visible = true;
                lS3.Visible = true;
                txtS3.Visible = true;
            }

            if (rbQ.Checked == false)
            {
                lS1.Visible = false;
                txtS1.Visible = false;
                lS2.Visible = false;
                txtS2.Visible = false;
                label2.Visible = false;
                label3.Visible = false;
                label4.Visible = false;
                lS3.Visible = false;
                txtS3.Visible = false;
            }
        }

        private void rbP_CheckedChanged(object sender, EventArgs e)
        {
            if (lS1.Visible == false && lS2.Visible == false && lS3.Visible == false)
            {
                lS1.Visible = true;
                txtS1.Visible = true;
                lS2.Text = "Höhe";
                lS2.Visible = true;
                txtS2.Visible = true;
                label2.Visible = true;
                label3.Visible = true;
            }
            if (rbP.Checked == false)
            {
                lS1.Visible = false;
                txtS1.Visible = false;
                lS2.Text = "Seite 2";
                lS2.Visible = false;
                txtS2.Visible = false;
                label2.Visible = false;
                label3.Visible = false;
            }
        }
    }
}
