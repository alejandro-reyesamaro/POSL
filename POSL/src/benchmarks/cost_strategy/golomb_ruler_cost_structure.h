#pragma once

#include <vector>
#include <list>
#include "../../tools/t_changes.h"
#include "../../tools/long_int.h"

class GolombRulerCostStructure
{
    public:
        GolombRulerCostStructure(int _order, int _length);

        int cost(std::vector<int> & config);
        int relative_cost(std::vector<int> & new_config, T_Changes change, bool updating);
        void init(std::vector<int> config);
        int costOnVariable(int index);
        void reset();

        int Order, Length;
        int CurrentCost;
        std::vector<int> Configuration;

    private:
        std::vector<int> measures;
        std::vector<std::list<int>> measures_intervenants;
        std::vector<std::list<int>> measures_intervenants_index;
        std::vector<std::list<int>> negative_measures_intervenants;
        std::vector<int> variables_in_negative_measures;
};
