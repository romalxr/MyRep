using PatternStrategy.Fly;
using PatternStrategy.Quack;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PatternStrategy.Ducks
{
    public abstract class DuckBase
    {
        protected iFlyable flyBehavior;
        protected iQuackable quackBehavior;

        public DuckBase()
        {
            flyBehavior = new NoFly();
            quackBehavior = new NoQuack();
        }

        public abstract void Display();

        public void Swim()
        {
            Console.WriteLine("I'm swimming");
        }

        public void Quack()
        {
            quackBehavior.Quack();
        }

        public void Fly()
        {
            flyBehavior.Fly();
        }
    }
}
