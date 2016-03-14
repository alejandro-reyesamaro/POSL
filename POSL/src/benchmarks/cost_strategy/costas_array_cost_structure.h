#pragma once

#include <vector>
#include "../../tools/t_changes.h"
#include "../../tools/randomizer.h"

class CostasArrayCostStructure
{
    public:
        CostasArrayCostStructure(int n);

        //int relative_cost(std::vector<int> new_config, T_Changes change, bool updating);
        //void set(std::vector<int> _configuration);

        void init(vector<int> config);
        int costOnVariable(int index);
        void Reset();

        int N;
        int CurrentCost;
        std::vector<int> Configuration;
        shared_ptr<Randomizer> GetRandomized() { return rand; }

    private:
        int m_error(){ return (N * N - (dist * dist)); }
        void m_errOn(int k) { err[k] += m_error(); err[k - dist] += m_error(); }
        void Random_Array_Permut(std::vector<int> & vec, int begin, int size);
        int Cost(vector<int> &config, bool update);

        shared_ptr<Randomizer> rand;
        int dist = 1;
        int i, first_i;
        int diff, diff_translated;
        int nb;
        int r = 0;
        std::vector<int> err;       /* errors on variables */
        std::vector<int> nb_occ;    /* nb occurrences of each distance -(size -1)..-1 1..size-1 (0 is unused) */
        std::vector<int> first;		/* records the indice of a first occurence of a distance */

        std::vector<int> save_sol;  /* save the sol[] vector */
        std::vector<int> best_sol;  /* save the best sol[] found in a reset phase */
        std::vector<int> i_err;     /* indices of erroneous vars */
        std::vector<int> to_add;	/* some values to add (circularly) at reset */
};
