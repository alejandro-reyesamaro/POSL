#include "golfers_single_swap_neighborhood.h"
#include "../tools/rand_index_generator.h"
#include "../packing/factory/factory_golfers_single_swap_neighborhood_packer.h"
#include "../tools/tools.h"
#include "dStrategy/single_swap_apply_change_behavior.h"
#include "dStrategy/elements_change_iterator.h"

#include <algorithm>
#include <iostream>

using namespace std;

#define TP (players * groups)

GolfersSingleSwapNeighborhood::GolfersSingleSwapNeighborhood(int _config_size, int _players, int _groups)
    : Neighborhood(_config_size),
      changeAtBhv(make_shared<SingleSwapApplyChangeBehavior>(_config_size)),
      players(_players),
      groups(_groups),
      indexes(Tools::generateMonotony(TP)),
      walk_indexes(Tools::generateMonotony(TP))
{}

void GolfersSingleSwapNeighborhood::updateChanges(shared_ptr<Randomizer> rand)
{
    changes.clear();
    int weeks = current_configuration.size() / (players*groups);    

    for (int w = 1; w < weeks; w++) // w = 1 because the first week remains the same
    {
        for(int i = 0; i < groups; i++)
            //random_shuffle(indexes.begin() + i * players, indexes.begin() + (i+1) * players);
            rand->vector_shuffle(indexes, i * players, (i+1) * players);
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

void GolfersSingleSwapNeighborhood::Init(shared_ptr<PSP> psp, vector<int> & _configuration)
{
    copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges(psp->GetRandomizer());
}

shared_ptr<FactoryPacker> GolfersSingleSwapNeighborhood::BuildPacker()
{
    return make_shared<FactoryGolfersSingleSwapNeighborhoodPacker>(current_configuration, size(), changes);
}

vector<int> GolfersSingleSwapNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);
}
