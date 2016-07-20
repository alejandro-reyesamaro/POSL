#pragma once

#include "aom_neighborhood_function.h"
#include "../data/solution.h"
#include "../benchmarks/benchmark.h"
#include "../data/neighborhood.h"
#include "../benchmarks/subsum.h"
#include "../data/subsum_single_permitation_neighborhood.h"

class OM_SubsumSinglePermutationNeighborhood : public AOM_NeighborhoodFunction
{
    public:
        OM_SubsumSinglePermutationNeighborhood(std::shared_ptr<Benchmark> bench);

        std::shared_ptr<Neighborhood> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Solution> input);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        std::shared_ptr<Subsum> object_bench;
        std::shared_ptr<SubsumSinglePermitationNeighborhood> V;
};
