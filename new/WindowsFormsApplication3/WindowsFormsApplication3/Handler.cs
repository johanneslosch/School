using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApplication3
{
    public class Handler
    {
        public static bool thoughZero(double one, double two)
        {
            if (two == 0.00) {
                return false;
            }
            else
            {
                return true;
            }
        }
        public static bool checkFields(String txt1, String txt2)
        {
            if (!String.IsNullOrEmpty(txt1) && !String.IsNullOrEmpty(txt2))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
