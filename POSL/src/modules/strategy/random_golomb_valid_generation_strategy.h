#pragma once

#include "../../data/solution.h"
#include "../../data/domain.h"
#include "../../modules/grouped_computation.h"
#include "../../benchmarks/benchmark.h"

class RandomGolombValidGenerationStrategy
{
    public:
        RandomGolombValidGenerationStrategy(int _order, int _length);

        std::vector<int> generate(vector<int> &configuration_tabu);
        std::vector<int> generate();

    private:
        std::vector<int> generate_conf();

        int subsum, n;
        int golomb_order;
        std::vector<int> values;

        shared_ptr<Benchmark> bench;
        shared_ptr<PSP> psp;
        shared_ptr<GroupedComputation> CM; // Gsec3

        shared_ptr<Solution> sol;
        std::vector<int> golomb_configuration;
        std::vector<int> subsum_configuration;
};
