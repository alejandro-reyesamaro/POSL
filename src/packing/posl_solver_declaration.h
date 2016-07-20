#pragma once

#include <string>
#include <vector>

struct PoslSolverDeclaration
{
    public:
        std::string Solver_Name;
        std::string Computation_Strategy_Name;
        std::vector<std::string> Operation_Module_Instance_Names;
        std::vector<std::string> Open_Channel_Instance_Names;
};
