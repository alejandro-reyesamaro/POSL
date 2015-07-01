#include "union_iterator.h"

UnionIterator::UnionIterator(UnionNeighborhood * _n) : neighborhood(_n), current(0)
{}

vector<int> UnionIterator::GetNext()
{
    return neighborhood->operator [](current ++);
}

bool UnionIterator::SomeNext()
{
    return current < neighborhood->size();
}

void UnionIterator::Reset()
{
    current = 0;
}
