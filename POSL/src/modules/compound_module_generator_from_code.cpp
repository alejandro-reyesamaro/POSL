#include "compound_module_generator_from_code.h"

CompoundModuleGeneratorFromCode::CompoundModuleGeneratorFromCode(string code, Benchmark * bench)
    : m_uncoder(new ModuleUncoder()),
      module(generateFrom(code, bench)),
      mycode(code)
{}

ComputationData * CompoundModuleGeneratorFromCode::execute(PSP * psp, ComputationData * input)
{
    return module->execute(psp, input);
}

CompoundModule * CompoundModuleGeneratorFromCode::generateFrom(string code, Benchmark * bench)
{
    return m_uncoder->uncodeCompoundModule(code, bench);
}

string CompoundModuleGeneratorFromCode::codeToSend()
{
    return mycode;
}
