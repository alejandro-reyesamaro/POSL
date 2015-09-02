#include "uncode_parallel_grouper_strategy.h"

UncodeParallelGrouperStrategy::UncodeParallelGrouperStrategy()
{}

GroupedParallelComputation * UncodeParallelGrouperStrategy::uncode(string code, Benchmark * bench)
{
    UncodeOperatorStrategy * build_strategy = new UncodeOperatorStrategy();
    return new GroupedParallelComputation(build_strategy->uncode(code, bench));
}
