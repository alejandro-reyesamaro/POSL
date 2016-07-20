#pragma once

#include "aom_process_configuration.h"
#include "strategy/rearrange_strategy.h"
#include "../benchmarks/cost_strategy/reseteable.h"

class OM_DanielASRestartProcessing : public AOM_ProcessConfiguration
{
    public:
        OM_DanielASRestartProcessing();

        std::shared_ptr<Solution> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Solution>);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    private:
        //std::shared_ptr<Reseteable> reseteable_bench;
        //std::shared_ptr<Benchmark> base_bench;
};
