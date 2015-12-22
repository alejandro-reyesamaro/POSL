#pragma once

#include <vector>
#include "../../tools/t_changes.h"

class CostasArrayCostStructure
{
    public:
        CostasArrayCostStructure(int n);

        //int relative_cost(std::vector<int> new_config, T_Changes change, bool updating);
        //void set(std::vector<int> _configuration);

        void init(std::vector<int> config);
        int costOnVariable(int index);

        int N;
        int CurrentCost;
        std::vector<int> Configuration;

    private:
        int m_error(){ return (N * N - (dist * dist)); }
        void m_errOn(int k) { err[k] += m_error(); err[k - dist] += m_error(); }

        int dist = 1;
        int i, first_i;
        int diff, diff_translated;
        int nb;
        int r = 0;
        std::vector<int> err;       /* errors on variables */
        std::vector<int> nb_occ;    /* nb occurrences of each distance -(size -1)..-1 1..size-1 (0 is unused) */
        std::vector<int> first;		/* records the indice of a first occurence of a distance */
};