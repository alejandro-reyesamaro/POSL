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

    int pos_new_value = 0;

    for (vector<vector<int>>::iterator it = the_changes.begin(); it != the_changes.end(); ++it)
    {
        vector<int> new_indexes = (*it);
        vector<int> new_values;

        //cout << "[ ";

        vector<int> the_configuration = sol->GetConfiguration();

        for (vector<int>::iterator jt = new_indexes.begin(); jt != new_indexes.end(); ++jt)
        {
            //cout << *jt << " ";
            vector<int> posible_values = Tools::vector_possible_values_to_hold_sorted(*jt,the_configuration);
            int current_value = the_configuration[*jt];

            vector<int>::iterator p = find (posible_values.begin(), posible_values.end(), current_value);
            if(p != posible_values.end() && posible_values.size() > 1)
                posible_values.erase(p); // BEST to do a swap with the first element

            pos_new_value = rand.NextInt(0, posible_values.size()-1);

            new_values.push_back(posible_values[pos_new_value]);

            //apply the last change
            the_configuration[*jt] = posible_values[pos_new_value];
        }

        //cout << "]" << endl;

        T_Nchanges next_changes = {new_indexes, new_values, new_values.size()};
        changes.push_back(next_changes);
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
