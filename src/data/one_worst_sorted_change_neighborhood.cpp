#include "one_worst_sorted_change_neighborhood.h"
#include "../tools/tools.h"
#include "../tools/golomb_tools.h"
#include "dStrategy/sorted_apply_change_behavior.h"
#include "dStrategy/elements_change_iterator.h"

OneWorstSortedChangeNeighborhood::OneWorstSortedChangeNeighborhood(int _config_size, shared_ptr<Benchmark> _benchmark)
    : Neighborhood(_config_size),
      benchmark(_benchmark),
      changeAtBhv(std::make_shared<SortedApplyChangeBehavior>(_config_size))
{}

shared_ptr<POSL_Iterator> OneWorstSortedChangeNeighborhood::getIterator()
{
    return std::make_shared<ElementsChangeIterator>(shared_from_this());
}

void OneWorstSortedChangeNeighborhood::Init(shared_ptr<PSP> psp, std::vector<int> & _configuration)
{
    copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges(psp->GetRandomizer());
}

void OneWorstSortedChangeNeighborhood::updateChanges(shared_ptr<Randomizer> rand)
{
    changes.clear();
    int worst_variable = benchmark->sickestVariable();

    int current_value = current_configuration[worst_variable];
    vector<int> posible_values = GolombTools::vector_possible_values_to_hold_sorted(worst_variable, current_configuration);
    rand->vector_shuffle(posible_values);
    T_Changes next_change;
    for (unsigned int j = 0; j <  posible_values.size(); j++)
        if(posible_values[j] != current_value)
        {
            next_change = {{worst_variable}, {posible_values[j]}, 1};
            changes.push_back(next_change);
        }
}

shared_ptr<FactoryPacker> OneWorstSortedChangeNeighborhood::BuildPacker(){ throw "Not implemented yet"; }

vector<int> OneWorstSortedChangeNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);
}
