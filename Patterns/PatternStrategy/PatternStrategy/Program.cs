using PatternStrategy.Ducks;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PatternStrategy
{
    class Program
    {
        static void Main(string[] args)
        {
            List<DuckBase> ducks = new List<DuckBase>();
            ducks.Add(new WoodenDuck());
            ducks.Add(new RubberDuck());
            ducks.Add(new SimpleDuck());
            ducks.Add(new ExoticDuck());

            foreach (var duck in ducks)
            {
                duck.Display();
                duck.Swim();
                duck.Fly();
                duck.Quack();
                Console.WriteLine();
            }

            MechanicDuck mechDuck = new MechanicDuck();
            mechDuck.Display();
            mechDuck.Swim();
            mechDuck.Fly();
            mechDuck.Quack();
            Console.WriteLine();

            mechDuck.Windup();
            mechDuck.Display();
            mechDuck.Swim();
            mechDuck.Fly();
            mechDuck.Quack();
            Console.WriteLine();

            Console.ReadKey();
        }
    }
}
