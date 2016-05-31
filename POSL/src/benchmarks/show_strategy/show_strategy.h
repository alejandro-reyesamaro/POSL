#pragma once

/**
 * POSL
 *
 * \file show_strategy.h
 * \brief Interface to represent the way a problem shows its result (solution)
 * \author Alejandro Reyes
 * \date 2016-05-31
 */

#include "../../data/solution.h"

/*!
 * \class ShowStrategy show_strategy.h
 * \brief Interface to represent the way a problem shows its result (solution)
 */
class ShowStrategy
{
    public:
        //! Default constructor.
        /*!
            \param solution A solution to some problem.
            \return String to show
         */
        virtual std::string showSolution(std::shared_ptr<Solution> solution) = 0;
};

