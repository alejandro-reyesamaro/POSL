#pragma once

#include "rearrange_strategy.h"

class AllCircularShiftAroundWorstRearrangeStrategy : public RearrangeStrategy
{
    public:
        AllCircularShiftAroundWorstRearrangeStrategy(int configuration_size);

        std::shared_ptr<Solution> rearrangement(std::vector<int> current_configuration, std::shared_ptr<Benchmark> benchmark);

    private:
        std::vector<int> temp_vec;
        std::vector<int> best_conf;
};
