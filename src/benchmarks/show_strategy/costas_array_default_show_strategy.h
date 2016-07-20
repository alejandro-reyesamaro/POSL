#pragma once

/**
 * POSL
 *
 * \file costas_array_default_show_strategy.h
 * \brief Class to represent the way Costas Array problem shows its result (solution)
 * \author Alejandro Reyes
 * \date 2016-05-31
 */

#include "show_strategy.h"

/*!
 * \class CostasArrayDefaultShowStrategy costas_array_default_show_strategy.h
 * \brief Class to represent the way Costas Array problem shows its result (solution)
 */
class CostasArrayDefaultShowStrategy : public ShowStrategy
{
    public:
        //! Default constructor.
        /*!
            \param n Problem order.
         */
        CostasArrayDefaultShowStrategy(int n);

        //! From <ShowStrategy>
        std::string showSolution(std::shared_ptr<Solution> solution);

    private:
        //! Problem order.
        int N;
};
