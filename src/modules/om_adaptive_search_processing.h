#pragma once

#include "aom_process_configuration.h"
#include "strategy/rearrange_strategy.h"

class OM_AdaptiveSearchProcessing : public AOM_ProcessConfiguration
{
    public:
        OM_AdaptiveSearchProcessing(std::shared_ptr<Benchmark> bench);

        std::shared_ptr<Solution> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Solution>);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    private:
          std::vector<int> config;
          std::shared_ptr<RearrangeStrategy> all_circualr_shift_str;
          std::shared_ptr<RearrangeStrategy> circualr_shift_str;
          std::shared_ptr<RearrangeStrategy> add_const_str;
          std::vector<std::shared_ptr<Solution>>  three_stpes_solutions;
          int cost_1, cost_2, cost_3;
};
