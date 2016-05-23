#pragma once

#include "aom_rearrange_configuration.h"
#include "strategy/rearrange_strategy.h"
#include "../benchmarks/cost_strategy/reseteable.h"

class OM_DanielASRestartRearrange : public AOM_RearrangeConfiguration
{
    public:
        OM_DanielASRestartRearrange();

        std::shared_ptr<Solution> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Solution>);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    private:
        //std::shared_ptr<Reseteable> reseteable_bench;
        //std::shared_ptr<Benchmark> base_bench;
};
