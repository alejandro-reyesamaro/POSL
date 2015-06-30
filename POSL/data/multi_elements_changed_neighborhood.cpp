#include "multi_elements_changed_neighborhood.h"
#include "elements_change_iterator.h"
#include "tools/rand_index_generator.h"

#include <algorithm>
#include <iostream>
#include <chrono>

MultiElementsChangedNeighborhood::MultiElementsChangedNeighborhood(Solution * sol) : rand_generator(chrono::system_clock::now().time_since_epoch().count())
{
    current_solution = sol;
    int n = sol->configuration.size();
    int ch = 0.3 * n; // to chahge ch elements
    int N = 0.5 * n;  // to have N chahges

    RandIndexGenerator rig(n-1, ch);
    vector<vector<int>> the_changes = rig.generate(N);

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

            uniform_int_distribution<int> distribution(0, posible_values.size()-1);
            pos_new_value = distribution(rand_generator);

            new_values.push_back(posible_values[pos_new_value]);
        }

        //cout << "]" << endl;

        T_Nchanges next_changes = {new_indexes, new_values, new_values.size()};
        changes.push_back(next_changes);
    }
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
