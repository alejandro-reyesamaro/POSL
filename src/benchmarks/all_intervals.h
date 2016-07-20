#pragma once

/**
 * POSL
 *
 * \file all_intervals.h
 * \brief Class to represent All-Interval Series problem
 * \author Alejandro Reyes
 * \date 2016-06-17
 */

#include "benchmark.h"
#include "cost_strategy/all_interval_relative_cost_strategy.h"

/*!
 * \class AllIntervals all_intervals.h
 * \brief Class to represent All-Interval Series problem
 */
class AllIntervals : public Benchmark
{
    public:
        //! Default constructor.
        /*!
            \param n Problem order.
         */
        AllIntervals(int _n);

        //! From <Benchmark>
        std::string showInstance();

        //! From <Benchmark>
        std::vector<int> Reset() override;

        //! (Property) All-Intervals Series Problem Order.
        int N(){ return n; }

    private:
        //! (Field) All-Intervals cast to relative cost strategy.
        std::shared_ptr<AllIntervalRelativeCostStrategy> cast_my_relative_strategy();

        //! (Field) All-Intervals Series Problem Order.
        int n;
};
