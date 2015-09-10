#include "golomb_ruler.h"
#include "../data/dStrategy/factory_n_int_domain.h"
#include "cost_strategy/golomb_ruler_distances_cost_strategy.h"

using namespace std;

GolombRuler::GolombRuler(int _order, int _length)
    : Benchmark(vector<Domain>(_order, Domain(make_shared<Factory_NIntDomain>(0, _length))), make_shared<GolombRulerDistancesCostStrategy>(_order, _length)),
      order(_order),
      length(_length)
{}

int GolombRuler::solutionCost(vector<int> configuration)
{
    return cost_strategy->solutionCost(configuration);
}

string GolombRuler::ShowSolution(shared_ptr<Solution> solution)
{
    string output = "";
    if(order == 6 and length == 17) output = "(6-17:2) ";
    else if(order == 7 and length == 25) output = "(7-25:4) ";
    else if(order == 8 and length == 34) output = "(8-34:7) ";
    else if(order == 9 and length == 44) output = "(9-44:9) ";
    else if(order == 10 and length == 55) output = "(10-55:11) ";
    else if(order == 11 and length == 72) output = "(11-72:19) ";
    else if(order == 12 and length == 85) output = "(12-85:20) ";
    return output + solution->configurationToString();
}
