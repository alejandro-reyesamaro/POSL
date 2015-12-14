#include "golfers_adaptive_search_neighborhood.h"
#include "../tools/rand_index_generator.h"
#include "../packing/factory/factory_golfers_single_swap_neighborhood_packer.h"
#include "../tools/tools.h"
#include "dStrategy/single_swap_apply_change_behavior.h"
#include "dStrategy/elements_change_iterator.h"

#include <algorithm>
#include <iostream>

using namespace std;

#define TP (players * groups)

GolfersAdaptiveSearchNeighborhood::GolfersAdaptiveSearchNeighborhood(shared_ptr<Golfers> _bench,
                                                                     int _config_size,
                                                                     int _players,
                                                                     int _groups)
    : Neighborhood(_config_size),
      benchmark(_bench),
      changeAtBhv(make_shared<SingleSwapApplyChangeBehavior>(_config_size)),
      players(_players),
      groups(_groups),
      //indexes(Tools::generateMonotony(TP)),
      //walk_indexes(Tools::generateMonotony(TP)),
      bad_variables(TP)
{
    updateChanges();
}

void GolfersAdaptiveSearchNeighborhood::updateChanges()
{
    changes.clear();
    bad_variables.clear();
    int weeks = current_configuration.size() / (players*groups);

    int cov;
    int bcov = benchmark->costOnVariable(0);
    bad_variables.pushBack(0);
    for(int i = 1; i < TP; i++)
    {
        cov = benchmark->costOnVariable(i);
        if (cov == bcov)
            bad_variables.pushBack(i);
        else if(cov > bcov)
        {
            bcov = cov;
            bad_variables.clear();
            bad_variables.pushBack(i);
        }
    }

    int bad_variable = bad_variables.elementAt(rand.NextInt(0, bad_variables.size()-1));
    vector<int>::iterator it;
    size_t pos_bv;
    int g_bv, gw, pl;

    for (int w = 1; w < weeks; w++) // w = 1 first week remains the same
    {
        it = find(current_configuration.begin()+(w * TP), current_configuration.begin()+((w+1) * TP), bad_variable + 1);
        pos_bv = it - current_configuration.begin();
        g_bv = (pos_bv) / players;
        for(gw = w * groups; gw < (w + 1) * groups; gw++)
        {
            if(gw == g_bv) continue;
            for(pl = gw * players; pl < (gw + 1) * players; pl++)
                save_change(pos_bv, pl);
        }
    }
}

void GolfersAdaptiveSearchNeighborhood::save_change(int pos1, int pos2)
{
    T_Changes next_change = { {pos1, pos2}, {current_configuration[pos2], current_configuration[pos1]}, 2};
    changes.push_back(next_change);
}

shared_ptr<POSL_Iterator> GolfersAdaptiveSearchNeighborhood::getIterator()
{
    return make_shared<ElementsChangeIterator>(shared_from_this());
}

void GolfersAdaptiveSearchNeighborhood::Init(vector<int> _configuration)
{
    copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges();
}

shared_ptr<FactoryPacker> GolfersAdaptiveSearchNeighborhood::BuildPacker()
{
    throw "Not implemented yet";
}

vector<int> GolfersAdaptiveSearchNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);
}
