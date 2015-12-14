#pragma once

#include "aom_neighborhood_function.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../data/neighborhood.h"
#include "../benchmarks/golfers.h"
#include "../data/golfers_adaptive_search_neighborhood.h"

class OM_GolfersAdaptiveSearchNeigborhood : public AOM_NeighborhoodFunction
{
    public:
        OM_GolfersAdaptiveSearchNeigborhood(std::shared_ptr<Benchmark> bench);

        std::shared_ptr<Neighborhood> spcf_execute(std::shared_ptr<PSP>, std::shared_ptr<Solution> input);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        std::shared_ptr<Golfers> object_bench;
        std::shared_ptr<GolfersAdaptiveSearchNeighborhood> V;
};
