#include "standard_apply_change_behavior.h"

#include <algorithm>

StandardApplyChangeBehavior::StandardApplyChangeBehavior(int config_size)
    : ApplyChangeBehavior(config_size)
{}

vector<int> StandardApplyChangeBehavior::applyChangeAt(int index, vector<int> config, vector<T_Changes> changes)
{
    if(index >= config.size()) return config;
    copy(config.begin(), config.end(), configuration_changed.begin());
    for (unsigned int i = 0;  i < changes[index].dim; i++)
        configuration_changed[changes[index].positions[i]] = changes[index].new_values[i];
    return configuration_changed;
}