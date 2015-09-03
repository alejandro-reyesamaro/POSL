#pragma once

#include "apply_change_behavior.h"

class SortedApplyChangeBehavior : public ApplyChangeBehavior
{
    public:
        SortedApplyChangeBehavior(int config_size);
        vector<int> applyChangeAt(int index, vector<int> config, vector<T_Changes> changes);
    private:
        ApplyChangeBehavior * pb;
};
