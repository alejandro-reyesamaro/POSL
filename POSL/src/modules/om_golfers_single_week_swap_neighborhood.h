#pragma once

#include "aom_neighborhood_function.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../data/neighborhood.h"
#include "../benchmarks/golfers.h"
#include "../data/golfers_single_week_swap_neighborhood.h"

class OM_GolfersSingleWeekSwapNeighborhood : public AOM_NeighborhoodFunction
{
    public:
        OM_GolfersSingleWeekSwapNeighborhood(std::shared_ptr<Benchmark> bench, int _zero_based_week);

        std::shared_ptr<Neighborhood> spcf_execute(std::shared_ptr<PSP>, std::shared_ptr<Solution> input);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        std::shared_ptr<Golfers> object_bench;
        std::shared_ptr<GolfersSingleWeekSwapNeighborhood> V;
};
