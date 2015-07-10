#include "golfers_single_swap_neighborhood.h"
#include "dStrategy/elements_change_iterator.h"
#include "tools/rand_index_generator.h"

#include <algorithm>
#include <iostream>

GolfersSingleSwapNeighborhood::GolfersSingleSwapNeighborhood(Solution * sol, int _players) : players(_players)
{
    current_solution = sol;
    int weeks = sol->configuration.size() / players;
    int swaps = players / 2;
    vector<int> indexes;
    for(int i = 0; i < players; i++)
        indexes.push_back(i);
    for (int w = 0; w < weeks; w++)
    {
        random_shuffle(indexes.begin(), indexes.end());
        for (int i = 0; i < swaps; i++)
        {
            T_SwapChanges next_change = { (w*players) + indexes[2*i], (w*players) + indexes[2*i+1]};
            changes.push_back(next_change);
        }
    }
}

POSL_Iterator<vector<int>> * GolfersSingleSwapNeighborhood::getIterator()
{
    POSL_Iterator<vector<int>> * iter = new ElementsChangeIterator(this);
    return iter;
}

int GolfersSingleSwapNeighborhood::size()
{
    return changes.size();
}

vector<int> GolfersSingleSwapNeighborhood::operator[](int index)
{
    return applyChangeAt(index);
}

vector<int> GolfersSingleSwapNeighborhood::applyChangeAt(int index)
{
    vector<int> conf = current_solution->configuration;
    if(index >= size()) return conf;
    swap(conf[changes[index].pos1],conf[changes[index].pos2]);
    return conf;
}
