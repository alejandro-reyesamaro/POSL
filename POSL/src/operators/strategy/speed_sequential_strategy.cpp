#include "speed_sequential_strategy.h"
#include "../../data/neighborhood.h"
#include "../../data/union_neighborhood.h"

#include <iostream>

SpeedSequentialStrategy::SpeedSequentialStrategy(CompoundModule *_M1, CompoundModule *_M2)
    : M1(_M1), M2(_M2),
      chro(new Chronometer()),
      result1(nullptr),
      result2(nullptr)
{}

ComputationData * SpeedSequentialStrategy::evaluate(PSP *psp, ComputationData * input)
{
    chro->reset();
    chro->start();
    result1 = M1->execute(psp, input);
    chro->stop();
    int time1 = chro->TimeMiliseconds();
    chro->reset();
    chro->start();
    result2 = M2->execute(psp, input);
    chro->stop();
    int time2 = chro->TimeMiliseconds();

    if (result1 == nullptr) return result2;
    if (result2 == nullptr) return result1;
    return (time1 <= time2) ? result1 : result2;
}