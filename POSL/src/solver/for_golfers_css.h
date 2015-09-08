#pragma once

#include "create_solver_strategy.h"
#include "../benchmarks/golfers.h"

class ForGolfersCSS : public CreateSolverStrategy
{
    public:
        ForGolfersCSS(shared_ptr<Golfers> golfers);
        vector<shared_ptr<POSL_Solver>> create();

    private:
        shared_ptr<POSL_Solver> single_solver;
        shared_ptr<POSL_Solver> receiver_solver;
        shared_ptr<POSL_Solver> sender_solver;
};
