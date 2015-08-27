#include "golomb_ruler.h"
#include "../tools/long_int.h"
#include "../data/dStrategy/factory_n_int_domain.h"

#define PENALIZATION 10

GolombRuler::GolombRuler(int _order, int _length)
    : order(_order), length(_length)
{}

vector<Domain> GolombRuler::Domains()
{
    FactoryDomain * fd_integers = new Factory_NIntDomain(0, length);
    Domain D(fd_integers);
    vector<Domain> domains (order, D);
    return domains;
}

int GolombRuler::solutionCost(Solution * sol)
{
    int table_length = length / 32 + 1;
    LongInt * measures = new LongInt(table_length, 0);
    vector<int> conf = sol->GetConfiguration();

    int cost = 0, penalty = 0;

    for(int i = 0; i < order - 1; i++)
        for(int j = i + 1; j < order; j++)
        {
            int distance = conf[j] - conf[i];
            if (distance <= 0)
                penalty ++;
            measures->activate(distance);
        }
    int not_measured = length - measures->bitCount();
    if(conf[0] != 0)
        penalty += PENALIZATION * PENALIZATION;
    if(conf[order - 1] != length)
        penalty += PENALIZATION * PENALIZATION;
    cost = not_measured + penalty * PENALIZATION;
    return cost;
}

int GolombRuler::Order()
{
    return order;
}

int GolombRuler::Length()
{
    return length;
}

string GolombRuler::ShowSolution(Solution * solution)
{

    string output = "";
    if(order == 6 and length == 17) output = "(6-17:2) ";
    else if(order == 7 and length == 25) output = "(7-25:4) ";
    else if(order == 8 and length == 34) output = "(8-34:7) ";
    else if(order == 12 and length == 85) output = "(12-85:20) ";

    return output + solution->configurationToString();
    //return solution->configurationToString();
}
