#include "golomb_ruler_cost_structure.h"
#include "../../tools/tools.h"

#include <algorithm>

using namespace std;

#define PENALIZATION 100

int zero_bounded_decrease(int x) { return (x > 0) ? x - 1 : 0; }

GolombRulerCostStructure::GolombRulerCostStructure(int _order, int _length)
    : Order(_order),
      Length(_length),
      Configuration(_order),
      measures(_length, 0),
      measures_intervenants(_length),
      measures_intervenants_index(_length),
      negative_measures_intervenants(_length),
      variables_in_negative_measures(_order, 0)
{}

int GolombRulerCostStructure::relative_cost(vector<int> & new_config, T_Changes change, bool updating)
{
    int new_value, new_pos, cost = CurrentCost;
    for(int i = 0; i < change.dim; i++)
    {
        new_value = change.new_values[i];
        new_pos = change.positions[i];

        // the case of changing the first
        cost += Tools::sign(Tools::sign(new_config[0]) - Tools::sign(Configuration[0])) * PENALIZATION;
        // <bgn 1> the case of changing the last
        if(Configuration[Order - 1] == Length && new_config[Order - 1] != Length)
            cost += PENALIZATION;
        else if(Configuration[Order - 1] != Length && new_config[Order - 1] == Length)
            cost -= PENALIZATION;
        // <end 1>

        // the case of changing and loosing ordering

    }
}

void GolombRulerCostStructure::init(vector<int> config)
{
    Configuration = config;
    CurrentCost = cost(Configuration);
}

int GolombRulerCostStructure::cost(vector<int> & config)
{
    fill(measures.begin(), measures.end(), 0);
    int min_val, min_index;
    int cost = 0, penalty = 0, distance = 0;
    for(int i = 0; i < Order - 1; i++)
        for(int j = i + 1; j < Order; j++)
        {
            distance = config[j] - config[i];
            min_val = min(config[i], config[j]);
            min_index = (min_val == config[i]) ? i : j;
            if (distance <= 0)
            {
                penalty ++;
                distance = abs(distance);
                negative_measures_intervenants[distance].push_back(min_val);
                variables_in_negative_measures[i] ++;
                variables_in_negative_measures[j] ++;
                continue;
            }
            if (distance < Length)
            {
                measures[distance] ++;
                measures_intervenants[distance].push_back(min_val);
                measures_intervenants_index[distance].push_back(min_index);
                // Not need to store the bigger, it can be obtained smaller + distance
            }
        }
    for (int i = 0; i < Length; i++)
        cost += Tools::sqr(zero_bounded_decrease(measures[i]));
    if(config[0] != 0)
        penalty += PENALIZATION;
    if(config[Order - 1] != Length)
        penalty += PENALIZATION;
    cost = cost + penalty;
    return cost;
}

int GolombRulerCostStructure::costOnVariable(int index)
{

}

void GolombRulerCostStructure::reset(){}
