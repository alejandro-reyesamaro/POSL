#include "tabu_list.h"
#include "tools.h"

#include <algorithm>
#include <iostream>

using namespace std;

TabuList::TabuList(int _size) : count(0), size(_size)
{
}

void TabuList::push(vector<int> & conf)
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

bool TabuList::isTabu(vector<int> & conf)
{
    list<vector<int>>::iterator it;
    it = find (tabu_list.begin(), tabu_list.end(), conf);
    return it != tabu_list.end();
}

bool TabuList::is_tabu(vector<int> & conf, std::function<float(vector<int>&, vector<int>&)> norm, float eps)
{
    for (std::list<vector<int>>::iterator it = tabu_list.begin(); it != tabu_list.end(); ++it)
    {
        //vector<int> current = *it;
        if(norm(conf, *it) < eps)
            return true;
    }
    return false;
}

bool TabuList::isTabuByNorm1(vector<int> & conf, float eps)
{
    std::function<float(vector<int>&, vector<int>&)> norm = Tools::norm1;
    return is_tabu(conf, norm, eps);
}

bool TabuList::isTabuByNorm2(vector<int> & conf, float eps)
{
    std::function<float(vector<int>&, vector<int>&)> norm = Tools::norm2;
    return is_tabu(conf, norm, eps);
}

bool TabuList::isTabuByNorm8(vector<int> & conf, float eps)
{
    std::function<float(vector<int>&, vector<int>&)> norm = Tools::norm8;
    return is_tabu(conf, norm, eps);
}
