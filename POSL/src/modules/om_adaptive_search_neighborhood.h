#pragma once

#include "aom_neighborhood_function.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../data/neighborhood.h"
#include "../data/adaptive_search_neighborhood.h"

class OM_AdaptiveSearchNeighborhood : public AOM_NeighborhoodFunction
{
    public:
        //! Constructor
        OM_AdaptiveSearchNeighborhood(std::shared_ptr<Benchmark> bench);

        std::shared_ptr<Neighborhood> spcf_execute(std::shared_ptr<PSP>, std::shared_ptr<Solution> input);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        std::shared_ptr<AdaptiveSearchNeighborhood> V;
};
