#include "one_2d_change_neighborhood.h"
#include "../packing/factory/factory_one_change_neighborhood_packer.h"
#include "../tools/tools.h"
#include "dStrategy/standard_apply_change_behavior.h"
#include "dStrategy/elements_change_iterator.h"

#include <algorithm>

One2DChangeNeighborhood::One2DChangeNeighborhood(shared_ptr<Benchmark> _bench)
    : Neighborhood(_bench->Dimension()),
      changeAtBhv(std::make_shared<StandardApplyChangeBehavior>(_bench->Dimension())),
      benchmark(_bench)
{}

void One2DChangeNeighborhood::Init(shared_ptr<PSP> psp, std::vector<int> & _configuration)
{
    copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges(psp->GetRandomizer());
}

std::shared_ptr<POSL_Iterator> One2DChangeNeighborhood::getIterator()
{
    return std::make_shared<ElementsChangeIterator>(shared_from_this());
}

void One2DChangeNeighborhood::updateChanges(shared_ptr<Randomizer> rand)
{
    changes.clear();
    int one_D_dim = current_configuration.size() / 2;
    int bad_variable = benchmark->sickestVariable();
    std::vector<int> possible_values_d1 = benchmark->Variable_Domain()->GetValues(bad_variable);
    std::vector<int> possible_values_d2 = benchmark->Variable_Domain()->GetValues(bad_variable + one_D_dim);
    rand->vector_shuffle(possible_values_d1);
    rand->vector_shuffle(possible_values_d2);
    int current_value_d1 = current_configuration[bad_variable];
    int current_value_d2 = current_configuration[bad_variable + one_D_dim];

    //int min_possible_values_sizes = min(possible_values_d1.size(), possible_values_d1.size());

    int new_value_d1, new_value_d2;
    for (unsigned int i = 0; i < possible_values_d1.size(); i++)
        for (unsigned int j = 0; j < possible_values_d2.size(); j++)
        {
            new_value_d1 = possible_values_d1[i];
            new_value_d2 = possible_values_d1[j];
            if(new_value_d1 != current_value_d1 || new_value_d2 != current_value_d2)
            {
                T_Changes next_change = {{bad_variable, bad_variable + one_D_dim}, {new_value_d1, new_value_d2}, 2};
                changes.push_back(next_change);
            }
        }
}

std::shared_ptr<FactoryPacker> One2DChangeNeighborhood::BuildPacker()
{
    return std::make_shared<FactoryOneChangeNeighborhoodPacker>(current_configuration, size(), changes);
}

std::vector<int> One2DChangeNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);
}
