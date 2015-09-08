#include "elements_change_iterator.h"

ElementsChangeIterator::ElementsChangeIterator(shared_ptr<Neighborhood> _n) : neighborhood(_n), current(0)
{}

vector<int> ElementsChangeIterator::GetNext()
{
    //vector<int> r = neighborhood->neighborAt(current);
    return neighborhood->neighborAt(current ++);
}

bool ElementsChangeIterator::SomeNext()
{
    return current < neighborhood->size();
}

void ElementsChangeIterator::Reset()
{
    current = 0;
}
