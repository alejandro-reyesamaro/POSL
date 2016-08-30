#include "as_tournament_partial_neighborhood.h"
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

ASTournamentPartialNeighborhood::ASTournamentPartialNeighborhood(shared_ptr<Benchmark> _bench,
                                                                 int _config_size,
                                                                 int _players,
                                                                 int _groups,
                                                                 int _part)
    : Neighborhood(_config_size),
      benchmark(_bench),
      changeAtBhv(make_shared<SingleSwapApplyChangeBehavior>(_config_size)),
      players(_players),
      groups(_groups),
      periods(_config_size / _TP),
      part(_part),
      weeks_2_swap(Tools::generateMonotony(1,_W-1))
{
}

void ASTournamentPartialNeighborhood::updateChanges(shared_ptr<Randomizer> rand)
{
    changes.clear();
    int bad_variable = benchmark->sickestVariable();

    rand->vector_shuffle(weeks_2_swap);

    vector<int>::iterator it;
    size_t pos_bv;
    int g_bv, gw, pl;
    for (unsigned int w = 0; w < weeks_2_swap.size()/part; w++)
    {
        it = find(current_configuration.begin()+(weeks_2_swap[w] * TP), current_configuration.begin()+((weeks_2_swap[w]+1) * TP), bad_variable + 1);
        pos_bv = it - current_configuration.begin();
        g_bv = (pos_bv) / players;

        for(gw = weeks_2_swap[w] * groups; gw < (weeks_2_swap[w] + 1) * groups; gw++)
        {
            if(gw == g_bv) continue;
            for(pl = gw * players; pl < (gw + 1) * players; pl++)
                save_swap(pos_bv, pl);
        }
    }
}

void ASTournamentPartialNeighborhood::save_swap(int pos1, int pos2)
{
    T_Changes next_change = { { pos1, pos2 }, { current_configuration[pos2], current_configuration[pos1] }, 2};
    changes.push_back(next_change);
}

shared_ptr<POSL_Iterator> ASTournamentPartialNeighborhood::getIterator()
{
    return make_shared<ElementsChangeIterator>(shared_from_this());
}

void ASTournamentPartialNeighborhood::Init(shared_ptr<PSP> psp, std::vector<int> & _configuration)
{
    copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges(psp->GetRandomizer());
}

shared_ptr<FactoryPacker> ASTournamentPartialNeighborhood::BuildPacker()
{
    throw "Not implemented yet";
}

vector<int> ASTournamentPartialNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);
}
