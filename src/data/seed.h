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

#include <functional>

#define TAGSEED "cd_Z"

/*!
 * \class Seed seed.h
 * \brief Class to obtain a seed
 */
class Seed : public ComputationData
{
    public:
        Seed();
        Seed(int _seed);

        std::string Tag() { return TAGSEED; }
        int seed() {return my_seed; }
        std::shared_ptr<FactoryPacker> BuildPacker();

        int comapareTo(std::shared_ptr<ComputationData> other, std::function<int(std::shared_ptr<ComputationData>)>);

    private:
        int my_seed;
};
