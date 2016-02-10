#include "golfers_adaptive_search_single_week_neighborhood.h"
#include "../tools/rand_index_generator.h"
#include "../tools/tools.h"
#include "dStrategy/single_swap_apply_change_behavior.h"
#include "dStrategy/elements_change_iterator.h"

#include <algorithm>
#include <iostream>

using namespace std;

#define TP (players * groups)
#define _TP (_players * _groups)
#define _W (_config_size / _TP)

int GolfersAdaptiveSearchSingleWeekNeighborhood::init_weeks(int _week)
{
    int weeks = current_configuration.size() / (players*groups);
    if(_week < 1) return 1;
    if(_week >= weeks) return weeks - 1;
    return _week;
}

GolfersAdaptiveSearchSingleWeekNeighborhood::GolfersAdaptiveSearchSingleWeekNeighborhood(shared_ptr<Golfers> _bench,
                                                                                         int _config_size,
                                                                                         int _players,
                                                                                         int _groups,
                                                                                         int _zero_based_week_2_swap)
    : Neighborhood(_config_size),
      benchmark(_bench),
      changeAtBhv(make_shared<SingleSwapApplyChangeBehavior>(_config_size)),
      players(_players),
      groups(_groups),
      weeks(_config_size / _TP),
      week_2_swap(init_weeks(_zero_based_week_2_swap))
{
}

void GolfersAdaptiveSearchSingleWeekNeighborhood::SetSeed(std::shared_ptr<Seed> _seed)
{
    if(!my_seed)
        my_seed = _seed;
}

void GolfersAdaptiveSearchSingleWeekNeighborhood::updateChanges()
{
    changes.clear();
    int bad_variable = benchmark->sickestVariable();

    vector<int>::iterator it;
    size_t pos_bv;
    int g_bv, gw, pl;
    //int wi;
    //for (int w = 1; w < weeks; w++) // w = 1 first week remains the same
    //for (int w = 0; w < weeks - 1; ++w)
    //{
        //wi = w_index[w];
        it = find(current_configuration.begin()+(week_2_swap * TP), current_configuration.begin()+((week_2_swap+1) * TP), bad_variable + 1);
        pos_bv = it - current_configuration.begin();
        g_bv = (pos_bv) / players;
        for(gw = week_2_swap * groups; gw < (week_2_swap + 1) * groups; gw++)
        {
            if(gw == g_bv) continue;
            for(pl = gw * players; pl < (gw + 1) * players; pl++)
                save_swap(pos_bv, pl);
        }
    //}
}

void GolfersAdaptiveSearchSingleWeekNeighborhood::save_swap(int pos1, int pos2)
{
    T_Changes next_change = { { pos1, pos2 }, { current_configuration[pos2], current_configuration[pos1] }, 2};
    changes.push_back(next_change);
}

shared_ptr<POSL_Iterator> GolfersAdaptiveSearchSingleWeekNeighborhood::getIterator()
{
    return make_shared<ElementsChangeIterator>(shared_from_this());
}

void GolfersAdaptiveSearchSingleWeekNeighborhood::Init(vector<int> _configuration)
{
    copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges();
}

shared_ptr<FactoryPacker> GolfersAdaptiveSearchSingleWeekNeighborhood::BuildPacker()
{
    throw "Not implemented yet";
}

vector<int> GolfersAdaptiveSearchSingleWeekNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);
}
