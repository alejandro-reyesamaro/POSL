#include "union_neighborhood.h"
#include "dStrategy/union_iterator.h"
#include "tools/rand_index_generator.h"

#include <algorithm>
#include <iostream>
#include <chrono>

UnionNeighborhood::UnionNeighborhood(Neighborhood * v1, Neighborhood * v2) : V1(v1), V2(v2)
{}

POSL_Iterator<vector<int>> * UnionNeighborhood::getIterator()
{
    POSL_Iterator<vector<int>> * iter = new UnionIterator(this);
    return iter;
}

// OPTIMIZAR : calcular bien la cantidad
int UnionNeighborhood::size()
{
    return V1->size() + V2->size();
}

// OPTIMIZAR : Calcular bien el elemento
vector<int> UnionNeighborhood::operator[](int index)
{
    if(index < V1->size())
        return V1->operator [](index);
    else
    {
        index = index-V1->size();
        return V2->operator [](index);
    }
}
