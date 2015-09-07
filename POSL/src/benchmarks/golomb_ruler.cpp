#include "golomb_ruler.h"
#include "../data/dStrategy/factory_n_int_domain.h"

#define PENALIZATION 10

GolombRuler::GolombRuler(int _order, int _length)
    : Benchmark(vector<Domain>(_order, Domain(new Factory_NIntDomain(0, _length)))),
      order(_order),
      length(_length),
      measures(_length / 32 + 1, 0)
{}

int GolombRuler::solutionCost(vector<int> configuration)
{
    measures.deactivateAll(); //measures.clearBits();// = new LongInt(table_length, 0);
    //vector<int> conf = sol->GetConfiguration();
    int cost = 0, penalty = 0;

    for(int i = 0; i < order - 1; i++)
        for(int j = i + 1; j < order; j++)
        {
            int distance = configuration[j] - configuration[i];
            if (distance <= 0)
                penalty ++;
            measures.activate(distance);
        }
    int not_measured = length - measures.bitCount();
    if(configuration[0] != 0)
        penalty += PENALIZATION * PENALIZATION;
    if(configuration[order - 1] != length)
        penalty += PENALIZATION * PENALIZATION;
    cost = not_measured + penalty * PENALIZATION;
    return cost;
}

int GolombRuler::Order(){ return order; }

int GolombRuler::Length(){ return length; }

string GolombRuler::ShowSolution(Solution * solution)
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
    //return solution->configurationToString();
}
