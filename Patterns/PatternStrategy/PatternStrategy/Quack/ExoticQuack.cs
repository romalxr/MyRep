using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PatternStrategy.Quack
{
    public class ExoticQuack : iQuackable
    {
        public void Quack()
        {
            Console.WriteLine("Meow! Meow!");
        }

    }
}
