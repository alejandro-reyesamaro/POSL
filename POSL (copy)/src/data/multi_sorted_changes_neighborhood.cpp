#include "multi_sorted_changes_neighborhood.h"
#include "dStrategy/elements_change_iterator.h"
#include "../tools/rand_index_generator.h"
#include "../tools/tools.h"

#include "dStrategy/neighborhood_packing_strategy.h"
#include "dStrategy/multi_elements_changed_body_packing_strategy.h"

#include <algorithm>
#include <iostream>
#include <chrono>

MultiSortedChangesNeighborhood::MultiSortedChangesNeighborhood(Solution * sol) : rand()
{
    current_solution = sol;
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
    packing_strategy = new NeighborhoodPackingStrategy(sol->GetConfiguration(), size(), new MultiElementsChangedBodyPackingStrategy(changes));
}

POSL_Iterator<vector<int>> * MultiSortedChangesNeighborhood::getIterator()
{
    POSL_Iterator<vector<int>> * iter = new ElementsChangeIterator(this);
    return iter;
}

int MultiSortedChangesNeighborhood::size()
{
    return changes.size();
}

vector<int> MultiSortedChangesNeighborhood::operator[](int index)
{
    return applyChangeAt(index);
}

vector<int> MultiSortedChangesNeighborhood::applyChangeAt(int index)
{
    vector<int> conf = current_solution->GetConfiguration();
    if(index >= size()) return conf;
    for (unsigned int i = 0;  i < changes[index].positions.size(); i++)
        conf[changes[index].positions[i]] = changes[index].new_values[i];

    sort(conf.begin(), conf.end());

    return conf;
}

vector<int> MultiSortedChangesNeighborhood::pack()
{
    return packing_strategy->pack();
}

int MultiSortedChangesNeighborhood::bodySize()
{
    return packing_strategy->BodySize();
}

vector<int> MultiSortedChangesNeighborhood::body()
{
    return packing_strategy->body();
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
    srand(time(0));
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
            random_shuffle (values_for_index.begin(), values_for_index.end());
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
