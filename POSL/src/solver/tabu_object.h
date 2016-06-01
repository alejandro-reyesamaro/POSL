#pragma once

#include "../tools/tabu_list.h"

#include <memory>

class TabuObject
{
    public:
        TabuObject(int problem_dimention);

        void addTabuSolution(std::vector<int> & configuration);
        bool isGlobalTabu(std::vector<int> & configuration, float eps);
        bool isGlobalTabu(std::vector<int> & configuration);
        bool ThereIsTabu() {return something_has_arrived; }
        std::vector<int> GetLastArrivedTabu() { return last_arrived_tabu_configuration; }

    private:
        std::shared_ptr<TabuList> tabu_list;
        std::vector<int> last_arrived_tabu_configuration;
        bool something_has_arrived;
};
