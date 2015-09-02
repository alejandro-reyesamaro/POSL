#include "one_permutation_neighborhood.h"
#include "dStrategy/elements_change_iterator.h"
#include "dStrategy/neighborhood_packing_strategy.h"
#include "dStrategy/multi_elements_changed_body_packing_strategy.h"
#include "../tools/tools.h"

#include <algorithm>
#include <iostream>
#include <chrono>

OnePermutationNeighborhood::OnePermutationNeighborhood(Solution * sol) : rand()
{
    current_solution = sol;
    vector<int> config = sol->GetConfiguration();
    int n = config.size();
    int n_changes = n/2;

    vector<int> monotony = Tools::generateMonotony(n);
    Tools::shuffle(monotony);

    for(int i = 0; i < n_changes; i++)
    {
        vector<int> new_indexes ({monotony[2*i], monotony[2*1 + 1]});
        vector<int> new_values ({config[monotony[2*1 + 1]], config[monotony[2*i]]});

        T_Nchanges next_changes = {new_indexes, new_values, new_values.size()};
        changes.push_back(next_changes);
    }
    packing_strategy = new NeighborhoodPackingStrategy(sol->GetConfiguration(), size(), new MultiElementsChangedBodyPackingStrategy(changes));
}

POSL_Iterator<vector<int>> * OnePermutationNeighborhood::getIterator()
{
    POSL_Iterator<vector<int>> * iter = new ElementsChangeIterator(this);
    return iter;
}

int OnePermutationNeighborhood::size()
{
    return changes.size();
}

vector<int> OnePermutationNeighborhood::operator[](int index)
{
    return applyChangeAt(index);
}

vector<int> OnePermutationNeighborhood::applyChangeAt(int index)
{
    vector<int> conf = current_solution->GetConfiguration();
    if(index >= size()) return conf;
    for (unsigned int i = 0;  i < changes[index].positions.size(); i++)
        conf[changes[index].positions[i]] = changes[index].new_values[i];
    return conf;
}

vector<int> OnePermutationNeighborhood::pack()
{
    return packing_strategy->pack();
}

int OnePermutationNeighborhood::bodySize()
{
    return packing_strategy->BodySize();
}

vector<int> OnePermutationNeighborhood::body()
{
    return packing_strategy->body();
}
