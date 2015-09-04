#pragma once

#include "packer.h"
#include "../../data/decision_pair.h"

class DecisionPairPacker : public Packer
{
    public:
        DecisionPairPacker(DecisionPair * pair);

        vector<int> pack();
        //static DecisionPair * unpack(int * pack, vector<Domain> domains);

        void update(vector<int> current, vector<int> found);

    private:
        vector<int> current_configuration;
        vector<int> found_configuration;        
};
