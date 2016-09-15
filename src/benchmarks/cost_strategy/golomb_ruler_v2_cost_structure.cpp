/*
#include "golomb_ruler_v2_cost_structure.h"
#include "../../tools/tools.h"

#include <algorithm>

using namespace std;

#define PENALIZATION 100

vector<list<int>> create_lists_for_measures(int size)
{
    vector<list<int>> v_result;
    for(int i = 0; i <= size - 1; i++)
    {
        list<int> l;
        v_result.push_back(l);
    }
    return v_result;
}

void clear_measures(vector<list<int>> & _measures_par_variable)
{
    for(unsigned int i = 0; i <= _measures_par_variable.size() - 1; i++)
        _measures_par_variable[i].clear();
}

GolombRulerV2CostStructure::GolombRulerV2CostStructure(int _order, int _length)
    : Order(_order),
      Length(_length),
      Configuration(_order - 1), // here, we represent the distances between marks
      measure_counters(_length + 1, 0), // no distance 0
      measure_per_variable(create_lists_for_measures(_order))
      //measures_intervenants(_length),
      //measures_intervenants_index(_length),
      //negative_measures_intervenants(_length),
      //variables_in_negative_measures(_order, 0)
      //aux_new_config(_order)
{}

int GolombRulerV2CostStructure::relative_cost(vector<int> & new_config, T_Changes, bool updating)
{
    if(updating)
    {
        init(new_config);
        return CurrentCost;
    }
    else return cost(new_config);
}

void GolombRulerV2CostStructure::init(vector<int> config)
{
    Configuration = config;
    CurrentCost = cost(Configuration);
}

int GolombRulerV2CostStructure::cost(vector<int> & config)
{
    fill(measure_counters.begin(), measure_counters.end(), 0);
    clear_measures(measure_per_variable);
    //int min_val, min_index;
    int cost = 0, distance = 0;
    for(int i = 0; i < Order - 2; i++)
    {
        distance = config[i];
        for(int j = i; j < Order -1 ; j++)
        {
            distance += (i == j) ? 0 : config[j];
            if (distance <= Length) // distance should be allways > 0
            {
                measure_per_variable[i].push_back(distance);
                measure_per_variable[j].push_back(distance);
                measure_counters[distance] ++;
            }
        }
    }
    for (int i = 0; i < Length; i++)
        cost += Tools::zero_bounded_decrease(measure_counters[i]);

    //int max_possible_measures = (Order * (Order - 1)) / 2;

    return cost;
}

int GolombRulerV2CostStructure::costOnVariable(int index)
{
    int max_possible_measures_per_variable = Order - 1;
    list<int> measures_of_variable = measure_per_variable[index];
    measures_of_variable.unique();
    return max_possible_measures_per_variable - measures_of_variable.size();
}

void GolombRulerV2CostStructure::reset(){}
*/
