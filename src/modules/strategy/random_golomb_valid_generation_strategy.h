#pragma once

#include "../../data/solution.h"
#include "../../data/domain.h"
#include "../../modules/grouped_computation.h"
#include "../../benchmarks/benchmark.h"

class RandomGolombValidGenerationStrategy
{
    public:
        RandomGolombValidGenerationStrategy(shared_ptr<Benchmark> _bench_subsum, int _golomb_order, int _subsum_order);

        std::vector<int> generate(shared_ptr<PSP> psp_subsum);
        //std::vector<int> generate();
        //std::vector<int> generate(std::shared_ptr<TabuObject> tabu_object);

    private:
        //std::vector<int> generate_conf(shared_ptr<PSP> psp_subsum);

        //int subsum, n;

        //std::vector<int> values;

        //shared_ptr<Benchmark> bench;
        int golomb_order;
        shared_ptr<GroupedComputation> CM; // Gsec3
        shared_ptr<Solution> sol;
        std::vector<int> golomb_configuration;
        std::vector<int> subsum_configuration;
};
