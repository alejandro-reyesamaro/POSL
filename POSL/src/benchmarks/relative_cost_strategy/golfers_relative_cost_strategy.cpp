#include "golfers_relative_cost_strategy.h"
#include "../../tools/tools.h"

#include <iostream>
#include <algorithm>
#include <utility>

#define PENALIZATION 10
#define TP (players * groups)
#define T (g * p * w)

using namespace std;

GolfersRelativeCostStrategy::GolfersRelativeCostStrategy(int g, int p, int w)
    : configuration(T,0),
      groups(g),
      players(p),
      weeks(w),
      cc_occurrences(g * p, Occurrences(g * p)),
      current_cost(0)
{
}

void GolfersRelativeCostStrategy::initializeCostData(vector<int> _configuration, int initial_cost)
{
    copy(_configuration.begin(), _configuration.end(), configuration.begin());
    int start_tournament, end_tournament;
    for(int w = 0; w < weeks; w++)
    {
        for(int g = 0; g < groups; g++)
        {
            start_tournament = (w * TP) + (g * players);
            end_tournament   = start_tournament + players;

            for(int i = start_tournament; i < end_tournament; i++)
                for(int j = start_tournament; j < end_tournament; j++)
                    if(i != j)
                        cc_occurrences[configuration[i]-1].IncreaseValue(configuration[j]-1);
        }
    }
    current_cost = initial_cost;
}

void GolfersRelativeCostStrategy::updateConfiguration(T_Changes change)
{
    int pos, value, w, g, j;
    int start_position_group_for_change, end_group_for_change, current_value_at_pos;

    for(int i = 0; i < change.dim; i++)
    {
        pos = change.positions[i];
        value = change.new_values[i];

        w = pos / TP;
        g = (w % TP) / players;
        start_position_group_for_change = w * TP + g * players;
        end_group_for_change = w * TP + (g + 1) * players;

        for(j = start_position_group_for_change; j < end_group_for_change; j++)
        {
            if(j != pos)
            {
                current_value_at_pos = configuration[pos];
                cc_occurrences[configuration[j]-1].DecreaseValue(current_value_at_pos-1);
                cc_occurrences[current_value_at_pos-1].DecreaseValue(configuration[j]-1);

                cc_occurrences[value-1].IncreaseValue(configuration[j]-1);
                cc_occurrences[configuration[j]-1].IncreaseValue(value-1);
            }
        }
    }
}

int GolfersRelativeCostStrategy::relativeSolutionCost(vector<int> _configuration)
{
    T_Changes changes = Tools::GetChanges(configuration, _configuration);
    return relativeSolutionCost(_configuration, changes);
}

int GolfersRelativeCostStrategy::relativeSolutionCost(vector<int> new_config, T_Changes change)
{
    int cost = current_cost;
    int w, g, pos1, value1, j; //pos2, value1, //value2, j;
    int start_position_group_for_change1, end_group_for_change1;
    //int start_position_group_for_change2, end_group_for_change2;

    int current_value_at_pos1, current_value_at_pos2, plays_with_others_in_the_group;

    for(int i = 0; i < change.dim; i++)
    {
        pos1 = change.positions[i];
        //pos2 = change.positions[i+1];
        value1 = change.new_values[i];
        //value2 = change.new_values[i+1];

        w = pos1 / TP;
        g = (pos1 % TP) / players;
        start_position_group_for_change1 = w * TP + g * players;
        end_group_for_change1 = w * TP + (g + 1) * players;
/*
        w = pos2 / TP;
        g = (pos2 % TP) / players;
        start_position_group_for_change2 = w * TP + g * players;
        end_group_for_change2 = w * TP + (g + 1) * players;
*/
        for(j = start_position_group_for_change1; j < end_group_for_change1; j++)
        {
            if(j != pos1)
            {
                // in current
                current_value_at_pos1 = configuration[pos1];
                plays_with_others_in_the_group = cc_occurrences[configuration[j]-1].GetValue(current_value_at_pos1-1);
                cost = cost - (min(2,plays_with_others_in_the_group) - 1)*2; // plays_with_others_in_the_group no puede ser 0, pues al menos esa vez jugaron
                /*
                current_value_at_pos1 = configuration[pos1];
                plays_with_others_in_the_group = cc_occurrences[configuration[j]-1].GetValue(current_value_at_pos1-1);
                cost = cost - (min(2,plays_with_others_in_the_group) - 1)*2; // plays_with_others_in_the_group no puede ser 0, pues al menos esa vez jugaron
                */
                //current_value_at_pos2 = configuration[pos2];
                plays_with_others_in_the_group = cc_occurrences[new_config[j]-1].GetValue(value1-1);
                cost = cost + min(1,plays_with_others_in_the_group)*2;
            }
        }
/*
        for(j = start_position_group_for_change2; j < end_group_for_change2; j++)
        {
            if(j != pos2)
            {
                current_value_at_pos2 = configuration[pos2];
                plays_with_others_in_the_group = cc_occurrences[configuration[j]-1].GetValue(current_value_at_pos2-1);
                current_cost = current_cost - (min(2,plays_with_others_in_the_group) - 1)*2; // plays_with_others_in_the_group no puede ser 0, pues al menos esa vez jugaron

                current_value_at_pos1 = configuration[pos1];
                plays_with_others_in_the_group = cc_occurrences[configuration[j]-1].GetValue(current_value_at_pos1-1);
                current_cost = current_cost + min(1,plays_with_others_in_the_group)*2;
            }
        }
        */
    }

    return cost;
}

