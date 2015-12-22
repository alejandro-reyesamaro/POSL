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
#define _TP (_players * _groups)
#define _W (_config_size / _TP)

GolfersAdaptiveSearchNeighborhood::GolfersAdaptiveSearchNeighborhood(shared_ptr<Golfers> _bench,
                                                                     int _config_size,
                                                                     int _players,
                                                                     int _groups)
    : Neighborhood(_config_size),
      benchmark(_bench),
      changeAtBhv(make_shared<SingleSwapApplyChangeBehavior>(_config_size)),
      players(_players),
      groups(_groups),
      weeks(_config_size / _TP),
      w_index(Tools::generateMonotony(1, _W - 1))
{
    updateChanges();
}

void GolfersAdaptiveSearchNeighborhood::updateChanges()
{
    changes.clear();
    //int weeks = current_configuration.size() / (players * groups);
    int bad_variable = benchmark->sickestVariable();

    vector<int>::iterator it;
    size_t pos_bv;
    int g_bv, gw, pl;

    Tools::shuffle(w_index);
    int wi;
    //for (int w = 1; w < weeks; w++) // w = 1 first week remains the same
    for (int w = 0; w < weeks - 1; ++w)
    {
        wi = w_index[w];
        it = find(current_configuration.begin()+(wi * TP), current_configuration.begin()+((wi+1) * TP), bad_variable + 1);
        pos_bv = it - current_configuration.begin();
        g_bv = (pos_bv) / players;
        for(gw = wi * groups; gw < (wi + 1) * groups; gw++)
        {
            if(gw == g_bv) continue;
            for(pl = gw * players; pl < (gw + 1) * players; pl++)
                save_swap(pos_bv, pl);
        }
    }
}

void GolfersAdaptiveSearchNeighborhood::save_swap(int pos1, int pos2)
{
    T_Changes next_change = { { pos1, pos2 }, { current_configuration[pos2], current_configuration[pos1] }, 2};
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
