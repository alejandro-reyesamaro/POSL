#pragma once

#include "packer.h"
#include "../data/decision_pair.h"

class DecisionPairPacker : public Packer
{
    public:
        DecisionPairPacker(DecisionPair * pair);
        vector<int> pack();

    private:
        vector<int> current_configuration;
        vector<int> found_configuration;
        vector<int> package;
};
