#pragma once

/**
 * POSL
 *
 * \file domain.h
 * \brief Class to represent the domain of a variable
 * \author Alejandro Reyes
 * \date 2015-04-14
 */

#include "dStrategy/factory_domain.h"

#include <vector>

using namespace std;

/*!
 * \class Domain domain.h
 * \brief Class to represent the domain of a variable
 */
class Domain
{
    public:
        //! Constructor
        /*!
        * \param fd Factory object to obtain an specific kind of domain
        */
        Domain(FactoryDomain * fd);

        //! Returns the vector of values
        /*!
        * \return Vector of values
        */
        vector<int> GetValues();

        //! Returns the minimum value of the domain
        /*!
        * \return Minimum value
        */
        int minimum();

        //! Returns the maximum value of the domain
        /*!
        * \return Maximum value
        */
        int maximum();

    private:
        //! Vector of values
        vector<int> D;
};
