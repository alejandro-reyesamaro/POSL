#include "one_element_changed_neighborhood.h"

#include <algorithm>
#include <random>
#include <chrono>

class OneElementChangedIterator : public POSL_Iterator<vector<int>>
{
    public:

        //OneElementChangedIterator(shared_ptr<OneElementChangedNeighborhood> _n) : neighborhood(_n){}
        OneElementChangedIterator(OneElementChangedNeighborhood * _n) : neighborhood(_n), current(0){}

        vector<int> GetNext()
        { return neighborhood->applyChangeAt(current ++); }

        bool SomeNext()
        { return current < neighborhood->size(); }

        void Reset()
        { current = 0; }

    private:
        //shared_ptr<OneElementChangedNeighborhood> neighborhood;
        OneElementChangedNeighborhood * neighborhood;
        int current;
};

OneElementChangedNeighborhood::OneElementChangedNeighborhood(shared_ptr<Solution> sol)
{
    current_solution = sol;
    int n = sol->configuration.size();
    double seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);

    vector<int> indexes;
    for (int i = 0; i < n; i++)
        indexes.push_back(i);
    n = 0.3 * n;
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
        pos_new_value = distribution(generator);
        T_change next_change = {indexes[i], posible_values[pos_new_value]};
        changes.push_back(next_change);
    }
}

POSL_Iterator<vector<int>> *OneElementChangedNeighborhood::getIterator()
{
    //shared_ptr<POSL_Iterator> iter = make_shared<OneElementChangedIterator>(this);
    POSL_Iterator<vector<int>> * iter = new OneElementChangedIterator(this);
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

