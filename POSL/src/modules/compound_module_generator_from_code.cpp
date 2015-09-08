#include "compound_module_generator_from_code.h"

CompoundModuleGeneratorFromCode::CompoundModuleGeneratorFromCode(string code, Benchmark * bench)
    : m_uncoder(new ModuleUncoder()),
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
