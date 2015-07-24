#include "compound_module_generator_from_code.h"
#include "../packing/uncode_compound_module_strategy.h"

CompoundModuleGeneratorFromCode::CompoundModuleGeneratorFromCode(string code)
    : module(generateFrom(code)),
      mycode(code)
{}

ComputationData * CompoundModuleGeneratorFromCode::execute(PSP * psp, ComputationData * input)
{
    return module->execute(psp, input);
}

CompoundModule * CompoundModuleGeneratorFromCode::generateFrom(string code)
{
    UncodeCompoundModuleStrategy * cm_strategy = new UncodeCompoundModuleStrategy();
    return cm_strategy->uncode(code);
}

string CompoundModuleGeneratorFromCode::codeToSend()
{
    return mycode;
}
