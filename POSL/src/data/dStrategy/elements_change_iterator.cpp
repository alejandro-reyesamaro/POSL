#include "elements_change_iterator.h"

ElementsChangeIterator::ElementsChangeIterator(std::shared_ptr<Neighborhood> _n)
    : neighborhood(_n),
      current(0)
{}

std::vector<int> ElementsChangeIterator::GetNext()
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
