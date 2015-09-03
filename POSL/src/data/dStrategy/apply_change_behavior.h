#pragma once

#include "../t_changes.h"

#include <vector>

using namespace std;

class ApplyChangeBehavior
{
    public:
        ApplyChangeBehavior(int config_size);
        virtual vector<int> applyChangeAt(int index, vector<int> config, vector<T_Changes> changes) = 0;

    protected:
        vector<int> configuration_changed;
};
