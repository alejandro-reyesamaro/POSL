#pragma once

#include "aom_neighborhood_function.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../data/neighborhood.h"
#include "../data/adaptive_search_range_neighborhood.h"

class OM_AdaptiveSearchRangeNeighborhood : public AOM_NeighborhoodFunction
{
    public:
        //! Constructor
        OM_AdaptiveSearchRangeNeighborhood(std::shared_ptr<Benchmark> bench, int _a, int _b);

        std::shared_ptr<Neighborhood> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Solution> input);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        std::shared_ptr<AdaptiveSearchRangeNeighborhood> V;
};
