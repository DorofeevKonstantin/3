namespace Benchmark.Benchmarks
{
    public interface IBenchmark
    {
        double GetAverageMark();
        double GetAverageExecutionTime();
        void Run();
        bool LimitExceeded();
    }
}