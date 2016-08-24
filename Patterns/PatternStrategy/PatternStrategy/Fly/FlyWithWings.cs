using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PatternStrategy.Fly
{
    public class FlyWithWings : iFlyable
    {
        public void Fly()
        {
            Console.WriteLine("I'm flying!");
        }
    }
}
