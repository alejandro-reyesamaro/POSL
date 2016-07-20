#include "factory_solution_packer.h"

FactorySolutionPacker::FactorySolutionPacker(std::shared_ptr<Solution> solution)
    : FactoryPacker(std::make_shared<SolutionPacker>(solution))
{}


