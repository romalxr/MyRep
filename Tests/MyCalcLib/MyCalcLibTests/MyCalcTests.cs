using Microsoft.VisualStudio.TestTools.UnitTesting;
using MyCalcLib;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyCalcLib.Tests
{
    [TestClass()]
    public class MyCalcTests
    {

        public TestContext TestContext { get; set; }

        [DataSource("Microsoft.VisualStudio.TestTools.DataSource.XML",
            "testData.xml",
            "Sum",
            DataAccessMethod.Sequential)]

        [TestMethod()]
        public void SumTests()
        {
            // arrange
            int a = Convert.ToInt32(TestContext.DataRow["a"]);
            int b = Convert.ToInt32(TestContext.DataRow["b"]);
            int expected = Convert.ToInt32(TestContext.DataRow["expected"]);

            // act
            MyCalc c = new MyCalc();
            int actual = c.Sum(a, b);

            // assert
            Assert.AreEqual(expected, actual);
        }

        [TestMethod()]
        public void Div_10_2_5Expected()
        {
            // arrange
            int x = 10;
            int y = 2;
            int expected = 5;

            // act
            MyCalc c = new MyCalc();
            int actual = c.Div(x, y);

            // assert
            Assert.AreEqual(expected, actual);
        }

        [TestMethod()]
        [ExpectedException(typeof(DivideByZeroException))]
        public void Div_10_0_ExceptionExpected()
        {
            // arrange
            int x = 10;
            int y = 0;           

            // act
            MyCalc c = new MyCalc();
            int actual = c.Div(x, y);

            // assert
        }

        [TestMethod()]
        public void Sqrt_4input_2returned()
        {
            // arrange
            const double input = 4;
            const double expected = 2;

            // act
            MyCalc c = new MyCalc();
            double actual = c.GetSqrt(input);

            // assert
            Assert.AreEqual(expected, actual, "Sqrt of {0} should have been {1}!", input, expected);
        }

        [TestMethod()]

        public void Sqrt_10input_3dot1returned()
        {
            // arrange
            const double input = 10;
            const double expected = 3.1;
            const double delta = 0.07;

            // act
            MyCalc c = new MyCalc();
            double actual = c.GetSqrt(input);

            // assert
            Assert.AreEqual(expected, actual, delta, "Sqrt of {0} should have been {1}!", input, expected);
        }
    }
}