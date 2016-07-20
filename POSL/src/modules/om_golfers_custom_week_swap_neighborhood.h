#pragma once

#include "aom_neighborhood_function.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../data/neighborhood.h"
#include "../benchmarks/golfers.h"
#include "../data/golfers_custom_week_swap_neighborhood.h"

class OM_GolfersCustomWeekSwapNeighborhood : public AOM_NeighborhoodFunction
{
    public:
        OM_GolfersCustomWeekSwapNeighborhood(std::shared_ptr<Benchmark> bench, vector<int> _zero_based_weeks);

        std::shared_ptr<Neighborhood> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Solution> input);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        std::shared_ptr<Golfers> object_bench;
        std::shared_ptr<GolfersCustomWeekSwapNeighborhood> V;
};
