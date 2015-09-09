#include "compound_module_generator_from_code.h"

using namespace std;

CompoundModuleGeneratorFromCode::CompoundModuleGeneratorFromCode(string code, shared_ptr<Benchmark> bench)
    : m_uncoder(make_shared<ModuleUncoder>()),
      module(generateFrom(code, bench)),
      mycode(code)
{}

shared_ptr<ComputationData> CompoundModuleGeneratorFromCode::execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    return module->execute(psp, input);
}

shared_ptr<CompoundModule> CompoundModuleGeneratorFromCode::generateFrom(string code, shared_ptr<Benchmark> bench)
{
    return m_uncoder->uncodeCompoundModule(code, bench);
}

string CompoundModuleGeneratorFromCode::codeToSend()
{
    return mycode;
}
