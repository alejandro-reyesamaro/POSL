#pragma once

#include "apply_change_behavior.h"
#include <memory>

class SortedApplyChangeBehavior : public ApplyChangeBehavior
{
    public:
        SortedApplyChangeBehavior(int config_size);
        std::vector<int> applyChangeAt(int index, std::vector<int> config, std::vector<T_Changes> changes);
    private:
        std::shared_ptr<ApplyChangeBehavior> pb;
};
