#include "n_queens_cost_structure.h"

#include <algorithm>

using namespace std;

#define PENALIZATION 10
#define D1(i, j)      (i + N-1 - j)
#define D2(i, j)      (i + j)
#define ErrD1(i, j)   (err_d1[D1(i, j)])
#define ErrD2(i, j)   (err_d2[D2(i, j)])

NQueensCostStructure::NQueensCostStructure(int n)
    : N(n), CurrentCost(0), Configuration(n),
      nb_diag(2 * n - 1),
      err_d1(2 * n - 1, 0),
      err_d2(2 * n - 1, 0),
      flags(n,0)
{}

void NQueensCostStructure::set(vector<int> _configuration)
{
    copy(_configuration.begin(), _configuration.end(), Configuration.begin());

    fill(err_d1.begin(), err_d1.end(), 0);
    fill(err_d2.begin(), err_d2.end(), 0);

    int j;
    for(int i = 0; i < N; i++)
    {
        j = _configuration[i];
        ErrD1(i, j)++;
        ErrD2(i, j)++;
    }

    int er, r = 0;
    for (int d = 1; d < nb_diag - 1; d++)
    {
        er = err_d1[d];
        r += F(er);

        er = err_d2[d];
        r += F(er);
    }
    CurrentCost = r;

    //tener en cuenta el caso en que haya alguno repetido :P
    fill(flags.begin(), flags.end(), 0);
    for(vector<int>::iterator it = _configuration.begin(); it != _configuration.end(); ++it)
        if(++flags[_configuration[*it]] > 1)
            CurrentCost += N/2;
}

int NQueensCostStructure::relative_cost(vector<int> new_config, T_Changes change, bool updating)
{
    int pos_change;
    int new_value;
    int current_value;
    int cost = 0;
    for(unsigned int i = 0; i < change.dim; i++)
    {
        pos_change = change.positions[i];
        new_value = new_config[pos_change];
        current_value = Configuration[pos_change];
        ErrD1(pos_change, current_value)--;
        ErrD1(pos_change, new_value)++;
        ErrD2(pos_change, current_value)--;
        ErrD2(pos_change, new_value)++;
    }

    int er, r = 0;
    for (int d = 1; d < nb_diag - 1; d++)
    {
        er = err_d1[d];
        r += F(er);

        er = err_d2[d];
        r += F(er);
    }
    cost = r;

    //tener en cuenta el caso en que haya alguno repetido :P
    fill(flags.begin(), flags.end(), 0);
    for(vector<int>::iterator it = new_config.begin(); it != new_config.end(); ++it)
        if(++flags[new_config[*it]] > 1)
            cost += N/2;

    if(updating)
    {
        copy(new_config.begin(), new_config.end(), Configuration.begin());
        CurrentCost = cost;
    }
    else
        for(unsigned int i = 0; i < change.dim; i++)
        {
            pos_change = change.positions[i];
            new_value = new_config[pos_change];
            current_value = Configuration[pos_change];
            ErrD1(pos_change, current_value)++;
            ErrD1(pos_change, new_value)--;
            ErrD2(pos_change, current_value)++;
            ErrD2(pos_change, new_value)--;
        }
    return cost;
}
