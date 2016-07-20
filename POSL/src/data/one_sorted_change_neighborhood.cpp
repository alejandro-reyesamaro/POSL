#include "one_sorted_change_neighborhood.h"
#include "../tools/tools.h"
#include "../tools/golomb_tools.h"
#include "dStrategy/sorted_apply_change_behavior.h"
#include "dStrategy/elements_change_iterator.h"
#include "../tools/tools.h"

#include <iostream>

using namespace std;

OneSortedChangeNeighborhood::OneSortedChangeNeighborhood(int _config_size)
    : Neighborhood(_config_size),
      changeAtBhv(std::make_shared<SortedApplyChangeBehavior>(_config_size)),
      changes(0),
      indexes(Tools::generateMonotony(1, _config_size - 2))
{}

std::shared_ptr<POSL_Iterator> OneSortedChangeNeighborhood::getIterator()
{
    return std::make_shared<ElementsChangeIterator>(shared_from_this());
}

void OneSortedChangeNeighborhood::Init(shared_ptr<PSP> psp, std::vector<int> & _configuration)
{
    // change this -> the neighborhood to give the posibility to reach the legnth at the end
    if((int)measured_distances.size() != GolombTools::max_posible_distances(_configuration.size(), _configuration[_configuration.size()-1]) + 1)
        measured_distances.resize(GolombTools::max_posible_distances(_configuration.size(), _configuration[_configuration.size()-1]) + 1, false);

    fill(measured_distances.begin(), measured_distances.end(), false);

    int distance = 0;
    for(unsigned int i = 0; i < _configuration.size() - 1; i++)
    {
        distance = _configuration[i+1] - _configuration[i];
        if(distance > 0 && distance < (int)measured_distances.size())
           measured_distances[distance] = true;
    }
    copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges(psp->GetRandomizer());
}

void OneSortedChangeNeighborhood::updateChanges(shared_ptr<Randomizer> rand)
{
    changes.clear();
    //int sz = changes.size();
    rand->vector_shuffle(indexes);

    int current_value, posible_values_size;
    T_Changes next_change;

    std::vector<int> posible_values;
    for(unsigned int i = 0; i < current_configuration.size()-2; i++)
    {
        current_value = current_configuration[indexes[i]];
        posible_values = GolombTools::vector_possible_values_to_hold_sorted(indexes[i], current_configuration);
        rand->vector_shuffle(posible_values);
        posible_values_size = posible_values.size();
        for (int pos_new_value = 0; pos_new_value <  posible_values_size ; pos_new_value++) // or posible_values_size/2
            if(posible_values[pos_new_value] != current_value && is_valid_distance(indexes[i], posible_values[pos_new_value]))
            {
                next_change = {{indexes[i]}, {posible_values[pos_new_value]}, 1};
                changes.push_back(next_change);
            }
    }
}

bool OneSortedChangeNeighborhood::is_valid_distance(int new_index, int new_value)
{
    //int distance1 = new_value - current_configuration[new_index-1];
    //int distance2 = current_configuration[new_index+1] - new_value;

    int distance_left = current_configuration[new_index] - current_configuration[new_index - 1];
    int distance_right = current_configuration[new_index + 1] - current_configuration[new_index];
    /*
    if(!measured_distances[distance_left])
    {
        cout << "bateo con " << distance_left << endl;
        cout << Tools::configurationToString(current_configuration) << endl;
        exit(0);
    }
    */
    measured_distances[distance_left] = false;
    /*
    if(!measured_distances[distance_right])
    {
        cout << "bateo con " << distance_right << endl;
        cout << Tools::configurationToString(current_configuration) << endl;
        exit(0);
    }
    */
    measured_distances[distance_right] = false;

    bool result =  ! (measured_distances[new_value - current_configuration[new_index-1]] ||
                      measured_distances[current_configuration[new_index+1] - new_value]);
    measured_distances[distance_left] = true;
    measured_distances[distance_right] = true;

    // the case both new distances are equals
    distance_left = new_value - current_configuration[new_index-1];
    distance_right = current_configuration[new_index+1] - new_value;

    /*
    if(distance_left == distance_right && result)
    {
        cout << "new index: " << new_index << "new value: " << new_value << endl;
        cout << Tools::configurationToString(current_configuration) << endl;
        exit(0);
    }
    */
    return (distance_left != distance_right && result); //result;
}

std::shared_ptr<FactoryPacker> OneSortedChangeNeighborhood::BuildPacker(){ throw "Not implemented yet"; }

std::vector<int> OneSortedChangeNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);
}
