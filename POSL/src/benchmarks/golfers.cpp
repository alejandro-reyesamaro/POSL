#include "golfers.h"
#include "../tools/tools.h"
#include "../data/dStrategy/factory_n_int_domain.h"
#include "cost_strategy/golfers_intersections_costs_trategy.h"
#include "cost_strategy/golfers_long_int_cost_strategy.h"
#include "cost_strategy/golfers_3pn_cost_strategy.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define PENALIZATION 10
#define TL p * g / 32 + 1

Golfers::Golfers(int g, int p, int w)
    : Benchmark(vector<Domain>(g * p * w, Domain(make_shared<Factory_NIntDomain>(1,p * g))), make_shared<GolfersLongIntCostStrategy>(g,p,w)),
      groups(g),
      players(p),
      weeks(w)
{}

int Golfers::solutionCost(vector<int> configuration)
{
    return cost_strategy->solutionCost(configuration);
}

string Golfers::ShowSolution(shared_ptr<Solution> solution)
{
    string out =  "Golfers: players-" + Tools::int2str(players);
           out += ", groups-" + Tools::int2str(groups);
           out += ", weeks-" + Tools::int2str(weeks) + "\n";
    vector<int> config = solution->GetConfiguration();
    vector<int>::iterator it = config.begin();
    for(int w = 0; w < weeks; w ++)
    {
        for(int g = 0; g < groups; g ++)
        {
            for(int p = 0; p < players; p ++)
            {
                int value = *it;
                out += Tools::int2str(value) + "\t";
                it ++;
            }
            out += "\n";
        }
        out += "--\n";
    }
    return out;
}
