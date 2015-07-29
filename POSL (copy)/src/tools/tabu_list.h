#pragma once

#include "../data/solution.h"

#include <vector>

using namespace std;

class TabuList
{
    public:
        TabuList(int _size);
        void push(Solution * conf);
        bool isTabu(Solution * conf);

    private:
        int count;
        vector<Solution *> tabu_list;
        int size;
};
