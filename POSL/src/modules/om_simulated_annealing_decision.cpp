#include "om_simulated_annealing_decision.h"
#include "../data/decision_pair.h"
#include "../tools/tokens_definition.h"

#include <chrono>
#include <math.h>
#include <iostream>

#define P_START 0.7         // Probability to start choosing bad configurations
#define FALL_RATE 0.8
#define MAX_ITER_PER_T 5

using namespace std;

OM_SimulatedAnnealingDecision::OM_SimulatedAnnealingDecision(double _start_probability, double _fall_rate, double _temperature_itereations)
    : rand(),
      started(false),
      start_probability(_start_probability),
      fall_rate(_fall_rate),
      temperature_iterations(_temperature_itereations),
      relative_iteration_counter(0),
      current_probability(0)
{}

shared_ptr<Solution> OM_SimulatedAnnealingDecision::spcf_execute(shared_ptr<PSP> psp, shared_ptr<DecisionPair> input)
{
    found_solution_cost = psp->GetBenchmark()->solutionCost(input->GetFound()); //wp
    current_solution_cost = psp->GetBenchmark()->solutionCost(input->GetCurrent()); //w
    if(found_solution_cost == 0) return input->GetFound();
    cout << found_solution_cost << endl;
    cout << current_solution_cost << endl;
    relative_difference_cost = abs((double)found_solution_cost - (double)current_solution_cost)/abs((double)found_solution_cost);
    cout << relative_difference_cost << endl;
    if(!started)
    {
        started = true;
        // computing T for the first time, depending on the cost difference
        T = -(relative_difference_cost)/log(start_probability);
    }
    // Reducing T when the MAX_ITER_PER_T is reached
    if(++relative_iteration_counter > temperature_iterations)
    {
        relative_iteration_counter = 0;
        T = T * fall_rate;
    }
    cout << "T=" << T << endl;
    current_probability = ((double)exp( - (relative_difference_cost) /   T )) * 10;

    int k = rand.NextInt(0, 10);    

    cout << current_probability << endl;
    cout << "--" << endl;
    if(k >= current_probability)
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
    return OM_SIMULATED_ANNEALING_DECISION_TOK;
}

string OM_SimulatedAnnealingDecision::Tag()
{
    return "SA_decission";
}
