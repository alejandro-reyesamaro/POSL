#pragma once

#include "aom_neighborhood_function.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../data/neighborhood.h"
#include "../data/one_2d_change_neighborhood.h"

class OM_One2DChangeNeighborhood : public AOM_NeighborhoodFunction
{
    public:
        //! Constructor
        OM_One2DChangeNeighborhood(std::shared_ptr<Benchmark> bench);

        std::shared_ptr<Neighborhood> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Solution> input);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        std::shared_ptr<One2DChangeNeighborhood> V;
};
