#include "subsum_single_permitation_neighborhood.h"
#include "../tools/rand_index_generator.h"
#include "../packing/factory/factory_golfers_single_swap_neighborhood_packer.h"
#include "../tools/tools.h"
#include "dStrategy/single_swap_apply_change_behavior.h"
#include "dStrategy/elements_change_iterator.h"

#include <algorithm>
#include <iostream>

using namespace std;

SubsumSinglePermitationNeighborhood::SubsumSinglePermitationNeighborhood(int _set_length, int _subsum_length)
    : Neighborhood(_set_length),
      changeAtBhv(make_shared<SingleSwapApplyChangeBehavior>(_set_length)),
      set_length(_set_length),
      subsum_length(_subsum_length),
      subsum_valid_index(Tools::generateMonotony(_subsum_length)),
      not_valid_index(Tools::generateMonotony(_subsum_length, _set_length-1))
{}

void SubsumSinglePermitationNeighborhood::updateChanges(shared_ptr<Randomizer> rand)
{
    changes.clear();
    rand->vector_shuffle(subsum_valid_index);
    rand->vector_shuffle(not_valid_index);
    T_Changes next_change;
    //for (unsigned int vi = 0; vi < subsum_valid_index.size(); vi++)
    int vi = rand->NextInt(0, subsum_valid_index.size());
        for(unsigned int nvi = 0; nvi < not_valid_index.size(); nvi++)
        {
            next_change = { {subsum_valid_index[vi], not_valid_index[nvi]},
                            {current_configuration[not_valid_index[nvi]], current_configuration[subsum_valid_index[vi]]},
                            2};
            changes.push_back(next_change);
        }
}

shared_ptr<POSL_Iterator> SubsumSinglePermitationNeighborhood::getIterator()
{
    return make_shared<ElementsChangeIterator>(shared_from_this());
}

void SubsumSinglePermitationNeighborhood::Init(shared_ptr<PSP> psp, vector<int> & _configuration)
{
    copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges(psp->GetRandomizer());
}

shared_ptr<FactoryPacker> SubsumSinglePermitationNeighborhood::BuildPacker()
{
    return make_shared<FactoryGolfersSingleSwapNeighborhoodPacker>(current_configuration, size(), changes);
}

vector<int> SubsumSinglePermitationNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);
}
