#include "factory_solution_packer.h"

FactorySolutionPacker::FactorySolutionPacker(shared_ptr<Solution> solution)
    : FactoryPacker(make_shared<SolutionPacker>(solution))
{}


