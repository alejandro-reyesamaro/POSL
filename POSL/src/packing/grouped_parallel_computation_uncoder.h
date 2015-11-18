#pragma once

#include "../modules/grouped_parallel_computation.h"

class GroupedParallelComputationUncoder
{
    public:
        GroupedParallelComputationUncoder();
        std::shared_ptr<GroupedParallelComputation> uncode(std::string code, std::shared_ptr<Benchmark> bench);
};
