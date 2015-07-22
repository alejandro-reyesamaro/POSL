#include "om_simulated_annealing_decition.h"
#include "../data/decision_pair.h"

#include <chrono>
#include <math.h>

#define P_START 0.5
#define FALL_RATE 2

OM_SimulatedAnnealingDecition::OM_SimulatedAnnealingDecition()
    :   rand(),
        started(false),
        M(5), m(0)
{}

ComputationData * OM_SimulatedAnnealingDecition::execute(PSP *psp, ComputationData * input)
{
    DecisionPair * pair = (DecisionPair *) input;

    int wp = psp->GetBenchmark()->solutionCost(pair->GetFound());
    int w = psp->GetBenchmark()->solutionCost(pair->GetCurrent());

    double relative_dif = abs((double)wp - (double)w)/abs((double)wp);

    // Calcular T por primera vez, dependeiendo de la diferencia de los costos
    if(!started)
    {
        started = true;
        T = -(relative_dif)/log(0.5); // Probabilidad con que se quiere comenzar a elegir malas configuraciones
    }
    int p = exp( - (relative_dif) /   T ) * 10;

    int k = rand.NextInt(0, 10);

    // Si se llega al limites de iteraciones por temperatura, reducir T a la mitad ????
    if(m++ > M)
    {
        m = 0;
        T = T / FALL_RATE;
    }

    if(k < p)
        return pair->GetFound();
    else
        return pair->GetCurrent();
}
