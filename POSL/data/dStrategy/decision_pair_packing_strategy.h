#pragma once

#include "packing_strategy.h"
#include "../decision_pair.h"

class DecisionPairPackingStrategy : public PackingStrategy
{
    public:
        DecisionPairPackingStrategy(DecisionPair * _pair);
        int * pack();

    private:
        DecisionPair * pair;
};
