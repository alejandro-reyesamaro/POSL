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
#include <memory>

using namespace std;

/*!
 * \class Domain domain.h
 * \brief Class to represent the domain of a variable
 */
class Domain
{
    public:
        Domain(shared_ptr<FactoryDomain> fd);

        vector<int> GetValues();
        int minimum();
        int maximum();

    private:
        vector<int> D;
};
