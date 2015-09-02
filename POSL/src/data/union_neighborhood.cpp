#include "union_neighborhood.h"
#include "../tools/rand_index_generator.h"
#include "dStrategy/union_iterator.h"
#include <algorithm>
#include <iostream>
#include <chrono>

UnionNeighborhood::UnionNeighborhood(Solution * sol, Neighborhood * v1, Neighborhood * v2)
    : Neighborhood(sol->GetConfiguration()),
      V1(v1), V2(v2)
{}

FactoryPacker * UnionNeighborhood::BuildPacker(){ throw "Not implemented yet"; }

POSL_Iterator<vector<int>> * UnionNeighborhood::getIterator(){ return new UnionIterator(this); }

// OPTIMIZAR : Calcular bien el elemento
vector<int> UnionNeighborhood::neighborAt(int index)
{
    if(index < V1->size())
        return V1->neighborAt(index);
    else
    {
        index = index-V1->size();
        return V2->neighborAt(index);
    }
}
