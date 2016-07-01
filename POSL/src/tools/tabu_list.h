#pragma once

#include <vector>
#include <list>
#include <functional>
#include "../tools/list_iterator.h"

class TabuList
{
    public:
        TabuList(int _size);

        void push(std::vector<int> & conf);
        bool isTabu(std::vector<int> & conf);
        bool isTabuByNorm(std::vector<int> & conf, float eps, std::function<float(std::vector<int>&, std::vector<int>&)> norm_func);
        bool isTabuByNorm1(std::vector<int> & conf, float eps);
        bool isTabuByNorm2(std::vector<int> & conf, float eps);
        bool isTabuByNorm8(std::vector<int> & conf, float eps);
        std::shared_ptr<ListIterator> GetConfigurationsIterator();

    private:
        bool is_tabu(std::vector<int> & conf, std::function<float(std::vector<int> &, std::vector<int> &)> norm, float eps);

        int count;
        std::list<std::vector<int>> tabu_list;
        int size;
};
