using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PatternStrategy.Quack
{
    public class SimpleQuack : iQuackable
    {
        public void Quack()
        {
            Console.WriteLine("Quack! Quack!");
        }

    }
}
