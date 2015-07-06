#pragma once

/**
 * POSL
 *
 * \file tools.h
 * \brief (Static) Class to represent useful methods
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include <string>

using namespace std;

/*!
 * \class Tools tools.h
 * \brief (Static) Class to represent useful methods
 */
class Tools
{
    public:
        //! Convert an integer in a string
        /*!
        * \param c A given integer
        * \return The resulting string
        */
        static string int2str(int c);
};
