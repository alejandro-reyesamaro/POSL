#pragma once

/**
 * POSL
 *
 * \file factory_compound_module.h
 * \brief Class to build a C.M. for a solver
 * \author Alejandro Reyes
 * \date 2015-05-12
 */

#include "compound_module.h"

using namespace std;

/*!
 * \class FactoryCompoundModule factory_compound_module.h
 * \brief Class to build a C.M. for a solver
 */
class FactoryCompoundModule
{
    public:
        FactoryCompoundModule();
        virtual CompoundModule buildCM() = 0;
};

