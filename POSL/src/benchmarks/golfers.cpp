#include "golfers.h"
#include "../tools/tools.h"
#include "../data/dStrategy/factory_n_int_domain.h"
#include "cost_strategy/golfers_intersections_costs_trategy.h"
#include "cost_strategy/golfers_long_int_cost_strategy.h"
#include "cost_strategy/golfers_3pn_cost_strategy.h"
#include "show_strategy/golfers_default_show_strategy.h"
#include "relative_cost_strategy/golfers_relative_cost_strategy.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

#define PENALIZATION 10
#define TP players * groups

Golfers::Golfers(int g, int p, int w)
    : Benchmark(vector<Domain>(g * p * w, Domain(make_shared<Factory_NIntDomain>(1,p * g))),
                make_shared<GolfersLongIntCostStrategy>(g,p,w),
                make_shared<GolfersRelativeCostStrategy>(g,p,w),
                make_shared<GolfersDefaultShowStrategy>(g,p,w)),
      groups(g),
      players(p),
      weeks(w)//,
      //cc_occurrences(g * p, Occurrences(g * p)),
      //current_cost(0)
{}

/*
int Golfers::relativeSolutionCost(vector<int> _configuration)
{
    int current_value, new_value;
    vector<int> conf(_configuration.size());
    copy(configuration.begin(), configuration.end(), conf.begin());

    int pos_mismatch = 0, pos_relative_mismatch = 0;
    int end_of_the_week;

    pair<vector<int>::iterator,vector<int>::iterator> p;
    vector<int>::iterator pp;
    p = mismatch (configuration.begin(), configuration.end(), conf.begin());

    vector<int> ch_possitions;
    vector<int> ch_values;

    while(p.first != configuration.end())
    {
        pos_mismatch = p.first - configuration.begin();
        current_value = *p.first;
        new_value = *p.second;
        end_of_the_week = ((pos_mismatch / TP) + 1) * TP;
        pp = find(conf.begin() + pos_mismatch, conf.begin() + end_of_the_week, configuration[pos_mismatch]);
        pos_relative_mismatch = pp - configuration.begin();
        ch_possitions.push_back(pos_mismatch);
        ch_values.push_back(conf[pos_mismatch]);
        ch_possitions.push_back(pos_relative_mismatch);
        ch_values.push_back(conf[pos_relative_mismatch]);
        conf[pos_mismatch] = configuration[pos_mismatch];
        conf[pos_relative_mismatch] = configuration[pos_relative_mismatch];
        p = mismatch (configuration.begin(), configuration.end(), conf.begin());
    }
    if(ch_possitions.size() == 0)
        return current_cost;
    else
    {
        T_Changes changes = {ch_possitions, ch_values, ch_possitions.size()};
        return relativeSolutionCost(changes);
    }
}

int Golfers::relativeSolutionCost(T_Changes change)
{
    int w, g, pos1, pos2, value1, value2, j;
    int start_position_group_for_change1, end_group_for_change1;
    int start_position_group_for_change2, end_group_for_change2;

    int current_value_at_pos1, current_value_at_pos2, plays_with_others_in_the_group;

    for(int i = 0; i < change.dim; i = i + 2)
    {
        pos1 = change.positions[i];
        pos2 = change.positions[i+1];
        value1 = change.new_values[i];
        value2 = change.new_values[i+1];

        w = pos1 / TP;
        g = (w % TP) / players;
        start_position_group_for_change1 = w * TP + g * players;
        end_group_for_change1 = w * TP + (g + 1) * players;

        w = pos2 / TP;
        g = (w % TP) / players;
        start_position_group_for_change2 = w * TP + g * players;
        end_group_for_change2 = w * TP + (g + 1) * players;

        for(j = start_position_group_for_change1; j < end_group_for_change1; j++)
        {
            if(j != pos1)
            {
                current_value_at_pos1 = configuration[pos1];
                plays_with_others_in_the_group = cc_occurrences[configuration[j]-1].GetValue(current_value_at_pos1-1);
                current_cost = current_cost - (min(2,plays_with_others_in_the_group) - 1)*2; // plays_with_others_in_the_group no puede ser 0, pues al menos esa vez jugaron

                current_value_at_pos2 = configuration[pos2];
                plays_with_others_in_the_group = cc_occurrences[configuration[j]-1].GetValue(current_value_at_pos2-1);
                current_cost = current_cost + min(1,plays_with_others_in_the_group)*2;
            }
        }

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
    }

    return current_cost;
}

void Golfers::initializeCostData()
{
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
}
*/

string Golfers::showInstance()
{
    string out =  "Golfers: players-" + Tools::int2str(players);
           out += ", groups-" + Tools::int2str(groups);
           out += ", weeks-" + Tools::int2str(weeks) + "\n";
    return out;
}
