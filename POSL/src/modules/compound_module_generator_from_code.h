#pragma once

#include "compound_module.h"
#include "../operators/operator.h"
#include "../expressions/boolean_expression.h"
#include "../packing/uncode_compound_module_strategy.h"

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

        UncodeCompoundModuleStrategy * cm_strategy;
        CompoundModule * module;
        string mycode;        
};
