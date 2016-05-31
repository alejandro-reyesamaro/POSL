#pragma once

/**
 * POSL
 *
 * \file golomb_ruler_default_show_strategy.h
 * \brief Class to represent the way Golomb Ruler problem shows its result (solution)
 * \author Alejandro Reyes
 * \date 2016-05-31
 */

#include "show_strategy.h"

/*!
 * \class GolombRulerDefaultShowStrategy golomb_ruler_default_show_strategy.h
 * \brief Class to represent the way Golomb Ruler problem shows its result (solution)
 */
class GolombRulerDefaultShowStrategy : public ShowStrategy
{
    public:
        //! Default constructor.
        /*!
            \param _order Problem order: number of marks.
            \param _length Maximal measure (final mark).
         */
        GolombRulerDefaultShowStrategy(int _order, int _length);

        //! From <ShowStrategy>
        std::string showSolution(std::shared_ptr<Solution> solution);

    private:
        //! [Number of marcs], [Maximum distance]
        int order, length;
};
