#pragma once

#include "apply_change_behavior.h"

class SingleSwapApplyChangeBehavior : public ApplyChangeBehavior
{
    public:
        SingleSwapApplyChangeBehavior(int config_size);
        vector<int> applyChangeAt(int index, vector<int> config, vector<T_Changes> changes);
};
