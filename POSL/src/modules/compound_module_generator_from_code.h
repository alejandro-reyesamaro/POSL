#pragma once

#include "compound_module.h"
#include "../operators/operator.h"
#include "../expressions/boolean_expression.h"
#include "../packing/module_uncoder.h"

using namespace std;

class CompoundModuleGeneratorFromCode : public CompoundModule
{
    public:
        CompoundModuleGeneratorFromCode(string code, Benchmark * bench);
        shared_ptr<ComputationData> execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input);
        //! From Codable
        string codeToSend();

    private:
        shared_ptr<CompoundModule> generateFrom(string code, shared_ptr<Benchmark> bench);

        shared_ptr<ModuleUncoder> m_uncoder;
        shared_ptr<CompoundModule> module;
        string mycode;        
};
