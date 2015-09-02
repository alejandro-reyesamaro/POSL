#pragma once

#include "compound_module.h"
#include "../operators/operator.h"
#include "../expressions/boolean_expression.h"

using namespace std;

class CompoundModuleGeneratorFromCode : public CompoundModule
{
    public:
        CompoundModuleGeneratorFromCode(string code, Benchmark * bench);
        ComputationData * execute(PSP * psp, ComputationData * input);
        //! From Codable
        string codeToSend();

    private:
        CompoundModule * generateFrom(string code, Benchmark * bench);
        CompoundModule * module;
        string mycode;
};
