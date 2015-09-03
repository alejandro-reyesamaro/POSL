#include "single_swap_apply_change_behavior.h"

#include <algorithm>

SingleSwapApplyChangeBehavior::SingleSwapApplyChangeBehavior(int config_size)
    : ApplyChangeBehavior(config_size)
{}

vector<int> SingleSwapApplyChangeBehavior::applyChangeAt(int index, vector<int> config, vector<T_Changes> changes)
{
    if(index >= config.size()) return config;
    copy(config.begin(), config.end(), configuration_changed.begin());
    swap(configuration_changed[changes[index].positions[0]],configuration_changed[changes[index].positions[1]]);
    return configuration_changed;
}
