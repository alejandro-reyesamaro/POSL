#pragma once

#include "../solver/posl_solver.h"
#include "../tools/hash_map.h"

class POSL_DeclarationUncoder
{
    public:
        POSL_DeclarationUncoder();
        HashMap<std::string, std::shared_ptr<POSL_Solver> > uncode(std::vector<std::string> vcode,
                                                                   std::shared_ptr<Benchmark> bench);
                                                                   //shared_ptr<SearchProcessParamsStruct> psp_params);
};
