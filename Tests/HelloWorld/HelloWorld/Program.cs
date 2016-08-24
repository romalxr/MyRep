using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloWorld
{
    class Program
    {
        static int Main(string[] args)
        {
            if (args.Count() == 0)
                return 1;

            if (args[0] != "Hello world")
                return 1;

            Console.WriteLine(args[0]);
            return 0;
        }
    }
}
