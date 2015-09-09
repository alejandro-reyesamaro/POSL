#pragma once

#include "create_solver_strategy.h"
#include "../benchmarks/golfers.h"

class ForGolfersCSS : public CreateSolverStrategy
{
    public:
        ForGolfersCSS(std::shared_ptr<Golfers> golfers);
        std::vector<std::shared_ptr<POSL_Solver>> create();

    private:
        std::shared_ptr<POSL_Solver> single_solver;
        std::shared_ptr<POSL_Solver> receiver_solver;
        std::shared_ptr<POSL_Solver> sender_solver;
};
