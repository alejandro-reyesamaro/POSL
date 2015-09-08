#include "union_iterator.h"

UnionIterator::UnionIterator(shared_ptr<UnionNeighborhood> _n)
    : neighborhood(_n), current(0)
{}

vector<int> UnionIterator::GetNext()
{
    return neighborhood->neighborAt(current ++);
}

bool UnionIterator::SomeNext()
{
    return current < neighborhood->size();
}

void UnionIterator::Reset()
{
    current = 0;
}
