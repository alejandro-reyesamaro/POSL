#include "elements_change_iterator.h"

ElementsChangeIterator::ElementsChangeIterator(Neighborhood * _n) : neighborhood(_n), current(0)
{}

vector<int> ElementsChangeIterator::GetNext()
{
    return neighborhood->operator [](current ++);
}

bool ElementsChangeIterator::SomeNext()
{
    return current < neighborhood->size();
}

void ElementsChangeIterator::Reset()
{
    current = 0;
}
