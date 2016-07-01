#include "list_iterator.h"

ListIterator::ListIterator(std::list<std::vector<int>> & _list)
    : list(_list),
      current(_list.begin()),
      current_index(0)
{}

std::vector<int> ListIterator::GetNext()
{
    current_index ++;
    return * current ++;
}

bool ListIterator::SomeNext()
{
    return current_index < list.size();
}

void ListIterator::Reset()
{
    current_index = 0;
    current = list.begin();
}
