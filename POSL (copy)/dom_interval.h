#pragma once

/**
 * POSL
 *
 * \file dom_interval.h
 * \brief Class to represent an integer interval
 * \author Alejandro Reyes
 * \date 2015-04-15
 */

/*!
 * \class DomInterval dom_interval.h
 * \brief Class to represent an integer interval
 */
class DomInterval
{
    public:
        //! Constructor
        /*!
        * \param _a Tha initial value
        * \param _b The final value
        */
        DomInterval(int _a, int _b);

        //! Return the lenght of the interval
        /*!
        * \return Lenght of the interval
        */
        int Length();

        //! Initial and final value of the interval
        int a, b;
};
