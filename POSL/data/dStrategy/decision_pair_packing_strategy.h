#pragma once

#include "packing_strategy.h"
#include "../decision_pair.h"

class DecisionPairPackingStrategy : public PackingStrategy
{
    public:
        DecisionPairPackingStrategy(DecisionPair * _pair);
        int * pack();
        int BodySize();
        int * body();

    private:
        DecisionPair * pair;
};
