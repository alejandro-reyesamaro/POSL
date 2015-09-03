#include "sorted_apply_change_behavior.h"
#include "standard_apply_change_behavior.h"

#include <algorithm>

SortedApplyChangeBehavior::SortedApplyChangeBehavior(int config_size)
    : ApplyChangeBehavior(config_size),
      pb(new StandardApplyChangeBehavior(config_size))
{}

vector<int> SortedApplyChangeBehavior::applyChangeAt(int index, vector<int> config, vector<T_Changes> changes)
{
    vector<int> config_changed = pb->applyChangeAt(index, config, changes);
    sort(config_changed.begin(), config_changed.end());
    return config_changed;
}

