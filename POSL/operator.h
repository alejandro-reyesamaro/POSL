#pragma once

/**
 * POSL
 *
 * \file operator.h
 * \brief Class to represent an operation between modules
 * \author Alejandro Reyes
 * \date 2015-05-12
 */

#include "compound_module.h"

#include <vector>

using namespace std;

/*!
 * \class Operation operator.h
 * \brief Class to represent an operation between modules
 */
class Operator
{
    public:
        Operator();
        virtual void evaluate() = 0;

    private:
        vector<CompoundModule> modules;
};
