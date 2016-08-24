using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyCalcLib
{
    public class MyCalc
    {        
        public int Sum(int a, int b)
        {
            return a + b;
        }

        public int Div(int x, int y)
        {
            return x / y;
        }

        public double GetSqrt(double value)
        {
            return Math.Sqrt(value);
        }

        public string SayHello(string name)
        {
            if (name == null)
            {
                throw new ArgumentNullException("Parameter is null");
            }

            return "Hello " + name;
        }
    }
}
