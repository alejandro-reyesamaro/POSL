#include "om_random_selection.h"
#include "../data/decision_pair.h"
#include "../data/neighborhood.h"

OM_RandomSelection::OM_RandomSelection() : rand()
{}

ComputationData * OM_RandomSelection::execute(PSP *psp, ComputationData * input)
{
    //DecisionPair * pair = (DecisionPair *) input;
    Neighborhood * V = (Neighborhood *) input;

    Solution * current_solution = psp->GetCurrentSolution();

    int neighSize = V->size();
    int index = rand.NextInt(0, neighSize);

    Solution * new_solution = new Solution(current_solution->domains, V->operator[](index));

    DecisionPair * p = new DecisionPair(current_solution, new_solution);
    return p;
}
