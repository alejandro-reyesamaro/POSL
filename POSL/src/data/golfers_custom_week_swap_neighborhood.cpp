#include "golfers_custom_week_swap_neighborhood.h"
#include "../tools/rand_index_generator.h"
#include "../packing/factory/factory_golfers_single_swap_neighborhood_packer.h"
#include "../tools/tools.h"
#include "dStrategy/single_swap_apply_change_behavior.h"
#include "dStrategy/elements_change_iterator.h"

#include <algorithm>
#include <iostream>

using namespace std;

#define TP (players * groups)

GolfersCustomWeekSwapNeighborhood::GolfersCustomWeekSwapNeighborhood(int _config_size,
                                                                     int _players,
                                                                     int _groups,
                                                                     vector<int> _zero_based_weeks)
    : Neighborhood(_config_size),
      changeAtBhv(make_shared<SingleSwapApplyChangeBehavior>(_config_size)),
      players(_players),
      groups(_groups),
      weeks(_config_size / TP),
      indexes(Tools::generateMonotony(TP)),
      weeks_2_swap(_zero_based_weeks)
{
    normalize_weeks();
}

void GolfersCustomWeekSwapNeighborhood::normalize_weeks()
{
    for(unsigned i = 0; i < weeks_2_swap.size(); i++)
    {
        if(weeks_2_swap[i] < 1) weeks_2_swap[i] = 1;
        if(weeks_2_swap[i] >= weeks) weeks_2_swap[i] = weeks - 1;
    }
}

void GolfersCustomWeekSwapNeighborhood::updateChanges(shared_ptr<Randomizer> rand)
{
    changes.clear();
    for(int i = 0; i < groups; i++)
        //random_shuffle(indexes.begin() + i * players, indexes.begin() + (i+1) * players);
        rand->vector_shuffle(indexes, i * players, (i+1) * players);
    for (unsigned int w = 0; w < weeks_2_swap.size(); w++)
        for (int i = 0; i < groups - 1; i++)
            for(int j = i + 1; j < groups; j++)
                save_changes(i,j,weeks_2_swap[w]);
}

void GolfersCustomWeekSwapNeighborhood::save_changes(int g1, int g2, int week)
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

shared_ptr<POSL_Iterator> GolfersCustomWeekSwapNeighborhood::getIterator()
{
    return make_shared<ElementsChangeIterator>(shared_from_this());
}

void GolfersCustomWeekSwapNeighborhood::Init(shared_ptr<PSP> psp, vector<int> & _configuration)
{
    copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges(psp->GetRandomizer());
}

shared_ptr<FactoryPacker> GolfersCustomWeekSwapNeighborhood::BuildPacker()
{
    return make_shared<FactoryGolfersSingleSwapNeighborhoodPacker>(current_configuration, size(), changes);
}

vector<int> GolfersCustomWeekSwapNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);
}
