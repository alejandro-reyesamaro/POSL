#pragma once

#include "../modules/compound_module.h"

class ComputationStrategyUncoder
{
    public:
        ComputationStrategyUncoder();
        static std::shared_ptr<CompoundModule> uncode(std::string code,
                                                      std::vector<std::string> om_instances,
                                                      std::vector<std::string> och_instances,
                                                      std::shared_ptr<Benchmark> bench);
};
