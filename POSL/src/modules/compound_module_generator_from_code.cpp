#include "compound_module_generator_from_code.h"

#include <iostream>

using namespace std;

CompoundModuleGeneratorFromCode::CompoundModuleGeneratorFromCode(string code,
                                                                 shared_ptr<Benchmark> bench,
                                                                 shared_ptr<SearchProcessParamsStruct> psp_params)
    : m_uncoder(make_shared<CompoundModuleUncoder>()),
      module(generateFrom(code, bench, psp_params)),
      mycode(code)
{}

shared_ptr<ComputationData> CompoundModuleGeneratorFromCode::execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    return module->execute(psp, input);
}

shared_ptr<CompoundModule> CompoundModuleGeneratorFromCode::generateFrom(string code,
                                                                         shared_ptr<Benchmark> bench,
                                                                         shared_ptr<SearchProcessParamsStruct> psp_params)
{    
    return m_uncoder->uncode(code, bench, psp_params);
}

string CompoundModuleGeneratorFromCode::codeToSend()
{
    return mycode;
}
