#pragma once

#include "packer.h"
#include "../../data/decision_pair.h"

class DecisionPairPacker : public Packer
{
    public:
        DecisionPairPacker(std::shared_ptr<DecisionPair> pair);

        std::vector<int> pack();
        //static DecisionPair * unpack(int * pack, vector<Domain> domains);

        void update(std::vector<int> current, std::vector<int> found);

    private:
        std::vector<int> current_configuration;
        std::vector<int> found_configuration;
};
