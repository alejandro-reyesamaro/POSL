#include "n_queens.h"
#include "../tools/long_int.h"
#include "../tools/tools.h"
#include "../data/dStrategy/factory_n_int_domain.h"

#include <vector>
#include <iostream>

using namespace std;

#define PENALIZATION 10

#define D1(i, j)      (i + N-1 - j)
#define D2(i, j)      (i + j)
#define ErrD1(i, j)   (err_d1[D1(i, j)])
#define ErrD2(i, j)   (err_d2[D2(i, j)])

NQueens::NQueens(int n) : N(n)
{}

vector<Domain> NQueens::Domains()
{
    FactoryDomain * fd_integers = new Factory_NIntDomain(0,N-1);
    Domain D(fd_integers);
    vector<Domain> domains (N, D);
    return domains;
}

int F(int x){ return (x <= 1) ? 0 : x; }

int NQueens::solutionCost(Solution * sol)
{
    vector<int> config = sol->GetConfiguration();

    int nb_diag = 2 * N - 1;
    //memset(err_d1, 0, nb_diag * sizeof(int));
    vector<int> err_d1(nb_diag, 0);

    //memset(err_d2, 0, nb_diag * sizeof(int));
    vector<int> err_d2(nb_diag, 0);

    int j;
    for(int i = 0; i < N; i++)
    {
        j = config[i];
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
    vector<unsigned int> flags(N,0);
    for(vector<int>::iterator it = config.begin(); it != config.end(); ++it)
        if(++flags[config[*it]] > 1)
            cost += N/2;
    return cost;
}

int NQueens::Order(){ return N; }

string NQueens::ShowSolution(Solution * solution)
{
    if(N > 20)
        return Tools::int2str(N) +"-Queens: " + solution->configurationToString();

    string out = "";
    vector<int> config = solution->GetConfiguration();

    // TRANSPOSING
    vector<int> T(N,0);
    for(vector<int>::iterator it = config.begin(); it != config.end(); ++it)
        T[*it] = *it;
    //------------

    for(vector<int>::iterator it = config.begin(); it != config.end(); ++it)
    {
        int pos = *it;
        for(int i = 0; i < N; i ++)
            out +=(i != pos)? "0 " : "X ";
        out += "\n";
    }
    return out;
}
