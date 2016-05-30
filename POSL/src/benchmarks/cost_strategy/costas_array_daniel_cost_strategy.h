#pragma once

/**
 * POSL
 *
 * \file costas_array_daniel_cost_strategy.h
 * \brief Class to represent the absolute cost stratategy of Costas Array Problem
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

#include "solution_cost_strategy.h"
#include "../../tools/long_int.h"
#include "costas_array_cost_structure.h"

#include <memory>

/*!
 * \class CostasArrayDanielCostStrategy costas_array_daniel_cost_strategy.h
 * \brief Class to represent the absolute cost stratategy of Costas Array Problem
 */
class CostasArrayDanielCostStrategy : public SolutionCostStrategy
{
    public:
        //! Default constructor.
        /*!
            \param n Problem order.
         */
        CostasArrayDanielCostStrategy(int n);

        //! From <SolutionCostStrategy>
        int solutionCost(std::vector<int> & configuration);

    private:
        //! Costas Array cost structure.
        /*!
            A structure with all needed information about the cost.
        */
        std::shared_ptr<CostasArrayCostStructure> ca_str;
};
