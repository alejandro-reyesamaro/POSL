#pragma once

#include "../../tools/t_changes.h"

#include <vector>

class ApplyChangeBehavior
{
    public:
        ApplyChangeBehavior(int config_size);
        virtual std::vector<int> applyChangeAt(int index, std::vector<int> & config, std::vector<T_Changes> changes) = 0;

    protected:
        std::vector<int> configuration_changed;
};
