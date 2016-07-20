#pragma once

/**
 * POSL
 *
 * \file reseteable.h
 * \brief Interface to represent a class that performs a reset
 * \author Alejandro Reyes
 * \date 2016-05-30
 */

#include <vector>

/*!
 * \class Reseteable reseteable.h
 * \brief Interface to represent a relative solution cost strategy
 */
class Reseteable
{
    public:
        //! Performs a reset w.r.t. the current configuration
        /*!
            \return A <i>reseted</i> configuration.
         */
        virtual std::vector<int> Reset() = 0;
};
