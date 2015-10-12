#include "golfers_single_swap_neighborhood.h"
#include "../tools/rand_index_generator.h"
#include "../packing/factory/factory_golfers_single_swap_neighborhood_packer.h"
#include "../tools/tools.h"
#include "dStrategy/single_swap_apply_change_behavior.h"
#include "dStrategy/elements_change_iterator.h"

#include <algorithm>
#include <iostream>

using namespace std;

//#define SWAPS 600
#define TP players * groups

GolfersSingleSwapNeighborhood::GolfersSingleSwapNeighborhood(int _config_size, int _players, int _groups)
    : Neighborhood(_config_size),
      changeAtBhv(make_shared<SingleSwapApplyChangeBehavior>(_config_size)),
      players(_players),
      groups(_groups),
      indexes(Tools::generateMonotony(TP)),
      walk_indexes(Tools::generateMonotony(TP))
      //indexes_IG(Tools::generateMonotony(_players)),
      //indexes_IP(Tools::generateMonotony(_players))
{
    updateChanges();
}

void GolfersSingleSwapNeighborhood::updateChanges()
{
    changes.clear();
    int weeks = current_configuration.size() / (players*groups);
    //int posibles = players * (players-1);
    //int swaps = min(SWAPS, posibles);

    /*
    for (int w = 1; w < weeks; w++) // w = 1 porque la primera semana se mantiene igual
    {
        Tools::shuffle(indexes);
        for (int i = 0; i < players - 1; i++)
            for(int j = i + 1; j < players; j++)
            {
                if ( (i+1) * (j+1) > posibles || changes.size() >= swaps)
                    break;
                int pos1 = (w*players) + indexes[i];
                int pos2 = (w*players) + indexes[j];
                T_Changes next_change = { {pos1, pos2}, {current_configuration[pos2], current_configuration[pos1]}, 2};
                changes.push_back(next_change);
            }
    }
    */
    /*
    for (int w = 1; w < weeks; w++) // w = 1 porque la primera semana se mantiene igual
    {
        for (int i = 0; i < players - 1; i++)
        {
            Tools::shuffle(indexes_IG);
            for(int j = 0; j < players - 1; j++)
            {
                Tools::shuffle(indexes_IP);
                int subgroup1 = indexes_IG[i];
                int subgroup2 = indexes_IG[i+1];
                int subplayer1 = indexes_IP[j];
                int subplayer2 = indexes_IP[j+1];
                int pos1 = (TP * w) + subgroup1 * players + subplayer1;
                int pos2 = (TP * w) + subgroup2 * players + subplayer2;

                T_Changes next_change = { {pos1, pos2}, {current_configuration[pos2], current_configuration[pos1]}, 2};
                changes.push_back(next_change);
            }
        }
    }
    */

    for (int w = 1; w < weeks; w++) // w = 1 porque la primera semana se mantiene igual
    {
        srand(time(0));
        for(int i = 0; i < groups; i++)
            random_shuffle(indexes.begin() + i * players, indexes.begin() + (i+1) * players);
        //Tools::shuffle(walk_indexes);

        /*
        for (int i = 0; i < TP - 1; i++)
            for(int j = i + 1; j < TP; j++)
            {
                if (i/players == j/players)
                    continue;
                int pos1 = (w * TP) + indexes[i];
                int pos2 = (w * TP) + indexes[j];
                T_Changes next_change = { {pos1, pos2}, {current_configuration[pos2], current_configuration[pos1]}, 2};
                changes.push_back(next_change);
            }
         */
        for (int i = 0; i < groups - 1; i++)
            for(int j = i + 1; j < groups; j++)
            {
                save_changes(i,j,w);
            }
    }    
}

void GolfersSingleSwapNeighborhood::save_changes(int g1, int g2, int week)
{
    for (int i = 0; i < players/2 + 1; i++)
        for (int j = 0; j < players/2 + 1; j++)
        {
            int pos1 = (week * TP) + indexes[g1 * players + i];
            int pos2 = (week * TP) + indexes[g2 * players + j];
            T_Changes next_change = { {pos1, pos2}, {current_configuration[pos2], current_configuration[pos1]}, 2};
            changes.push_back(next_change);
        }
}

shared_ptr<POSL_Iterator> GolfersSingleSwapNeighborhood::getIterator()
{
    return make_shared<ElementsChangeIterator>(shared_from_this());
}

void GolfersSingleSwapNeighborhood::Init(vector<int> _configuration)
{
    copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges();
}

shared_ptr<FactoryPacker> GolfersSingleSwapNeighborhood::BuildPacker()
{
    return make_shared<FactoryGolfersSingleSwapNeighborhoodPacker>(current_configuration, size(), changes);
}

vector<int> GolfersSingleSwapNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);
}
