#include "one_permutation_neighborhood.h"
#include "dStrategy/elements_change_iterator.h"
#include "../tools/tools.h"

#include <algorithm>
#include <iostream>
#include <chrono>

OnePermutationNeighborhood::OnePermutationNeighborhood(Solution * sol)
    : Neighborhood(sol->GetConfiguration()),
      monotony(Tools::generateMonotony(sol->GetConfiguration().size()))
{
    updateChanges();
}

void OnePermutationNeighborhood::update(vector<int> _configuration)
{
    copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges();
}

void OnePermutationNeighborhood::updateChanges()
{
    int n = current_configuration.size();
    int n_changes = n/2;

    Tools::shuffle(monotony);

    for(int i = 0; i < n_changes; i++)
    {
        vector<int> new_indexes ({monotony[2*i], monotony[2*1 + 1]});
        vector<int> new_values ({current_configuration[monotony[2*1 + 1]], current_configuration[monotony[2*i]]});

        T_Nchanges next_changes = {new_indexes, new_values, new_values.size()};
        changes.push_back(next_changes);
    }
}

FactoryPacker * OnePermutationNeighborhood::BuildPacker(){ throw "Not implemented yet"; }

vector<int> OnePermutationNeighborhood::neighborAt(int index){ return applyChangeAt(index); }

vector<int> OnePermutationNeighborhood::applyChangeAt(int index)
{
    if(index >= size()) return current_configuration;
    copy(current_configuration.begin(), current_configuration.end(), configuration_changed.begin());
    for (unsigned int i = 0;  i < changes[index].positions.size(); i++)
        configuration_changed[changes[index].positions[i]] = changes[index].new_values[i];
    return configuration_changed;
}
