#pragma once

#include "packer.h"
#include "../../data/solution.h"

class SolutionPacker : public Packer
{
    public:
        SolutionPacker(std::shared_ptr<Solution> solution);

        std::vector<int> pack();
        void update(std::vector<int> _configuration);

    private:
        std::vector<int> configuration;
};
