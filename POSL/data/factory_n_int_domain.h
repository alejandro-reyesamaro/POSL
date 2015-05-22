#pragma once

/**
 * FoolSolver
 *
 * \file factory_n_int_domain.h
 * \brief Factory class to build an integer domain
 * \author Alejandro Reyes
 * \date 2014-08-14
 */

#include "factory_domain.h"

using namespace std;

/*!
 * \class Factory_NIntDomain factory_n_int_domain.h
 * \brief Factory class to build an integer domain
 */
class Factory_NIntDomain : public FactoryDomain
{
    public:
        //! Constructor
        /*!
        * \param min Minimum value
        * \param max Maximum value
        */
        Factory_NIntDomain(int min, int max);

        //! Overriding the method from the father class
        /*!
        * \return Vector of values
        */
        vector<int> BuildDomain();

    private:
        //! Minimum and maximum values
        int a, b;
};
