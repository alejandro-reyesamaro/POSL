#include "golfers_relative_cost_strategy.h"
#include "../../tools/tools.h"

#include <iostream>
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
      cc_occurrences(g * p),
      current_cost(0),
      bad_variables(TP)
{}

void GolfersRelativeCostStrategy::initializeCostData(vector<int> _configuration, int initial_cost)
{
    copy(_configuration.begin(), _configuration.end(), configuration.begin());
    int start_tournament, end_tournament;
    current_cost = 0;
    cc_occurrences.clear();
    for(int w = 0; w < weeks; w++)
    {
        for(int g = 0; g < groups; g++)
        {
            start_tournament = (w * TP) + (g * players);
            end_tournament   = start_tournament + players;

            for(int i = start_tournament; i < end_tournament - 1; i++)
                for(int j = i + 1; j < end_tournament; j++)
                {
                    current_cost += cc_occurrences.add_connection(configuration[i], configuration[j], true);
                    //current_cost += cc_occurrences.projected_cost(configuration[i], configuration[j]);
                }
        }
    }
    current_cost = initial_cost;
}

int GolfersRelativeCostStrategy::relative_cost(std::vector<int> new_config, T_Changes change, bool updating)
{
    int cost = 0;
    int pos, new_value, w, g, j;
    int start_position_group_for_change, end_group_for_change;
    int current_player_at_pos, partner_current_group, partner_new_group;

    for(unsigned int i = 0; i < change.dim; i++)
    {
        pos = change.positions[i];
        new_value = change.new_values[i];

        w = pos / TP;
        g = (pos % TP) / players;
        start_position_group_for_change = w * TP + g * players;
        end_group_for_change = w * TP + (g + 1) * players;

        for(j = start_position_group_for_change; j < end_group_for_change; j++)
        {
            if(j != pos)
            {
                current_player_at_pos = configuration[pos];
                partner_current_group = configuration[j];
                partner_new_group = new_config[j];

                cost += cc_occurrences.remove_connection(current_player_at_pos, partner_current_group, updating);
                cost += cc_occurrences.add_connection(new_value, partner_new_group, updating);
            }
        }
    }
    return cost;
}

void GolfersRelativeCostStrategy::updateConfiguration(vector<int> new_config)
{
    T_Changes changes = Tools::GetChanges(configuration, new_config);
    if(changes.dim > 0)
    {
        current_cost += relative_cost(new_config, changes, true);
        copy(new_config.begin(), new_config.end(), configuration.begin());
    }

}

int GolfersRelativeCostStrategy::relativeSolutionCost(vector<int> _configuration)
{
    T_Changes changes = Tools::GetChanges(configuration, _configuration);
    return relativeSolutionCost(_configuration, changes);
}

int GolfersRelativeCostStrategy::relativeSolutionCost(vector<int> new_config, T_Changes changes)
{
    return current_cost + relative_cost(new_config, changes, false);
}

int GolfersRelativeCostStrategy::costOnVariable(int variable_index)
{
    return cc_occurrences.ranking_cost_of_variable(variable_index);
}


///
/// \brief Returns just the worst player
///
int GolfersRelativeCostStrategy::sickestVariable()
{
    bad_variables.clear();
    int cov;
    int bcov = costOnVariable(0);
    bad_variables.pushBack(0);
    for(int i = 1; i < groups * players; i++)
    {
        cov = costOnVariable(i);
        if (cov == bcov)
            bad_variables.pushBack(i);
        else if(cov > bcov)
        {
            bcov = cov;
            bad_variables.clear();
            bad_variables.pushBack(i);
        }
    }

    return bad_variables.elementAt(rand.NextInt(0, bad_variables.size()-1));
}
