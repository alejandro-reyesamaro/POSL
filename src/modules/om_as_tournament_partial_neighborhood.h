#pragma once

#include "aom_neighborhood_function.h"
#include "../benchmarks/benchmark.h"
#include "../data/neighborhood.h"
#include "../benchmarks/golfers.h"
#include "../data/as_tournament_partial_neighborhood.h"

class OM_ASTournamentPartialNeighborhood : public AOM_NeighborhoodFunction
{
    public:
        OM_ASTournamentPartialNeighborhood(std::shared_ptr<Benchmark> bench, int _players, int _groups, int _part);

        std::shared_ptr<Neighborhood> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Solution> input);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        std::shared_ptr<ASTournamentPartialNeighborhood> V;
};
