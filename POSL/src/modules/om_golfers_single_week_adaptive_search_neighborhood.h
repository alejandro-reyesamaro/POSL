#pragma once

#include "aom_neighborhood_function.h"
#include "../benchmarks/benchmark.h"
#include "../data/neighborhood.h"
#include "../benchmarks/golfers.h"
#include "../data/golfers_adaptive_search_single_week_neighborhood.h"

class OM_GolfersSingleWeekAdaptiveSearchNeighborhood : public AOM_NeighborhoodFunction
{
    public:
        OM_GolfersSingleWeekAdaptiveSearchNeighborhood(std::shared_ptr<Benchmark> bench, int _zero_based_week);

        std::shared_ptr<Neighborhood> spcf_execute(std::shared_ptr<PSP>, std::shared_ptr<Solution> input);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        std::shared_ptr<Golfers> object_bench;
        std::shared_ptr<GolfersAdaptiveSearchSingleWeekNeighborhood> V;
};
