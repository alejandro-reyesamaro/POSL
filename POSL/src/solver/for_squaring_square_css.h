#pragma once

#include "create_solver_strategy.h"
#include "../benchmarks/squaring_square.h"

class ForSquaringSquareCSS : public CreateSolverStrategy
{
    public:
        ForSquaringSquareCSS(std::shared_ptr<SquaringSquare> ssq);
        std::vector<std::shared_ptr<POSL_Solver>> create();

    private:
        std::shared_ptr<POSL_Solver> single_solver;
        std::shared_ptr<POSL_Solver> receiver_solver;
        std::shared_ptr<POSL_Solver> sender_solver;
};
