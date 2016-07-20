#include "om_simulated_annealing_decision.h"
#include "../data/decision_pair.h"
#include "../tools/tokens_definition.h"

#include <chrono>
#include <math.h>
#include <iostream>

#define EPS 0.02

using namespace std;

OM_SimulatedAnnealingDecision::OM_SimulatedAnnealingDecision(double _start_probability, double _fall_rate, double _temperature_itereations)
    : started(false),
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
    if(found_solution_cost == 0)
    {
        psp->UpdateSolution(input->GetFound()->get_conf_by_ref());
        return input->GetFound();
    }
    //cout << found_solution_cost << endl;
    //cout << current_solution_cost << endl;
    relative_difference_cost = max(abs((double)found_solution_cost - (double)current_solution_cost)/abs((double)found_solution_cost), EPS);
    //cout << relative_difference_cost << endl;
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
    //cout << "T=" << T << endl;
    current_probability = ((double)exp( - (relative_difference_cost) /   T )) * 10;

    int k = psp->GetRandomizer()->NextInt(0, 10);

    //cout << current_probability << endl;
    //out << "--" << endl;
    if(k >= current_probability)
    {
        //cout << "good" << endl;
        psp->UpdateSolution(input->GetFound()->get_conf_by_ref());
        return input->GetFound();
    }
    else
    {
        //cout << current_probability << " :/" << endl;
        psp->UpdateSolution(input->GetCurrent()->get_conf_by_ref());
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
