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

bool is_trivial_solution(vector<int> & configuration, int size)
{
    return (configuration[0] == 0 ||
            configuration[0] == size - 1 ||
            configuration[size - 1] == 0 ||
            configuration[size - 1] == size - 1);
}

int cost_of_solution(vector<int> & occurrences, vector<int> & configuration, int size)
{
    int i;
    //memset(nb_occ, 0, size * sizeof(int));
    fill(occurrences.begin(), occurrences.end(), 0);

    for(i = 0; i < size - 1; i++)
        occurrences[abs(configuration[i] - configuration[i + 1])]++;

    if (is_trivial_solution(configuration, size))
        return size;

    return cost(occurrences, size);
}

/*
 *  COST_IF_SWAP
 *
 *  Evaluates the new total cost for a swap.
 */
int cost_if_swap(vector<int> & configuration,
                 vector<int> & occurrences,
                 int size, /*int current_cost,*/
                 int index1,
                 int index2)
{
    int s1, s2;
    int rem1, rem2, rem3, rem4;
    int add1, add2, add3, add4;
    int i1 = min(index1, index2);
    int i2 = max(index1, index2);

//#ifdef NO_TRIVIAL
    if ((i1 == 0 && (configuration[i2] == 0 || configuration[i2] == size - 1)) ||
        (i2 == 0 && (configuration[i1] == 0 || configuration[i1] == size - 1)))
        return size;
//#endif

    s1 = configuration[i1];
    s2 = configuration[i2];

    if (i1 > 0)
    {
        rem1 = abs(configuration[i1 - 1] - s1);
        occurrences[rem1]--;
        add1 = abs(configuration[i1 - 1] - s2);
        occurrences[add1]++;
    }
    else
        rem1 = add1 = 0;


    if (i1 < i2 - 1)		/* i1 and i2 are not consecutive */
    {
        rem2 = abs(s1 - configuration[i1 + 1]);
        occurrences[rem2]--;
        add2 = abs(s2 - configuration[i1 + 1]);
        occurrences[add2]++;

        rem3 = abs(configuration[i2 - 1] - s2);
        occurrences[rem3]--;
        add3 = abs(configuration[i2 - 1] - s1);
        occurrences[add3]++;
    }
    else
        rem2 = add2 = rem3 = add3 = 0;

    if (i2 < size - 1)
    {
        rem4 = abs(s2 - configuration[i2 + 1]);
        occurrences[rem4]--;
        add4 = abs(s1 - configuration[i2 + 1]);
        occurrences[add4]++;
    }
    else
        rem4 = add4 = 0;

    int r = cost(occurrences, size);

    /* undo */

    occurrences[rem1]++;
    occurrences[rem2]++;
    occurrences[rem3]++;
    occurrences[rem4]++;
    occurrences[add1]--;
    occurrences[add2]--;
    occurrences[add3]--;
    occurrences[add4]--;

    return r;
}

AllIntervalsCostStructure::AllIntervalsCostStructure(int _n)
    : N(_n),
      CurrentCost(0),
      Configuration(_n),
      nb_occ(_n),
      nb_occ_aux(_n),
      rand(make_shared<Randomizer>(_n, 1))
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

void AllIntervalsCostStructure::init(vector<int> _configuration)
{
    Configuration = _configuration;
    CurrentCost = cost_of_solution(nb_occ, Configuration, N);
}

int AllIntervalsCostStructure::costOnVariable(int index)
{
    //return 0;
    int cost = 0;
    int r;
    for(unsigned int i = 0; i < Configuration.size(); i++)
        if((int)i != index) // cost += cost_if_swap(Configuration, nb_occ, N, CurrentCost, i, index);
        {
            r = cost_if_swap(Configuration, nb_occ, N, /*CurrentCost,*/ i, index);
            if(r > cost)
                cost = r;
        }
    return cost;
}

int AllIntervalsCostStructure::worst_variable()
{
    int w_cost = 0, w_index = 0, r;
    for(unsigned int i = 0; i < Configuration.size(); i++)
    {
        r = costOnVariable(i);
        if (w_cost < r)
        {
            w_cost = r;
            w_index = i;
        }
    }
    return w_index;
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
