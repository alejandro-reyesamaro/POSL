#pragma once

/**
 * POSL
 *
 * \file costas_array_cost_structure.h
 * \brief Class to represent the necessary functionality to compute the solution cost of Costas Array Problem
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

#include <vector>
#include "../../tools/t_changes.h"
#include "../../tools/randomizer.h"
#include "projectable_cost.h"

/*!
 * \class CostasArrayCostStructure costas_array_cost_structure.h
 * \brief Class to represent the necessary functionality to compute the solution cost of Costas Array Problem
 */
class CostasArrayCostStructure : public ProjectableCost
{
    public:
        CostasArrayCostStructure(int n);

        //int relative_cost(std::vector<int> new_config, T_Changes change, bool updating);
        //void set(std::vector<int> _configuration);

        //! Initialize the information related to the cost.
        /*!
            \param _configuration A configuration (solution).
         */
        void init(vector<int> _configuration);

        //! From <ProjectableCost>
        int costOnVariable(int index);

        //! Performs a <i>reset</i> w.r.t the current configuration.
        /*!
            \return A configuration <i>reseted</i>.
         */
        void reset();

        //! (Property) Retrun a pointer to the random generator
        /*!
            \return The randome generator.
         */
        shared_ptr<Randomizer> GetRandomized() { return rand; }

        //! (Field) Costas Array Problem Order.
        int N;
        //! (Field) The current cost
        int CurrentCost;
        //! (Field) The current configuration
        std::vector<int> Configuration;

    private:
        //! Function just to make easier some calculations
        int m_error(){ return (N * N - (dist * dist)); }
        //! Function just to make easier some calculations
        void m_errOn(int k) { err[k] += m_error(); err[k - dist] += m_error(); }

        //! Performs a random permutation of an array.
        /*!
            \param vec A vector (configuration).
            \param begin Start position
            \param size Number of elements to be shuffled
         */
        void Random_Array_Permut(std::vector<int> & vec, int begin, int size);

        //! Computes the cost of a given configuration.
        /*!
            \param config A given configuration.
            \param update Whether the information will be updated
            \return The cost of a given configuration
         */
        int Cost(vector<int> & config, bool update);

        //! A random generator
        shared_ptr<Randomizer> rand;

        int dist = 1;
        int i, first_i;
        int diff, diff_translated;
        int nb;
        int r = 0;

        //! errors on variables
        std::vector<int> err;
        //! nb occurrences of each distance -(size -1)..-1 1..size-1 (0 is unused)
        std::vector<int> nb_occ;
        //! records the indice of a first occurence of a distance
        std::vector<int> first;
        //! save the sol[] vector
        std::vector<int> save_sol;
        //! save the best sol[] found in a reset phase
        std::vector<int> best_sol;
        //! indices of erroneous vars
        std::vector<int> i_err;
        //! some values to add (circularly) at reset
        std::vector<int> to_add;
};
