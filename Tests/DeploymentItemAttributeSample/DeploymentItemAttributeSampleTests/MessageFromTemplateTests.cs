using Microsoft.VisualStudio.TestTools.UnitTesting;
using DeploymentItemAttributeSample;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DeploymentItemAttributeSample.Tests
{
    [TestClass()]
    [DeploymentItem("Files\\ExamCreatedResult.txt")]
    [DeploymentItem("Files\\ExamCreatedTemplate.txt")]
    public class MessageFromTemplateTests
    {
        [TestMethod()]
        public void FromTemplate_PassTestValue_StringFromTemplateReturned()
        {
            MessageFromTemplate messageBuilder = new MessageFromTemplate();
            messageBuilder.TemplateFolder = ".";

            string expectedResult = File.ReadAllText("ExamCreatedResult.txt");
            string actualResult = messageBuilder.FromTemplate("TestExam", "Beginner", new DateTime(2000, 1, 1));

            Assert.AreEqual(expectedResult, actualResult);
        }
    }
}