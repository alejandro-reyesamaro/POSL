#pragma once

#include "../modules/grouped_sequential_computation.h"

class GroupedSequentialComputationUncoder
{
    public:
        GroupedSequentialComputationUncoder();
        std::shared_ptr<GroupedSequentialComputation> uncode(std::string code, std::shared_ptr<Benchmark> bench);
};
