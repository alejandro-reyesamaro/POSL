#include "golomb_ruler_relative_cost_structure.h"
#include "../../tools/tools.h"

#include <algorithm>

using namespace std;

#define PENALIZATION 100

GolombRulerRelativeCostStructure::GolombRulerRelativeCostStructure(int _order, int _length)
    : Order(_order),
      Length(_length),
      Configuration(_order),
      aux_configuration(_order),
      measure_counters(_length + 1, 0), // no distance 0
      aux_measure_counters(_length + 1, 0),
      measure_per_variable(make_shared<GolombMeasuresStruct>(_order))
{}

int GolombRulerRelativeCostStructure::relative_cost(vector<int> & new_config, T_Changes change, bool updating)
{
    if(!updating)
    {
        copy(measure_counters.begin(), measure_counters.end(), aux_measure_counters.begin());
        copy(Configuration.begin(), Configuration.end(), aux_configuration.begin());
    }
    for(unsigned int i = 0; i < change.dim; i++)
    {
        update_measures(aux_configuration,
                        change.positions[i],
                        change.new_values[i],
                        (updating) ? measure_counters : aux_measure_counters,
                        updating);

    }

    int penalty = 0, cost = 0;

    for (int i = 0; i < Length; i++)
        cost += Tools::zero_bounded_decrease((updating) ? measure_counters[i] : aux_measure_counters[i]);

    if(new_config[0] != 0)
        penalty += PENALIZATION;
    if(new_config[Order - 1] != Length)
        penalty += PENALIZATION;

    cost += penalty;

    if(updating)
    {
        copy(aux_configuration.begin(), aux_configuration.end(), Configuration.begin());
        CurrentCost = cost;
    }
    return cost;
}

void GolombRulerRelativeCostStructure::update_measures(vector<int> & configuration, // before change
                                                       int new_pos,
                                                       int new_value,
                                                       vector<int> & measures,
                                                       bool updating)
{
    int distance = 0;
    for(int i = 0; i < Order; i++)
        if(i != new_pos)
        {
            distance = configuration[max(i, new_pos)] - configuration[min(i, new_pos)];
            measures[distance] = Tools::zero_bounded_decrease(measures[distance]);
            if(updating)
            {
                measure_per_variable->removeDistanceFromVariable(i, distance);
                measure_per_variable->removeDistanceFromVariable(new_pos, distance);
            }
        }
    for(int i = 0; i < Order; i++)
        if(i != new_pos)
        {
            distance = (i < new_pos)
                       ? new_value - configuration[i]
                       : configuration[i] - new_value;
            measures[distance] ++;
            if(updating)
            {
                measure_per_variable->addVariableDistance(i, distance);
                measure_per_variable->addVariableDistance(new_pos, distance);
            }
        }
    // updating the configuration
    configuration[new_pos] = new_value;
}

void GolombRulerRelativeCostStructure::init(vector<int> config)
{
    Configuration = config;
    fill(measure_counters.begin(), measure_counters.end(), 0);
    measure_per_variable->clear();
    int penalty = 0, distance = 0;
    CurrentCost = 0;
    for(int i = 0; i < Order - 1; i++)
        for(int j = i + 1; j < Order; j++)
        {
            distance = config[j] - config[i];
            if (distance > 0 && distance <= Length)
            {
                measure_per_variable->addVariableDistance(i, distance);
                measure_per_variable->addVariableDistance(j, distance);
                measure_counters[distance] ++;
            }
        }
    for (int i = 0; i < Length; i++)
        CurrentCost += Tools::zero_bounded_decrease(measure_counters[i]);

    if(config[0] != 0)
        penalty += PENALIZATION;
    if(config[Order - 1] != Length)
        penalty += PENALIZATION;

    CurrentCost += penalty;
}

int GolombRulerRelativeCostStructure::costOnVariable(int index)
{
    // maximum possible measures per variable --> Order - 1
    return (Order - 1) - measure_per_variable->measuresOfVariable(index);
}

void GolombRulerRelativeCostStructure::reset(){}
