#include "multi_sorted_changes_neighborhood.h"
#include "../tools/rand_index_generator.h"
#include "../tools/tools.h"
#include "dStrategy/sorted_apply_change_behavior.h"
#include "dStrategy/elements_change_iterator.h"

#include <algorithm>
#include <iostream>
#include <chrono>

MultiSortedChangesNeighborhood::MultiSortedChangesNeighborhood(std::shared_ptr<Domain> _domain, int _config_size)
    : Neighborhood(_config_size),
      changeAtBhv(std::make_shared<SortedApplyChangeBehavior>(_config_size)),
      domain(_domain)
{}

void MultiSortedChangesNeighborhood::updateChanges(shared_ptr<Randomizer> rand)
{
    changes.clear();
    //int n = current_configuration.size();
    std::vector<vector<int>> the_changes = rand->generate_multichanges();

    //int pos_new_value = 0;

    for (std::vector<std::vector<int>>::iterator it = the_changes.begin(); it != the_changes.end(); ++it)
    {
        std::vector<int> list_of_indexes = (*it);
        pushSetOfValues(rand, list_of_indexes);
    }
}

std::shared_ptr<POSL_Iterator> MultiSortedChangesNeighborhood::getIterator()
{
    return std::make_shared<ElementsChangeIterator>(shared_from_this());
}

void MultiSortedChangesNeighborhood::Init(shared_ptr<PSP> psp, std::vector<int> & _configuration)
{
    std::copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges(psp->GetRandomizer());
}

std::shared_ptr<FactoryPacker> MultiSortedChangesNeighborhood::BuildPacker(){ throw "Not implemented yet"; }

std::vector<int> MultiSortedChangesNeighborhood::neighborAt(int index)
{
    return changeAtBhv->applyChangeAt(index, current_configuration, changes);
}

void MultiSortedChangesNeighborhood::pushSetOfValues(shared_ptr<Randomizer> rand, vector<int> indexes)
{
    int domains_size = domain->maximum(0);
    // <= 16
    int NCh = (domains_size <= 20) ? 1 : sqrt(domains_size);

    std::vector<int> values_for_index;

    // creating the domains
    std::vector<vector<int>> vector_values;
    for (std::vector<int>::iterator it = indexes.begin(); it != indexes.end(); ++it)
    {
        unsigned int index = *it;
        if(index == 0)
        {
            std::vector<int> v(NCh, 0);
            values_for_index = v;
        }
        else if(index == current_configuration.size()-1)
        {
            std::vector<int> v(NCh, current_configuration[current_configuration.size()-1]);
            values_for_index = v;
        }
        else
        {
            values_for_index = domain->GetValues(index);
            rand->vector_shuffle(values_for_index);
        }
        vector_values.push_back(values_for_index);
    }
    std::vector<int> the_values;
    for (int i = 0; i < NCh; i++)
    {
        for (unsigned int j = 0; j < indexes.size(); j++)
            the_values.push_back(vector_values[j][i]);
        T_Changes next_changes = {indexes, the_values, (int)the_values.size()};
        changes.push_back(next_changes);
        the_values.clear();
    }
}
