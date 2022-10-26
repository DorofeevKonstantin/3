using System;
using System.Security.Cryptography;
using System.Threading.Tasks;

namespace Benchmark.Benchmarks.Implementations
{
    public class Sha512Benchmark : IBenchmark
    {
        private static double LimitTime = 120;
        private static double CalculatedTime = 0.0;

        public void Run()
        {
            try
            {
                int n = 20;
                double summ = 0;
                GetExecuteTime();
                for (int i = 0; i < n; i++)
                {
                    summ += GetExecuteTime();
                }
                CalculatedTime = summ / (double)n;
            }
            catch (Exception exception)
            {
                //LogHelper.LogError(exception);
            }
        }

        public double GetAverageExecutionTime()
        {
            return CalculatedTime;
        }

        public double GetAverageMark()
        {
            throw new NotImplementedException();
        }

        public bool LimitExceeded()
        {
            bool exceeded = false;
            if (CalculatedTime > LimitTime)
                exceeded = true;
            return exceeded;
        }

        private double GetExecuteTime()
        {
            DateTime begin = DateTime.Now;
            InputAction();
            DateTime end = DateTime.Now;
            return (end - begin).TotalMilliseconds;
        }

        private int InputAction()
        {
            Parallel.For(1000000, 1001000, CreateSHA512);
            return 0;
        }

        private void CreateSHA512(int i)
        {
            Random rnd = new Random(i);
            SHA512.Create(rnd.NextDouble().ToString());
        }
    }
}