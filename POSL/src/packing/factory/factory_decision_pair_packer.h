#pragma once

#include "factory_packer.h"
#include "../packers/decision_pair_packer.h"

class FactoryDecisionPairPacker : public FactoryPacker
{
    public:
        FactoryDecisionPairPacker(shared_ptr<DecisionPair> pair);
};
