#include "executer.h"

Executer::Executer(shared_ptr<CompoundModule> _M)
    : output(nullptr),
      M(_M)
{}

void Executer::execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    output = M->execute(psp, input);
}

shared_ptr<ComputationData> Executer::GetOutput()
{
    return output;
}
