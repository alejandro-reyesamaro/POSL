#include "executer.h"

Executer::Executer(CompoundModule * _M)
    : output(nullptr),
      M(_M)
{}

void Executer::execute(PSP *psp, ComputationData * input)
{
    output = M->execute(psp, input);
}

ComputationData * Executer::GetOutput()
{
    return output;
}
