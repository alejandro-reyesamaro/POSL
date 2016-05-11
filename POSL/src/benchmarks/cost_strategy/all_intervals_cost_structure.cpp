#include "all_intervals_cost_structure.h"
#include "../../tools/tools.h"

#include <algorithm>

using namespace std;

int cost(vector<int> & occurrences, int size)
{
    int r = 0, i;
    for(i = 1; i < size; i++)
        if (occurrences[i] == 0)
            r += i;
    return r;
}

int cost_of_solution(vector<int> & occurrences, vector<int> & configuration, int size)
{
    int i;
    //memset(nb_occ, 0, size * sizeof(int));
    fill(occurrences.begin(), occurrences.end(), 0);

    for(i = 0; i < size - 1; i++)
        occurrences[abs(configuration[i] - configuration[i + 1])]++;

    //if (Is_Trivial_Solution(sol, size))
    //    return size;

    return cost(occurrences, size);
}

AllIntervalsCostStructure::AllIntervalsCostStructure(int _n)
    : N(_n),
      CurrentCost(0),
      Configuration(_n),
      nb_occ(_n),
      nb_occ_aux(_n),
      rand(make_shared<Randomizer>(_n))
{}

int AllIntervalsCostStructure::relative_cost(vector<int> & new_config, T_Changes, bool updating)
{
    if(updating)
    {
        init(new_config);
        return CurrentCost;
    }
    else
        return cost_of_solution(nb_occ_aux, new_config, N);
}

void AllIntervalsCostStructure::init(vector<int> config)
{
    Configuration = config;
    CurrentCost = cost_of_solution(nb_occ, Configuration, N);
}

int AllIntervalsCostStructure::costOnVariable(int)
{
    return 0;
}

void AllIntervalsCostStructure::reset()
{
    int dist_min = N - 3;	/* size - 1 also works pretty well */
    int i, j, x;

    for(i = 1; i < N; i++)
    {
        if (abs(Configuration[i - 1] - Configuration[i]) >= dist_min)
        {
            j = rand->NextInt(0, N-1);//Random(size);
            x = Configuration[i];
            Configuration[i] = Configuration[j];
            Configuration[j] = x;
        }
    }
}
