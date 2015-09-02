#include "factory_solution_packer.h"

FactorySolutionPacker::FactorySolutionPacker(Solution * solution)
    : FactoryPacker(new SolutionPacker(solution))
{}


