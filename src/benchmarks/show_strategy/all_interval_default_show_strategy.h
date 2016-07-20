#pragma once

/**
 * POSL
 *
 * \file all_interval_default_show_strategy.h
 * \brief Class to represent the way All-Interval Series problem shows its result (solution)
 * \author Alejandro Reyes
 * \date 2016-05-31
 */

#include "show_strategy.h"

/*!
 * \class AllIntervalDefaultShowStrategy all_interval_default_show_strategy.h
 * \brief Class to represent the way All-Interval Series problem shows its result (solution)
 */
class AllIntervalDefaultShowStrategy : public ShowStrategy
{
    public:
        //! Default constructor.
        /*!
            \param n Problem order.
         */
        AllIntervalDefaultShowStrategy(int n);

        //! From <ShowStrategy>
        std::string showSolution(std::shared_ptr<Solution> solution);

    private:
        //! Problem order.
        int N;
};
