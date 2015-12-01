#pragma once

#include "../solver/posl_solver.h"
#include "../tools/hash_map.h"
#include "connections_declaration.h"

class PoslUncoder
{
    public:
        PoslUncoder();
        HashMap<std::string, std::shared_ptr<POSL_Solver> > uncode_declarations(std::string code, std::shared_ptr<Benchmark> bench);
        std::vector<ConnectionsDeclaration> uncode_connections(std::string code, std::shared_ptr<Benchmark> bench);
        //std::vector<std::shared_ptr<POSL_Solver>> uncode_declarations(std::string code, std::shared_ptr<Benchmark> bench);
};
