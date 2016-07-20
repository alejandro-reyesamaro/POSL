#pragma once

#include "../neighborhood.h"
#include "../decision_pair.h"
#include "../../benchmarks/benchmark.h"
#include "../../solver/psp.h"

class NeighborSelectingHeuristicFirstImprovement
{
    public:
        NeighborSelectingHeuristicFirstImprovement(std::shared_ptr<Domain> domain, int dimension);

        std::shared_ptr<DecisionPair> select(std::shared_ptr<PSP> psp, std::shared_ptr<Neighborhood> V);

    private:
        std::shared_ptr<DecisionPair> rPair;
        std::shared_ptr<POSL_Iterator> it;
        std::vector<int> current_config;
        std::vector<int> best_found_config;
        std::vector<int> neighbor;
};
