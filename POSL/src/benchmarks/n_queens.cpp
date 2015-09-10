#include "n_queens.h"
#include "../tools/tools.h"
#include "../data/dStrategy/factory_n_int_domain.h"
#include "cost_strategy/n_queens_daniel_cost_strategy.h"

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

NQueens::NQueens(int n)
    : Benchmark(vector<Domain>(n, Domain(std::make_shared<Factory_NIntDomain>(0, n-1))), make_shared<NQueensDanielCostStrategy>(n)),
      N(n)
{}

int NQueens::solutionCost(std::vector<int> configuration)
{
    return cost_strategy->solutionCost(configuration);
}

std::string NQueens::ShowSolution(std::shared_ptr<Solution> solution)
{
    if(N > 20)
        return Tools::int2str(N) +"-Queens: " + solution->configurationToString();

    std::string out = "";
    std::vector<int> config = solution->GetConfiguration();

    // TRANSPOSING
    std::vector<int> T(N,0);
    for(std::vector<int>::iterator it = config.begin(); it != config.end(); ++it)
        T[*it] = *it;
    //------------

    for(std::vector<int>::iterator it = config.begin(); it != config.end(); ++it)
    {
        int pos = *it;
        for(int i = 0; i < N; i ++)
            out +=(i != pos)? "0 " : "X ";
        out += "\n";
    }
    return out;
}
