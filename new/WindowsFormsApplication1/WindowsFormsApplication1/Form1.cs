using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        //gruss button
        private void button1_Click(object sender, EventArgs e)
        {
            lUeberschrift.Visible = true;
        }

        //clear button
        private void button2_Click(object sender, EventArgs e)
        {
            lUeberschrift.Visible = false;
        }

        //End code
        private void button3_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}
