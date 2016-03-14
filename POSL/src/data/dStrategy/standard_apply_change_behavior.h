#pragma once

#include "apply_change_behavior.h"

class StandardApplyChangeBehavior : public ApplyChangeBehavior
{
    public:
        StandardApplyChangeBehavior(int config_size);
        std::vector<int> applyChangeAt(int index, std::vector<int> & config, std::vector<T_Changes> changes);
        void sortConfiguration();
};
