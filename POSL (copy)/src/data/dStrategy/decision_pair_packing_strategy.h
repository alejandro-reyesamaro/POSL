#pragma once

#include "packing_strategy.h"
#include "../decision_pair.h"

class DecisionPairPackingStrategy : public PackingStrategy
{
    public:
        DecisionPairPackingStrategy(DecisionPair * _pair);
        vector<int> pack();
        int BodySize();
        vector<int> body();

        static DecisionPair * unpack(int * pack, vector<Domain> domains);

    private:
        DecisionPair * pair;
};
