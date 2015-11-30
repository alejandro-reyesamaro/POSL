#pragma once

#include "posl_solver_declaration.h"

class SolverDeclarationUncoder
{
    public:
        SolverDeclarationUncoder();
        PoslSolverDeclaration uncode(std::string code);
};
