#pragma once

#include "rearrange_strategy.h"

class CircularShiftAroundBadRearrangeStrategy : public RearrangeStrategy
{
    public:
        CircularShiftAroundBadRearrangeStrategy(int configuration_size);

        std::shared_ptr<Solution> rearrangement(std::shared_ptr<PSP> psp, std::vector<int> current_configuration);

    private:
        std::vector<int> var_index;
        std::vector<int> v;
};
