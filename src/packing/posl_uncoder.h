#pragma once

#include "../solver/posl_solver.h"
#include "../tools/hash_map.h"
#include "../connections/connections_declaration.h"

class PoslUncoder
{
    public:
        PoslUncoder();
        HashMap<std::string, std::shared_ptr<POSL_Solver> > uncode_declarations(std::vector<std::string> code,
                                                                                std::shared_ptr<Benchmark> bench);//,
                                                                                //shared_ptr<SearchProcessParamsStruct> psp_params);
        std::vector<ConnectionsDeclaration> uncode_connections(std::string code);
        //std::vector<std::shared_ptr<POSL_Solver>> uncode_declarations(std::string code, std::shared_ptr<Benchmark> bench);
};
