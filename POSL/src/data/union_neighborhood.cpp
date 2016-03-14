#include "union_neighborhood.h"
#include "../tools/rand_index_generator.h"
#include "dStrategy/union_iterator.h"
#include <algorithm>
#include <iostream>
#include <chrono>

using namespace std;

UnionNeighborhood::UnionNeighborhood(shared_ptr<Solution> sol, shared_ptr<Neighborhood> v1, shared_ptr<Neighborhood> v2)
    : Neighborhood(sol->get_conf_by_copy()),
      V1(v1), V2(v2)
{}

shared_ptr<FactoryPacker> UnionNeighborhood::BuildPacker(){ throw "Not implemented yet"; }

std::shared_ptr<POSL_Iterator> UnionNeighborhood::getIterator()
{
    return make_shared<UnionIterator>(shared_from_this());
}

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
