#pragma once

#include "packer.h"
#include "../../data/solution.h"

class SolutionPacker : public Packer
{
    public:
        SolutionPacker(shared_ptr<Solution> solution);

        vector<int> pack();
        //static Solution * unpack(int * pack, vector<Domain> domains);
        void update(vector<int> _configuration);

    private:
        vector<int> configuration;
};
