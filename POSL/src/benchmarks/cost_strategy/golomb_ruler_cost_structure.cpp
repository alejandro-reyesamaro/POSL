#include "golomb_ruler_cost_structure.h"
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

GolombRulerCostStructure::GolombRulerCostStructure(int _order, int _length)
    : Order(_order),
      Length(_length),
      Configuration(_order),
      measure_counters(_length + 1, 0), // no distance 0
      measure_per_variable(create_lists_for_measures(_order))
      //measures_intervenants(_length),
      //measures_intervenants_index(_length),
      //negative_measures_intervenants(_length),
      //variables_in_negative_measures(_order, 0)
      //aux_new_config(_order)
{}

int GolombRulerCostStructure::relative_cost(vector<int> & new_config, T_Changes, bool updating)
{
    /*
    int new_value, new_pos, old_value, cost = CurrentCost, distance, other_intervenant, min_val, min_index;
    copy(Configuration.begin(), Configuration.end(), aux_new_config);
    list<int>::iterator it_big;
    list<int>::iterator it_small;

    // the case of changing the first
    cost += Tools::sign(Tools::sign(new_config[0]) - Tools::sign(Configuration[0])) * PENALIZATION;
    // <bgn 1> the case of changing the last
    if(Configuration[Order - 1] == Length && new_config[Order - 1] != Length)
        cost += PENALIZATION;
    else if(Configuration[Order - 1] != Length && new_config[Order - 1] == Length)
        cost -= PENALIZATION;
    // <end 1>

    for(int i = 0; i < change.dim; i++)
    {
        old_value = Configuration[i];
        new_value = change.new_values[i];
        new_pos = change.positions[i];        

        // Remove information from old value
        for(int j = 0; j < Order; j++)
        {
            if (j == new_pos) continue;
            distance = (j < new_pos)
                ? aux_new_config[j] - new_value
                : new_value - aux_new_config[j];
            other_intervenant = distance + old_value;

            //---------------
            // to fix : it can't be applied find here (see .h)
            //----------------
            it_small = find(measures_intervenants[j].begin(), measures_intervenants[j].end(), old_value);
            it_big = find(measures_intervenants[j].begin(), measures_intervenants[j].end(), other_intervenant);

            if(it_small != measures_intervenants[j].end())
            {
                measures_intervenants[j].remove(old_value);
                measures[j] = max(0, measures[i]-1);
            }
            else if(it_big != measures_intervenants[j].end())
            {
                measures_intervenants[j].remove(other_intervenant);
                measures[j] = max(0, measures[j]-1);
            }
        }

        // Updating the information about new value
        for (int k = 0; k < Order; k++)
        {
            if (k == new_pos) continue;
            distance = (k < new_pos)
                ? new_config[k] - new_value
                : new_value - new_config[k];
            min_val = min(new_config[k], new_value);int zero_bounded_decrease(int x)
            min_index = (min_val == new_config[k]) ? new_pos : k;
            if (distance > 0 && distance < Length)
            {
                measures[distance] ++;
                measures_intervenants[distance].push_back(min_val);
                measures_intervenants_index[distance].push_back(min_index);
            }
        }
    }
    */
    if(updating)
    {
        init(new_config);
        return CurrentCost;
    }
    else return cost(new_config);
}

void GolombRulerCostStructure::init(vector<int> config)
{
    Configuration = config;
    CurrentCost = cost(Configuration);
}

int GolombRulerCostStructure::cost(vector<int> & config)
{
    fill(measure_counters.begin(), measure_counters.end(), 0);
    clear_measures(measure_per_variable);
    //int min_val, min_index;
    int cost = 0, penalty = 0, distance = 0;
    for(int i = 0; i < Order - 1; i++)
        for(int j = i + 1; j < Order; j++)
        {
            distance = config[j] - config[i];            
            //min_val = min(config[i], config[j]);
            //min_index = (min_val == config[i]) ? i : j;
            /*if (distance <= 0)
            {
                penalty ++;
                distance = abs(distance);
                negative_measures_intervenants[distance].push_back(min_val);
                variables_in_negative_measures[i] ++;
                variables_in_negative_measures[j] ++;
                continue;
            }*/
            if (distance > 0 && distance <= Length)
            {
                measure_per_variable[i].push_back(distance);
                measure_per_variable[j].push_back(distance);
                measure_counters[distance] ++;
                //measures_intervenants[distance].push_back(min_val);
                //measures_intervenants_index[distance].push_back(min_index);
                // Not need to store the bigger, it can be obtained smaller + distance
            }
        }
    for (int i = 0; i < Length; i++)
        cost += Tools::zero_bounded_decrease(measure_counters[i]);

    //int max_possible_measures = (Order * (Order - 1)) / 2;

    if(config[0] != 0)
        penalty += PENALIZATION;
    if(config[Order - 1] != Length)
        penalty += PENALIZATION;    

    cost = cost + penalty;

    return cost;
}

int GolombRulerCostStructure::costOnVariable(int index)
{
    int max_possible_measures_per_variable = Order - 1;
    list<int> measures_of_variable = measure_per_variable[index];
    measures_of_variable.unique();
    return max_possible_measures_per_variable - measures_of_variable.size();
}

void GolombRulerCostStructure::reset(){}
