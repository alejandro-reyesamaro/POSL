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
        Factory_NIntDomain(int min, int max);
        vector<int> BuildDomain();

    private:
        //! Minimum and maximum values
        int a, b;
};
