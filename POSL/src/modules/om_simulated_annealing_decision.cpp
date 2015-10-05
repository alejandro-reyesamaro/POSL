#include "om_simulated_annealing_decision.h"
#include "../data/decision_pair.h"

#include <chrono>
#include <math.h>

#define P_START 0.5
#define FALL_RATE 2
#define MAX_ITER_PER_T 5

using namespace std;

OM_SimulatedAnnealingDecision::OM_SimulatedAnnealingDecision()
    :   rand(),
        started(false),
        M(MAX_ITER_PER_T),
        m(0)
{}

shared_ptr<Solution> OM_SimulatedAnnealingDecision::spcf_execute(shared_ptr<PSP> psp, shared_ptr<DecisionPair> input)
{

    int wp = psp->GetBenchmark()->solutionCost(input->GetFound());
    int w = psp->GetBenchmark()->solutionCost(input->GetCurrent());

    if(wp == 0) return input->GetFound();

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
    {
        psp->UpdateSolution(input->GetFound()->GetConfiguration());
        return input->GetFound();
    }
    else
    {
        psp->UpdateSolution(input->GetCurrent()->GetConfiguration());
        return input->GetCurrent();
    }
}

string OM_SimulatedAnnealingDecision::codeToSend()
{
    return "D2";
}

string OM_SimulatedAnnealingDecision::TAG()
{
    return "SA_decission";
}
