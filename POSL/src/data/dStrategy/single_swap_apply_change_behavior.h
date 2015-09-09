#pragma once

#include "apply_change_behavior.h"

class SingleSwapApplyChangeBehavior : public ApplyChangeBehavior
{
    public:
        SingleSwapApplyChangeBehavior(int config_size);
        std::vector<int> applyChangeAt(int index, std::vector<int> config, std::vector<T_Changes> changes);
};
