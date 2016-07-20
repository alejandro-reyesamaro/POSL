#pragma once

#include "../neighborhood.h"
#include "../decision_pair.h"
#include "../../benchmarks/benchmark.h"
#include "../../solver/psp.h"
#include "../../tools/binary_search_tree.h"
#include "../../tools/hash_map.h"


class NeighborSelectingKBestImprovement
{
    public:
        NeighborSelectingKBestImprovement(shared_ptr<Domain> domain, int dimension, int k);

        std::shared_ptr<DecisionPair> select(std::shared_ptr<PSP> psp, std::shared_ptr<Neighborhood> V);

    private:
        int K;
        std::shared_ptr<DecisionPair> rPair;
        std::shared_ptr<POSL_Iterator> it;
        std::vector<int> current_config;
        //std::vector<int> best_found_config;        
        std::shared_ptr<BinarySearchTree<std::vector<int>>> selection_tree;

        std::vector<int> neighbor;
};

