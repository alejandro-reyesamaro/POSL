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

shared_ptr<Solution> CircularShiftAroundBadRearrangeStrategy::rearrangement(std::shared_ptr<PSP> psp, std::vector<int> current_configuration)
{
    psp->GetRandomizer()->vector_shuffle(var_index);
    int bad_variable = 1;
    int ind = 0;
    for(vector<int>::iterator it = var_index.begin(); it != var_index.end(); ++it)
    {
        ind = *it;
        if(ind > 0 && psp->GetBenchmark()->costOnVariable(ind) > 0)
        {
            bad_variable = ind;
            break;
        }
    }

    bad_variable ++;

    copy(current_configuration.begin(), current_configuration.end(), v.begin());
    std::rotate_copy(current_configuration.begin(), current_configuration.begin() + 1, current_configuration.begin() + bad_variable, v.begin());

    return make_shared<Solution>(psp->GetBenchmark()->Domains(), v);
}
