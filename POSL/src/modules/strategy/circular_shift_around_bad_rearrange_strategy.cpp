#include "circular_shift_around_bad_rearrange_strategy.h"
#include "../../tools/tools.h"

#include <algorithm>
#include <limits>
#include <iostream>

using namespace std;

CircularShiftAroundBadRearrangeStrategy::CircularShiftAroundBadRearrangeStrategy(int configuration_size)
    : var_index(Tools::generateMonotony(configuration_size)),
      v(configuration_size)
{}

shared_ptr<Solution> CircularShiftAroundBadRearrangeStrategy::rearrangement(vector<int> current_configuration, shared_ptr<Benchmark> benchmark)
{
    Tools::shuffle(var_index);
    int bad_variable = 1;
    int ind = 0;
    for(vector<int>::iterator it = var_index.begin(); it != var_index.end(); ++it)
    {
        ind = *it;
        if(ind > 0 && benchmark->costOnVariable(ind) > 0)
        {
            bad_variable = ind;
            break;
        }
    }

    bad_variable ++;

    copy(current_configuration.begin(), current_configuration.end(), v.begin());
    std::rotate_copy(current_configuration.begin(), current_configuration.begin() + 1, current_configuration.begin() + bad_variable, v.begin());

    return make_shared<Solution>(benchmark->Domains(), v);
}
