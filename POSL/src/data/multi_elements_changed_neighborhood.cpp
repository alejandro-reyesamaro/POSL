#include "multi_elements_changed_neighborhood.h"
#include "../tools/rand_index_generator.h"
#include "../packing/factory/factory_multi_changes_neighborhood_packer.h"

#include <algorithm>
#include <iostream>
#include <chrono>

#define N_NEIGHBORS 10
#define PRC_CHANGES 0.5

MultiElementsChangedNeighborhood::MultiElementsChangedNeighborhood(Solution * sol)
    : Neighborhood(sol->GetConfiguration()),
      domains(sol->GetDomains()),
      rand()
{
    updateChanges();
}

void MultiElementsChangedNeighborhood::updateChanges()
{
    int n = current_configuration.size();
    int ch = N_NEIGHBORS; // to chahge ch elements
    //int N = PRC_CHANGES * n;  // to have N chahges

    RandIndexGenerator rig(n-1);
    vector<vector<int>> the_changes = rig.generate();

    int pos_new_value = 0;

    for (vector<vector<int>>::iterator it = the_changes.begin(); it != the_changes.end(); ++it)
    {
        vector<int> new_indexes = (*it);
        vector<int> new_values;

        //cout << "[ ";

        for (vector<int>::iterator jt = new_indexes.begin(); jt != new_indexes.end(); ++jt)
        {
            //cout << *jt << " ";

            vector<int> posible_values =domains[*jt].GetValues();
            int current_value = current_configuration[*jt];

            vector<int>::iterator p = find (posible_values.begin(), posible_values.end(), current_value);
            if(p != posible_values.end())
                posible_values.erase(p); // BEST to do a swap with the first element

            pos_new_value = rand.NextInt(0, posible_values.size()-1);
            new_values.push_back(posible_values[pos_new_value]);
        }

        //cout << "]" << endl;

        T_Changes next_changes = {new_indexes, new_values, new_values.size()};
        changes.push_back(next_changes);
    }
}

void MultiElementsChangedNeighborhood::update(vector<int> _configuration)
{
    copy(_configuration.begin(), _configuration.end(), current_configuration.begin());
    updateChanges();
}

FactoryPacker * MultiElementsChangedNeighborhood::BuildPacker()
{
    return new FactoryMultiChangesNeighborhoodPacker(current_configuration, size(), changes);
}

vector<int> MultiElementsChangedNeighborhood::neighborAt(int index){ return applyChangeAt(index); }

vector<int> MultiElementsChangedNeighborhood::applyChangeAt(int index)
{
    if(index >= size()) return current_configuration;
    copy(current_configuration.begin(), current_configuration.end(), configuration_changed.begin());
    for (unsigned int i = 0;  i < changes[index].positions.size(); i++)
        configuration_changed[changes[index].positions[i]] = changes[index].new_values[i];
    return configuration_changed;
}
