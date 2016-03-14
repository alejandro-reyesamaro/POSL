#include "all_circular_shift_around_worst_rearrange_strategy.h"

#include <algorithm>
#include <limits>
#include <iostream>

using namespace std;

AllCircularShiftAroundWorstRearrangeStrategy::AllCircularShiftAroundWorstRearrangeStrategy(int configuration_size)
    : temp_vec(configuration_size),
      best_conf(configuration_size)
{}

/// Example code in cpp.sh/32whl
shared_ptr<Solution> AllCircularShiftAroundWorstRearrangeStrategy::rearrangement(std::shared_ptr<PSP> psp,
                                                                                 std::vector<int> current_configuration)
{
    int worst_index = psp->GetBenchmark()->sickestVariable();
    int w = worst_index + 1;
    //std::rotate(myvector.begin()+2,myvector.begin()+3,myvector.begin()+5);
    int cost = 0, best_cost = std::numeric_limits<int>::max();    
    int size = current_configuration.size();


    // sub-arrays ending with WORST
    for(int i = 0; i < worst_index; i++)
    {
        copy(current_configuration.begin(), current_configuration.end(), temp_vec.begin());
        std::rotate_copy(current_configuration.begin() + i, current_configuration.begin() + i + 1, current_configuration.begin() + w, temp_vec.begin() + i);


        cost = psp->GetBenchmark()->solutionCost(temp_vec);
        if (cost < best_cost)
        {
            best_cost = cost;
            copy(temp_vec.begin(), temp_vec.end(), best_conf.begin());
        }
    }

    // sub-arrays begining with WORST
    for(int i = 1; i < size - w + 1; i++)
    {
        copy(current_configuration.begin(), current_configuration.end(), temp_vec.begin());
        std::rotate_copy(current_configuration.begin() + w - 1, current_configuration.begin() + w, current_configuration.begin() + w + i, temp_vec.begin() + w - 1);


        cost = psp->GetBenchmark()->solutionCost(temp_vec);
        if (cost < best_cost)
        {
            best_cost = cost;
            copy(temp_vec.begin(), temp_vec.end(), best_conf.begin());
        }
    }

    return make_shared<Solution>(psp->GetBenchmark()->Domains(), best_conf);
}


/*
cout << worst_index << endl;
int count = 1;
*/

/*
// print out content:
cout << count ++ << ": ";
for (vector<int>::iterator it=temp_vec.begin(); it!=temp_vec.end(); ++it)
    cout << ' ' << *it;
cout << '\n';
*/
