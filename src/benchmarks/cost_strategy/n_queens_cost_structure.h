#pragma once

#include <vector>
#include "../../tools/t_changes.h"
#include "projectable_cost.h"

class NQueensCostStructure : public ProjectableCost
{
    public:
        NQueensCostStructure(int n);

        int relative_cost(std::vector<int> & new_config, T_Changes change, bool updating);
        void set(std::vector<int> & _configuration);
        int costOnVariable(int i);

        int N;
        int CurrentCost;
        std::vector<int> Configuration;

    private:
        int F(int x){ return (x <= 1) ? 0 : x; }

        int nb_diag;
        std::vector<int> err_d1;
        std::vector<int> err_d2;
        std::vector<unsigned int> flags;

};
