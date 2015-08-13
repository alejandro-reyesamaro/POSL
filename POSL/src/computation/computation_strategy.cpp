#include "computation_strategy.h"
#include "../data/seed.h"

ComputationStrategy::ComputationStrategy(FactoryComputationStrategy * builder)
    : module(builder->buildModule())
{}

Solution * ComputationStrategy::execute(PSP * psp)
{
    ComputationData * result = module->execute(psp, new Seed());
    return (Solution *)result;
}
