using Benchmark.Benchmarks;
using Benchmark.Benchmarks.Implementations;
using System;

namespace Benchmark
{
    class Program
    {
        static void Main(string[] args)
        {
            // somewhere in program logic (application start)
            //if (ApplicationSettings.firstProgramLaunch)
            //    RunBenchmark();
            //ApplicationSettings.ApplyStartSettings();
            RunBenchmark();
        }

        private static void RunBenchmark()
        {
            try
            {
                IBenchmark benchmark = new Sha512Benchmark(); // can replace implementation later
                benchmark.Run();
                var benchmarkExecutionTime = benchmark.GetAverageExecutionTime();
                System.Diagnostics.Debug.WriteLine($"benchmarkExecutionTime = {benchmarkExecutionTime} ms");
                //LogHelper.LogDebug($"Benchmark execution time : {benchmarkExecutionTime} ms");
                //if (benchmark.LimitExceeded())
                //    ApplicationSettings.isLowQuality = true;
            }
            catch (Exception exception)
            {
                //LogHelper.LogError(exception);
            }
        }
    }
}