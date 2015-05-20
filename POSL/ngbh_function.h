#pragma once

/**
 * POSL
 *
 * \file ngbh_function.h
 * \brief Interface to represent a neighborhood funtion
 * \author Alejandro Reyes
 * \date 2015-04-15
 */

#include "posl_iterator.h"

#include <vector>
#include <memory>

using namespace std;

/*!
 * \class NgbhFunction ngbh_function.h
 * \brief Interface to represent a neighborhood funtion
 */
class NgbhFunction
{
    public:
        //! Returns an elements iterator
        /*!
        * \return Elements iterator
        */
        virtual shared_ptr<POSL_Iterator<vector<int>>> getIterator() = 0;

        //! Returns the element at the position pos
        /*!
        * \param pos Index of the element
        * \return The element at the position pos
        */
        virtual int elementAt(int pos) = 0;

        //! Returns the number of element of the neighborhood
        /*!
        * \return The number of elements
        */
        virtual int length() = 0;
};
