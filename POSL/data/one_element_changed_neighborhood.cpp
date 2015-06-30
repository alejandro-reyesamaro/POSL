#include "one_element_changed_neighborhood.h"
#include "elements_change_iterator.h"

#include <algorithm>
#include <chrono>

OneElementChangedNeighborhood::OneElementChangedNeighborhood(Solution * sol) : rand_generator(chrono::system_clock::now().time_since_epoch().count())
{
    current_solution = sol;
    int n = sol->configuration.size();

    vector<int> indexes;
    for (int i = 0; i < n; i++)
        indexes.push_back(i);
    n = 0.5 * n;
    random_shuffle (indexes.begin(), indexes.end());

    int pos_new_value = 0;

    for(int i = 0; i < n; ++i)
    {
        vector<int> posible_values = sol->domains[indexes[i]].GetValues();
        int current_value = sol->configuration[indexes[i]];

        vector<int>::iterator p = find (posible_values.begin(), posible_values.end(), current_value);
        if(p != posible_values.end())
            posible_values.erase(p); // BEST to do a swap with the first element
        uniform_int_distribution<int> distribution(0, posible_values.size()-1);
        pos_new_value = distribution(rand_generator);
        T_change next_change = {indexes[i], posible_values[pos_new_value]};
        changes.push_back(next_change);
    }
}

POSL_Iterator<vector<int>> * OneElementChangedNeighborhood::getIterator()
{
    //shared_ptr<POSL_Iterator> iter = make_shared<OneElementChangedIterator>(this);
    POSL_Iterator<vector<int>> * iter = new ElementsChangeIterator(this);
    return iter;
}

int OneElementChangedNeighborhood::size()
{
    return changes.size();
}

vector<int> OneElementChangedNeighborhood::operator[](int index)
{
    return applyChangeAt(index);
}

vector<int> OneElementChangedNeighborhood::applyChangeAt(int index)
{
    vector<int> conf = current_solution->configuration;
    if(index >= size()) return conf;
    conf[changes[index].pos] = changes[index].new_value;
    return conf;
}

