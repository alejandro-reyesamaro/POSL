#include "computation_strategy.h"
#include "../data/seed.h"

#include <iostream>
using namespace std;

ComputationStrategy::ComputationStrategy(shared_ptr<FactoryComputationStrategy> builder)
    : TAG(builder->TAG),
      module(builder->buildModule())
{}

shared_ptr<Solution> ComputationStrategy::execute(shared_ptr<PSP> psp)
{
    return static_pointer_cast<Solution>(module->execute(psp, make_shared<Seed>()));
}
