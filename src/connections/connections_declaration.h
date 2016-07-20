#pragma once

#include <string>
#include <vector>

class ConnectionsDeclaration
{
    public:
        std::string Operator_Name;
        std::vector<std::string> Jack_solvers;
        std::vector<std::string> Jacks;
        std::vector<std::string> Outlet_solvers;
        std::vector<std::string> Outlets;
        int TopologySize;
};
