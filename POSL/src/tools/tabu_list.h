#pragma once

#include <vector>
#include <list>

using namespace std;

class TabuList
{
    public:
        TabuList(int _size);
        void push(vector<int> conf);
        bool isTabu(vector<int> conf);

    private:
        int count;
        list<vector<int>> tabu_list;
        int size;
};
