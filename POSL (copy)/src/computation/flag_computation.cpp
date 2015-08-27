#include "flag_computation.h"

Computation FlagSequentialComputation::computation()
{
    return SEQ;
}

FlagParallelComputation::FlagParallelComputation(int procA, int procB)
    : ProcessA(procA),
      ProcessB(procB)
{}

Computation FlagParallelComputation::computation()
{
    return PAR;
}
