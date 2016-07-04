#pragma once

#include "aom_first_configuration_generation.h"
#include "strategy/random_golomb_valid_generation_strategy.h"
#include "../benchmarks/golomb_ruler.h"
#include "../benchmarks/subsum.h"

class OM_GolombValidGeneration : public AOM_FirstConfigurationGeneration
{
    public:
        //! Constructor
        OM_GolombValidGeneration(std::shared_ptr<Benchmark> bench);

        std::shared_ptr<Solution> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Seed>);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    protected:
        std::shared_ptr<Solution> rsolution;
        std::shared_ptr<GolombRuler> object_bench;        
        int golomb_order;
        int golomb_length;
        int subsum, n;
        std::vector<int> values;
        std::shared_ptr<Subsum> object_subsum;
        std::shared_ptr<PSP> subsum_psp;
        std::vector<int> subsum_configuration;
        std::shared_ptr<RandomGolombValidGenerationStrategy> rconf_strategy;
};
