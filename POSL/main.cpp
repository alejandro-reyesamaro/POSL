#include <memory>
#include <vector>
#include <iostream>

#include <sstream>
#include <string>
#include <fstream>

#include "benchmark.h"
#include "golfers.h"
#include "factory_n_int_domain.h"
#include "om_random_conf_generation.h"
#include "om_florian_random_conf_generation.h"

using namespace std;

int main(int argc, char *argv[])
{
    shared_ptr<FactoryDomain> fd_integers = make_shared<Factory_NIntDomain>(1,16);
    Domain D(fd_integers);
    vector<Domain> domains (32,D);
    vector<int> config(
    {
        1,  2,   3,  4,
        5,  6,   7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16,

        13, 10,  7,  4,
        14, 11,  8,  1,
        15, 12,  2,  5,
        16,  3,  6,  9
    });

    vector<int> config2(
    {
        1,  2,   3,  4,
        5,  6,   7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16,

        13, 10,  7,  8,
        14, 11,  4,  1,
        15, 12,  2,  5,
        16,  3,  6,  9
    });

    shared_ptr<Solution> sol = make_shared<Solution>(domains, config2);
    shared_ptr<Benchmark> bench = make_shared<Golfers>(4,4,2);
    float c = bench->solutionCost(sol);
    cout << "Cost : " << c << endl;
    bench->UpdateSolution(sol);
    OperationModule<shared_ptr<Benchmark>, vector<int>> * op1 = new OM_RandomConfGeneration();
    OperationModule<shared_ptr<Benchmark>, vector<int>> * op2 = new OM_FlorianRandomConfGeneration();
    vector<int> rand_conf = op1->execute(bench);
    vector<int> rand_conf2 = op2->execute(bench);

    sol = make_shared<Solution>(domains, rand_conf);
    c = bench->solutionCost(sol);
    cout << "Cost : " << c << endl;

    sol = make_shared<Solution>(domains, rand_conf2);
    c = bench->solutionCost(sol);
    cout << "Cost : " << c << endl;
}
