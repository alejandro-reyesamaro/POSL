#pragma once

#include "create_solver_strategy.h"
#include "../benchmarks/golomb_ruler.h"

class ForGolombRulerCSS : public CreateSolverStrategy
{
    public:
        ForGolombRulerCSS(std::shared_ptr<GolombRuler> golomb);
        std::vector<std::shared_ptr<POSL_Solver>> create();

    private:
        std::shared_ptr<POSL_Solver> single_solver;
        std::shared_ptr<POSL_Solver> receiver_solver;
        std::shared_ptr<POSL_Solver> sender_solver;
};
