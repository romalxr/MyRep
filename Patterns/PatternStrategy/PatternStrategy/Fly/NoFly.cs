using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PatternStrategy.Fly
{
    public class NoFly : iFlyable
    {
        public void Fly()
        {
            Console.WriteLine("I cannot fly");
        }        
    }
}
