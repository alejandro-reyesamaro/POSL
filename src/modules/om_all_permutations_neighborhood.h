#pragma once

#include "aom_neighborhood_function.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../data/neighborhood.h"
#include "../data/all_permutations_neighborhood.h"

class OM_AllPermutationsNeighborhood : public AOM_NeighborhoodFunction
{
    public:
        //! Constructor
        OM_AllPermutationsNeighborhood(std::shared_ptr<Benchmark> bench, int part);

        std::shared_ptr<Neighborhood> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Solution> input);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        std::shared_ptr<AllPermutationsNeighborhood> V;
};
