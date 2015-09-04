#include "compound_module_generator_from_code.h"

CompoundModuleGeneratorFromCode::CompoundModuleGeneratorFromCode(string code, Benchmark * bench)
    : cm_strategy(new UncodeCompoundModuleStrategy()),
      module(generateFrom(code, bench)),
      mycode(code)
{}

ComputationData * CompoundModuleGeneratorFromCode::execute(PSP * psp, ComputationData * input)
{
    return module->execute(psp, input);
}

CompoundModule * CompoundModuleGeneratorFromCode::generateFrom(string code, Benchmark * bench)
{
    return cm_strategy->uncode(code, bench);
}

string CompoundModuleGeneratorFromCode::codeToSend()
{
    return mycode;
}
