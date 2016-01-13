#pragma once

#include "rearrange_strategy.h"

class CircularShiftAroundBadRearrangeStrategy : public RearrangeStrategy
{
    public:
        CircularShiftAroundBadRearrangeStrategy(int configuration_size);

        std::shared_ptr<Solution> rearrangement(std::vector<int> current_configuration, std::shared_ptr<Benchmark> benchmark);

    private:
        std::vector<int> var_index;
        std::vector<int> v;
};
