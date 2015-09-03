#pragma once

#include "apply_change_behavior.h"

class StandardApplyChangeBehavior : public ApplyChangeBehavior
{
    public:
        StandardApplyChangeBehavior(int config_size);
        vector<int> applyChangeAt(int index, vector<int> config, vector<T_Changes> changes);
        void sortConfiguration();
};
