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
        Seed(int _seed);

        std::string Tag() { return "cd_Z"; }
        int seed() {return my_seed; }
        std::shared_ptr<FactoryPacker> BuildPacker();

    private:
        int my_seed;
};
