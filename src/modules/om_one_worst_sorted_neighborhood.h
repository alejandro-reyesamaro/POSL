#pragma once

#include "aom_neighborhood_function.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../data/neighborhood.h"
#include "../data/one_worst_sorted_change_neighborhood.h"

class OM_OneWorstSortedNeighborhood : public AOM_NeighborhoodFunction
{
    public:
        OM_OneWorstSortedNeighborhood(std::shared_ptr<Benchmark> bench);

        std::shared_ptr<Neighborhood> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Solution> input);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        std::shared_ptr<OneWorstSortedChangeNeighborhood> V;
};
