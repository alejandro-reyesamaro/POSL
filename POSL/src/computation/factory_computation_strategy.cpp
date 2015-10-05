#include "factory_computation_strategy.h"

using namespace std;

FactoryComputationStrategy::FactoryComputationStrategy(shared_ptr<Benchmark> _bench, string tag)
    : TAG(tag),
      bench(_bench)
{}
