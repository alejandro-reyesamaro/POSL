#include "executer.h"

using namespace std;

Executer::Executer(shared_ptr<CompoundModule> _M)
    : M(_M),
      output(nullptr)
{}

void Executer::execute(shared_ptr<PSP> psp, shared_ptr<ComputationData> input)
{
    output = M->execute(psp, input);
}

shared_ptr<ComputationData> Executer::GetOutput()
{
    return output;
}
