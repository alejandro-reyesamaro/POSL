#pragma once

#include "factory_packer.h"
#include "../packers/solution_packer.h"

class FactorySolutionPacker : public FactoryPacker
{
    public:
        FactorySolutionPacker(shared_ptr<Solution> solution);
};
