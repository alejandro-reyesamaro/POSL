#pragma once

#include "factory_packer.h"
#include "../packers/solution_packer.h"

class FactorySolutionPacker : public FactoryPacker
{
    public:
        FactorySolutionPacker(Solution * solution);
};
