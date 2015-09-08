#pragma once

#include "create_solver_strategy.h"
#include "../benchmarks/golomb_ruler.h"

class ForGolombRulerCSS : public CreateSolverStrategy
{
    public:
        ForGolombRulerCSS(shared_ptr<GolombRuler> golomb);
        vector<shared_ptr<POSL_Solver>> create();

    private:
        shared_ptr<POSL_Solver> single_solver;
        shared_ptr<POSL_Solver> receiver_solver;
        shared_ptr<POSL_Solver> sender_solver;
};
