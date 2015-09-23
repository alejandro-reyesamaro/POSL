#include "tabu_list.h"
#include "tools.h"

#include <algorithm>
#include <iostream>

using namespace std;

TabuList::TabuList(int _size) : count(0), size(_size)
{
}

void TabuList::push(vector<int> conf)
{
    if(count >= size)
    {
        //vector<vector<int>> aux(tabu_list.size() - 1);
        //copy ( tabu_list.begin()+1, tabu_list.end(), aux.begin() );
        //tabu_list = aux;
        tabu_list.pop_front();
    } else
        count ++;

    tabu_list.push_back(conf);
    //cout << Tools::configurationToString(conf) << endl;
}

/*
bool areEquals(vector<int> v1, vector<int> v2)
{
    return equal(v1.begin(), v1.end(), v2);
}
*/

bool TabuList::isTabu(vector<int> conf)
{
    /*for(int i = 0; i < count; i++)
        if(areEquals(tabu_list[i], conf))
            return true;
    return false;
    */
    list<vector<int>>::iterator it;
    it = find (tabu_list.begin(), tabu_list.end(), conf);

    return it != tabu_list.end();
}
