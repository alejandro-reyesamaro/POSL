#include "one_sorted_change_neighborhood.h"
#include "dStrategy/elements_change_iterator.h"
#include "dStrategy/neighborhood_packing_strategy.h"
#include "dStrategy/one_element_changed_body_packing_strategy.h"
#include "../tools/tools.h"

#include <algorithm>
#include <chrono>

#define N_NEIGHBORS 16

OneSortedChangeNeighborhood::OneSortedChangeNeighborhood(Solution * sol) : rand()

{
    current_solution = sol;
    int n = sol->GetConfiguration().size();

    vector<int> indexes;
    for (int i = 0; i < n; i++)
        indexes.push_back(i);
    //n = N_NEIGHBORS;
    srand(time(0));
    random_shuffle (indexes.begin(), indexes.end());

    int pos_new_value = 0;
    vector<int> the_configuration = sol->GetConfiguration();

    for(int i = 0; i < n; ++i)
    {
        int current_value = the_configuration[indexes[i]];
        vector<int> posible_values = Tools::vector_possible_values_to_hold_sorted(indexes[i],the_configuration);
        srand(time(0));
        random_shuffle (posible_values.begin(), posible_values.end());
        //vector<int>::iterator p = find (posible_values.begin(), posible_values.end(), current_value);
        //if(p != posible_values.end())
        //    posible_values.erase(p); // BEST to do a swap with the first element
        for (int j = 0; j < posible_values.size() / 2 + 1; j++)
        {
            pos_new_value = rand.NextInt(0, posible_values.size()/2);
            if(posible_values[pos_new_value] == current_value)
                continue;
            T_change next_change = {indexes[i], posible_values[pos_new_value]};
            changes.push_back(next_change);
        }
    }
    packing_strategy = new NeighborhoodPackingStrategy(sol->GetConfiguration(), size(), new OneElementChangedBodyPackingStrategy(changes));
}

POSL_Iterator<vector<int>> * OneSortedChangeNeighborhood::getIterator()
{
    //shared_ptr<POSL_Iterator> iter = make_shared<OneElementChangedIterator>(this);
    POSL_Iterator<vector<int>> * iter = new ElementsChangeIterator(this);
    return iter;
}

int OneSortedChangeNeighborhood::size()
{
    return changes.size();
}

vector<int> OneSortedChangeNeighborhood::operator[](int index)
{
    return applyChangeAt(index);
}

vector<int> OneSortedChangeNeighborhood::applyChangeAt(int index)
{
    vector<int> conf = current_solution->GetConfiguration();
    if(index >= size()) return conf;
    conf[changes[index].pos] = changes[index].new_value;
    return conf;
}

vector<int> OneSortedChangeNeighborhood::pack()
{
    return packing_strategy->pack();
}

int OneSortedChangeNeighborhood::bodySize()
{
    return packing_strategy->BodySize();
}

vector<int> OneSortedChangeNeighborhood::body()
{
    return packing_strategy->body();
}
