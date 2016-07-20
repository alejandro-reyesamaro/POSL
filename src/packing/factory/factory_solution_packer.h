#pragma once

#include "factory_packer.h"
#include "../packers/solution_packer.h"

class FactorySolutionPacker : public FactoryPacker
{
    public:
        FactorySolutionPacker(std::shared_ptr<Solution> solution);
};
