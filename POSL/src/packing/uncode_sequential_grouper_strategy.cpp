#include "uncode_sequential_grouper_strategy.h"

UncodeSequentialGrouperStrategy::UncodeSequentialGrouperStrategy()
{}

GroupedSequentialComputation * UncodeSequentialGrouperStrategy::uncode(string code, Benchmark * bench)
{
    UncodeOperatorStrategy * build_strategy = new UncodeOperatorStrategy();
    return new GroupedSequentialComputation(build_strategy->uncode(code, bench));
}
