#pragma once

#include "../modules/compound_module.h"

class CompoundModuleUncoder
{
    public:
        CompoundModuleUncoder();
        std::shared_ptr<CompoundModule> uncode(std::string code, std::shared_ptr<Benchmark> bench);
};
