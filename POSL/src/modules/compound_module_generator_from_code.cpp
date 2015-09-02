#include "compound_module_generator_from_code.h"
#include "../packing/uncode_compound_module_strategy.h"

CompoundModuleGeneratorFromCode::CompoundModuleGeneratorFromCode(string code, Benchmark * bench)
    : module(generateFrom(code, bench)),
      mycode(code)
{}

ComputationData * CompoundModuleGeneratorFromCode::execute(PSP * psp, ComputationData * input)
{
    return module->execute(psp, input);
}

CompoundModule * CompoundModuleGeneratorFromCode::generateFrom(string code, Benchmark * bench)
{
    UncodeCompoundModuleStrategy * cm_strategy = new UncodeCompoundModuleStrategy();
    return cm_strategy->uncode(code, bench);
}

string CompoundModuleGeneratorFromCode::codeToSend()
{
    return mycode;
}
