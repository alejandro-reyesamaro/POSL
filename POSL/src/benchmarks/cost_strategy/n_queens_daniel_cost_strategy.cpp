#include "n_queens_daniel_cost_strategy.h"

#include <algorithm>

using namespace std;
/*
#define PENALIZATION 10
#define D1(i, j)      (i + N-1 - j)
#define D2(i, j)      (i + j)
#define ErrD1(i, j)   (err_d1[D1(i, j)])
#define ErrD2(i, j)   (err_d2[D2(i, j)])

int F(int x){ return (x <= 1) ? 0 : x; }
*/

NQueensDanielCostStrategy::NQueensDanielCostStrategy(int n)
    : N(n),
      nq_str(make_shared<NQueensCostStructure>(n))
      //err_d1(2 * n - 1, 0),
      //err_d2(2 * n - 1, 0),
      //flags(n,0)
{}

int NQueensDanielCostStrategy::solutionCost(std::vector<int> configuration)
{
    nq_str->set(configuration);
    return nq_str->CurrentCost;
    /*
    int nb_diag = 2 * N - 1;
    //memset(err_d1, 0, nb_diag * sizeof(int));
    //vector<int> err_d1(nb_diag, 0);
    fill(err_d1.begin(), err_d1.end(), 0);

    //memset(err_d2, 0, nb_diag * sizeof(int));
    //vector<int> err_d2(nb_diag, 0);
    fill(err_d2.begin(), err_d2.end(), 0);

    int j;
    for(int i = 0; i < N; i++)
    {
        j = configuration[i];
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
    //return r;
    int cost = r;

    //tener en cuenta el caso en que haya alguno repetido :P
    //vector<unsigned int> flags(N,0);
    fill(flags.begin(), flags.end(), 0);
    for(vector<int>::iterator it = configuration.begin(); it != configuration.end(); ++it)
        if(++flags[configuration[*it]] > 1)
            cost += N/2;
    return cost;
    */
}
