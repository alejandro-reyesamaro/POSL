#include "golfers_single_swap_neighborhood.h"
#include "../tools/rand_index_generator.h"
#include "../packing/factory/factory_golfers_single_swap_neighborhood_packer.h"
#include "../tools/tools.h"

#include <algorithm>
#include <iostream>

#define SWAPS 600

GolfersSingleSwapNeighborhood::GolfersSingleSwapNeighborhood(Solution * sol, int _players)
    : Neighborhood(sol->GetConfiguration()),
      players(_players),
      indexes(Tools::generateMonotony(_players))
{
    updateChanges();
}

void GolfersSingleSwapNeighborhood::updateChanges()
{
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
                T_SwapChanges next_change = { (w*players) + indexes[i], (w*players) + indexes[j]};
                changes.push_back(next_change);
            }
    }
}

void GolfersSingleSwapNeighborhood::update(std::vector<int> _configuration)
{
    copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges();
}

FactoryPacker * GolfersSingleSwapNeighborhood::BuildPacker()
{
    return new FactoryGolfersSingleSwapNeighborhoodPacker(current_configuration, size(), changes);
}

vector<int> GolfersSingleSwapNeighborhood::neighborAt(int index){ return applyChangeAt(index); }

vector<int> GolfersSingleSwapNeighborhood::applyChangeAt(int index)
{
    if(index >= size()) return current_configuration;
    copy(current_configuration.begin(), current_configuration.end(), configuration_changed.begin());
    swap(configuration_changed[changes[index].pos1],configuration_changed[changes[index].pos2]);
    return configuration_changed;
}
