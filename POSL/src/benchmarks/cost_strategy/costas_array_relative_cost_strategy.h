#pragma once

/**
 * POSL
 *
 * \file costas_array_relative_cost_strategy.h
 * \brief Class to represent the relative cost stratategy of Costas Array Problem
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

#include "relative_cost_strategy.h"
#include "costas_array_cost_structure.h"
#include "sickest_variable_strategy.h"

#include <memory>

/*!
 * \class CostasArrayRelativeCostStrategy costas_array_relative_cost_strategy.h
 * \brief Class to represent the relative cost stratategy of Costas Array Problem
 */
class CostasArrayRelativeCostStrategy : public RelativeCostStrategy
{
    public:
        //! Default constructor.
        /*!
            \param n Problem order.
         */
        CostasArrayRelativeCostStrategy(int n);

        //! From <RelativeCostStrategy>
        void initializeCostData(vector<int> &_configuration, int _initial_cost);

        //! From <RelativeCostStrategy>
        int relativeSolutionCost(vector<int> & _configuration);

        //! From <RelativeCostStrategy>
        int relativeSolutionCost(std::vector<int> & _configuration, T_Changes);

        //! From <RelativeCostStrategy>
        void updateConfiguration(vector<int> & new_config);

        //! From <RelativeCostStrategy>
        int costOnVariable(int variable_index);

        //! From <RelativeCostStrategy>
        int sickestVariable();

        //! Performs a <i>reset</i> w.r.t the current configuration.
        /*!
            \return A configuration <i>reseted</i>.
         */
        std::vector<int> Reset();//vector<int> &current_configuration);

        //! (Property) From <RelativeCostStrategy>
        int currentCost() { return ca_str->CurrentCost; }

    private:
        //! Costas Array cost structure.
        /*!
            A structure with all needed information about the cost.
        */
        std::shared_ptr<CostasArrayCostStructure> ca_str;

        //! Strategy to compute the most troubled variable.
        /*!
            In this problem, the strategy is by default: select the index of a variable
            with the highest projected cost, using the function <b>sickestVariable()</b>
        */
        std::shared_ptr<SickestVariableStrategy> sickest_variable_strategy;
};
