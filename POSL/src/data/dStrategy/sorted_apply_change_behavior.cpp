#include "sorted_apply_change_behavior.h"
#include "standard_apply_change_behavior.h"

#include <algorithm>

SortedApplyChangeBehavior::SortedApplyChangeBehavior(int config_size)
    : ApplyChangeBehavior(config_size),
      pb(std::make_shared<StandardApplyChangeBehavior>(config_size))
{}

std::vector<int> SortedApplyChangeBehavior::applyChangeAt(int index, std::vector<int> config, std::vector<T_Changes> changes)
{
    std::vector<int> config_changed = pb->applyChangeAt(index, config, changes);
    std::sort(config_changed.begin(), config_changed.end());
    return config_changed;
}

