#include "multi_elements_changed_neighborhood.h"
#include "dStrategy/elements_change_iterator.h"
#include "tools/rand_index_generator.h"
#include "dStrategy/neighborhood_packing_strategy.h"
#include "dStrategy/multi_elements_changed_body_packing_strategy.h"

#include <algorithm>
#include <iostream>
#include <chrono>

#define N_NEIGHBORS 10
#define PRC_CHANGES 0.5

MultiElementsChangedNeighborhood::MultiElementsChangedNeighborhood(Solution * sol) : rand()
{
    current_solution = sol;
    int n = sol->configuration.size();
    int ch = N_NEIGHBORS; // to chahge ch elements
    int N = PRC_CHANGES * n;  // to have N chahges

    RandIndexGenerator rig(n-1);
    vector<vector<int>> the_changes = rig.generate(ch);

    int pos_new_value = 0;

    for (vector<vector<int>>::iterator it = the_changes.begin(); it != the_changes.end(); ++it)
    {
        vector<int> new_indexes = (*it);
        vector<int> new_values;

        //cout << "[ ";

        for (vector<int>::iterator jt = new_indexes.begin(); jt != new_indexes.end(); ++jt)
        {
            //cout << *jt << " ";

            vector<int> posible_values = sol->domains[*jt].GetValues();
            int current_value = sol->configuration[*jt];

            vector<int>::iterator p = find (posible_values.begin(), posible_values.end(), current_value);
            if(p != posible_values.end())
                posible_values.erase(p); // BEST to do a swap with the first element

            pos_new_value = rand.NextInt(0, posible_values.size()-1);

            new_values.push_back(posible_values[pos_new_value]);
        }

        //cout << "]" << endl;

        T_Nchanges next_changes = {new_indexes, new_values, new_values.size()};
        changes.push_back(next_changes);
    }
    packing_strategy = new NeighborhoodPackingStrategy(sol->configuration, size(), new MultiElementsChangedBodyPackingStrategy(changes));
}

POSL_Iterator<vector<int>> * MultiElementsChangedNeighborhood::getIterator()
{
    POSL_Iterator<vector<int>> * iter = new ElementsChangeIterator(this);
    return iter;
}

int MultiElementsChangedNeighborhood::size()
{
    return changes.size();
}

vector<int> MultiElementsChangedNeighborhood::operator[](int index)
{
    return applyChangeAt(index);
}

vector<int> MultiElementsChangedNeighborhood::applyChangeAt(int index)
{
    vector<int> conf = current_solution->configuration;
    if(index >= size()) return conf;
    for (int i = 0;  i < changes[index].positions.size(); i++)
        conf[changes[index].positions[i]] = changes[index].new_values[i];
    return conf;
}

int * MultiElementsChangedNeighborhood::pack()
{
    return packing_strategy->pack();
}

int MultiElementsChangedNeighborhood::bodySize()
{
    return packing_strategy->BodySize();
}

int * MultiElementsChangedNeighborhood::body()
{
    return packing_strategy->body();
}
