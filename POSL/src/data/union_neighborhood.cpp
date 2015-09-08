#include "union_neighborhood.h"
#include "../tools/rand_index_generator.h"
#include "dStrategy/union_iterator.h"
#include <algorithm>
#include <iostream>
#include <chrono>

UnionNeighborhood::UnionNeighborhood(shared_ptr<Solution> sol, shared_ptr<Neighborhood> v1, shared_ptr<Neighborhood> v2)
    : Neighborhood(sol->GetConfiguration()),
      V1(v1), V2(v2)
{}

shared_ptr<FactoryPacker> UnionNeighborhood::BuildPacker(){ throw "Not implemented yet"; }

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
