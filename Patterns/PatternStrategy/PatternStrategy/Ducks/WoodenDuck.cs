using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PatternStrategy.Ducks
{
    class WoodenDuck : DuckBase
    {
        public override void Display()
        {
            Console.WriteLine("Hi! I'm a wooden duck!");
        }
    }
}
