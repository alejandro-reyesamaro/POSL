#include "tabu_list.h"

#include <algorithm>

TabuList::TabuList(int _size) : count(0), size(_size)
{
}

void TabuList::push(Solution * conf)
{
    if(count >= size)
    {
        vector<Solution *> aux(tabu_list.size() - 1);
        copy ( tabu_list.begin()+1, tabu_list.end(), aux.begin() );
        tabu_list = aux;
    } else count ++;

    tabu_list.push_back(conf);
}

bool TabuList::isTabu(Solution * conf)
{
    for(int i = 0; i < count; i++)
        if(tabu_list[i]->equal(conf))
            return true;
    return false;
}
