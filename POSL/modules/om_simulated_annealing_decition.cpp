#include "om_simulated_annealing_decition.h"
#include "data/decision_pair.h"

OM_SimulatedAnnealingDecition::OM_SimulatedAnnealingDecition()
{}

ComputationData * OM_SimulatedAnnealingDecition::execute(PSP *psp, ComputationData * input)
{
    DecisionPair * pair = (DecisionPair *) input;

    simulated annealing, leer bien como hacer esto :D
    return pair->GetFound();
}
