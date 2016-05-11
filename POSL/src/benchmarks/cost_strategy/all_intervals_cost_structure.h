#pragma once

#include "../../tools/t_changes.h"
#include "../../tools/long_int.h"
#include "projectable_cost.h"
#include "../../tools/randomizer.h"

#include <vector>
#include <list>

class AllIntervalsCostStructure : public ProjectableCost
{
    public:
        AllIntervalsCostStructure(int _n);


        int relative_cost(std::vector<int> & new_config, T_Changes, bool updating);
        void init(std::vector<int> config);
        int costOnVariable(int);
        void reset();

        int N;
        int CurrentCost;
        std::vector<int> Configuration;

    private:
        std::vector<int> nb_occ;
        std::vector<int> nb_occ_aux;
        std::shared_ptr<Randomizer> rand;
};
