#pragma once

/**
 * POSL
 *
 * \file seed.h
 * \brief Class to obtain a seed
 * \author Alejandro Reyes
 * \date 2015-04-28
 */

#include "computation_data.h"

/*!
 * \class Seed seed.h
 * \brief Class to obtain a seed
 */
class Seed : public ComputationData
{
    public:
        Seed();

        std::string Tag() { return "cd_Z"; }

        double seed();
        std::shared_ptr<FactoryPacker> BuildPacker();        
};
