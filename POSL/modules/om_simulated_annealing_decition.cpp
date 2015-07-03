#include "om_simulated_annealing_decition.h"
#include "data/decision_pair.h"

#include <chrono>
#include <math.h>

OM_SimulatedAnnealingDecition::OM_SimulatedAnnealingDecition()
    :   generator(std::chrono::system_clock::now().time_since_epoch().count()),
        started(false),// , T( ?? )
        M(5), m(0)
{}

ComputationData * OM_SimulatedAnnealingDecition::execute(PSP *psp, ComputationData * input)
{
    DecisionPair * pair = (DecisionPair *) input;

    int wp = psp->GetBenchmark()->solutionCost(pair->GetFound());
    int w = psp->GetBenchmark()->solutionCost(pair->GetCurrent());

    int relative_dif = abs(wp - w)/abs(wp);
    if(!started)
    {
        started = true;
        T = -(relative_dif)/log(0.5); // Probabilidad con que se quiere comenzar a elegir malas configuraciones
    }
    int p = exp( - (relative_dif) /   T ) * 10;

    uniform_int_distribution<int> distribution(0, 10);
    int k = distribution(generator);

    // Si se llega al limites de iteraciones por temperatura, reducir T a la mitad ????
    if(m++ > M)
    {
        m = 0;
        T = T/2;
    }

    if(k < p)
        return pair->GetFound();
    else
        return pair->GetCurrent();
}
