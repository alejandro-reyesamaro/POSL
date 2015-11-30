#pragma once

#include "../solver/posl_solver.h"

class PoslUncoder
{
    public:
        PoslUncoder();
        std::vector<std::shared_ptr<POSL_Solver>> uncode_declarations(std::string code, std::shared_ptr<Benchmark> bench);
        //std::vector<std::shared_ptr<POSL_Solver>> uncode_declarations(std::string code, std::shared_ptr<Benchmark> bench);
};
