#include "golfers_single_swap_neighborhood.h"
#include "../tools/rand_index_generator.h"
#include "../packing/factory/factory_golfers_single_swap_neighborhood_packer.h"
#include "../tools/tools.h"
#include "dStrategy/single_swap_apply_change_behavior.h"

#include <algorithm>
#include <iostream>

#define SWAPS 600

GolfersSingleSwapNeighborhood::GolfersSingleSwapNeighborhood(int _config_size, int _players)
    : Neighborhood(_config_size),
      changeAtBhv(make_shared<SingleSwapApplyChangeBehavior>(_config_size)),
      players(_players),
      indexes(Tools::generateMonotony(_players))
{
    updateChanges();
}

void GolfersSingleSwapNeighborhood::updateChanges()
{
    changes.clear();
    int weeks = current_configuration.size() / players;
    int posibles = players * (players-1);
    int swaps = min(SWAPS, posibles);

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
}

void GolfersSingleSwapNeighborhood::Init(std::vector<int> _configuration)
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
