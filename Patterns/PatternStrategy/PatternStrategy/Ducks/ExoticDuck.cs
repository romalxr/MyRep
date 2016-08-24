using PatternStrategy.Fly;
using PatternStrategy.Quack;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PatternStrategy.Ducks
{
    class ExoticDuck : DuckBase
    {
        public ExoticDuck()
        {
            quackBehavior = new ExoticQuack();
            flyBehavior = new FlyWithWings();
        }

        public override void Display()
        {
            Console.WriteLine("Hi! I'm a exotic duck!");
        }
    }
}
