#include "speed_sequential_strategy.h"
#include "../../data/neighborhood.h"
#include "../../data/union_neighborhood.h"
#include "../../tools/chronometer.h"

#include <iostream>

SpeedSequentialStrategy::SpeedSequentialStrategy(CompoundModule *_M1, CompoundModule *_M2)
    : M1(_M1), M2(_M2)
{}

ComputationData * SpeedSequentialStrategy::evaluate(PSP *psp, ComputationData * input)
{
    Chronometer * chro = new Chronometer();
    chro->start();
    ComputationData * r1 = M1->execute(psp, input);
    chro->stop();
    int time1 = chro->TimeMiliseconds();
    chro->reset();
    chro->start();
    ComputationData * r2 = M2->execute(psp, input);
    chro->stop();
    int time2 = chro->TimeMiliseconds();

    if (r1 == NULL) return r2;
    if (r2 == NULL) return r1;
    return (time1 <= time2) ? r1 : r2;
}
