#pragma once

/**
 * POSL
 *
 * \file domain.h
 * \brief Class to represent the domain of a variable
 * \author Alejandro Reyes
 * \date 2015-04-14
 */

#include "factory_domain.h"

#include <vector>
#include <memory>

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
        Domain(shared_ptr<FactoryDomain> fd);

        //! Return the vector of values
        /*!
        * \return Vector of values
        */
        vector<int> GetValues();

    private:
        //! Vector of values
        vector<int> D;
};
