#include "multi_sorted_changes_neighborhood.h"
#include "../tools/rand_index_generator.h"
#include "../tools/tools.h"

#include <algorithm>
#include <iostream>
#include <chrono>

MultiSortedChangesNeighborhood::MultiSortedChangesNeighborhood(Solution * sol)
    : Neighborhood(sol->GetConfiguration()),
      rand()
{
    int n = sol->GetConfiguration().size();
    //int N = PRC_CHANGES * n;  // to have N chahges

    RandIndexGenerator rig(n-1);
    vector<vector<int>> the_changes = rig.generate();

    //int pos_new_value = 0;

    for (vector<vector<int>>::iterator it = the_changes.begin(); it != the_changes.end(); ++it)
    {
        vector<int> list_of_indexes = (*it);
        pushSetOfValues(list_of_indexes, sol);
    }
}

FactoryPacker * MultiSortedChangesNeighborhood::BuildPacker(){ throw "Not implemented yet"; }

vector<int> MultiSortedChangesNeighborhood::neighborAt(int index){ return applyChangeAt(index); }

vector<int> MultiSortedChangesNeighborhood::applyChangeAt(int index)
{
    if(index >= size()) return current_configuration;
    copy(current_configuration.begin(), current_configuration.end(), configuration_changed.begin());
    for (unsigned int i = 0;  i < changes[index].positions.size(); i++)
        configuration_changed[changes[index].positions[i]] = changes[index].new_values[i];
    sort(configuration_changed.begin(), configuration_changed.end());
    return configuration_changed;
}

void MultiSortedChangesNeighborhood::pushSetOfValues(vector<int> indexes, Solution * sol)
{
    //changes.clear();
    vector<int> config = sol->GetConfiguration();
    vector<Domain> domains = sol->GetDomains();
    int domains_size = domains[0].maximum();
    // <= 16
    int NCh = (domains_size <= 20) ? 1 : sqrt(domains_size);

    vector<int> values_for_index;

    // creating the domains
    vector<vector<int>> vector_values;
    for (vector<int>::iterator it = indexes.begin(); it != indexes.end(); ++it)
    {
        unsigned int index = *it;
        if(index == 0)
        {

            vector<int> v(NCh, 0);
            values_for_index = v;
        }
        else if(index == config.size()-1)
        {
            vector<int> v(NCh, config[config.size()-1]);
            values_for_index = v;
        }
        else
        {
            values_for_index = domains[index].GetValues();
            Tools::shuffle(values_for_index);
        }
        vector_values.push_back(values_for_index);
    }
    vector<int> the_values;
    for (int i = 0; i < NCh; i++)
    {
        for (unsigned int j = 0; j < indexes.size(); j++)
            the_values.push_back(vector_values[j][i]);
        T_Nchanges next_changes = {indexes, the_values, the_values.size()};
        changes.push_back(next_changes);
        the_values.clear();
    }
}
