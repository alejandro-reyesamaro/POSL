#pragma once

#include <memory>
#include <list>
#include <vector>

class ListIterator
{
    public:
        ListIterator(std::list<std::vector<int>> & _list);

        std::vector<int> GetNext();
        bool SomeNext();
        void Reset();

    private:
        std::list<std::vector<int>> & list;
        std::list<std::vector<int>>::iterator current;
        int current_index;
};
