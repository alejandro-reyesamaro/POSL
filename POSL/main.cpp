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
#include "neighborhood.h"
#include "one_element_changed_neighborhood.h"

using namespace std;

string TEST_CostOfSolution(vector<Domain> domains, vector<int> config);
string TEST_OM_FirstRandomConfiguration_Trivial(vector<Domain> domains);
string TEST_OM_FirstRandomConfiguration_Florian(vector<Domain> domains);
void TEST_OneElementChangedNeighborhood(vector<Domain> domains, vector<int> config);
string returnSTR(int c);
string writeConfiguration(vector<int> conf);

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

    TEST_OneElementChangedNeighborhood(domains, config2);
}

string TEST_CostOfSolution(vector<Domain> domains, vector<int> config)
{
    shared_ptr<Solution> sol = make_shared<Solution>(domains, config);
    shared_ptr<Benchmark> bench = make_shared<Golfers>(4,4,2);
    int c = bench->solutionCost(sol);
    return "Cost : " + returnSTR(c);
}

string TEST_OM_FirstRandomConfiguration_Trivial(vector<Domain> domains)
{
    shared_ptr<Solution> sol = make_shared<Solution>(domains);
    shared_ptr<Benchmark> bench = make_shared<Golfers>(4,4,2);
    OperationModule<shared_ptr<Benchmark>, vector<int>> * op1 = new OM_RandomConfGeneration();
    vector<int> rand_conf = op1->execute(bench);
    sol->configuration = rand_conf;
    bench->UpdateSolution(sol);
    int c = bench->solutionCost(sol);
    return "Cost : " + returnSTR(c);
}

string TEST_OM_FirstRandomConfiguration_Florian(vector<Domain> domains)
{
    shared_ptr<Solution> sol = make_shared<Solution>(domains);
    shared_ptr<Benchmark> bench = make_shared<Golfers>(4,4,2);
    OperationModule<shared_ptr<Benchmark>, vector<int>> * op1 = new OM_FlorianRandomConfGeneration();
    vector<int> rand_conf = op1->execute(bench);
    sol->configuration = rand_conf;
    bench->UpdateSolution(sol);
    int c = bench->solutionCost(sol);
    return "Cost : " + returnSTR(c);
}

void TEST_OneElementChangedNeighborhood(vector<Domain> domains, vector<int> config)
{
    shared_ptr<Solution> sol = make_shared<Solution>(domains, config);
    shared_ptr<Benchmark> bench = make_shared<Golfers>(4,4,2);

    Neighborhood * V = new OneElementChangedNeighborhood(sol);
    vector<int> conf = (*V)[5];

    POSL_Iterator<vector<int>> * it = V ->getIterator();
    it->Reset();
    while(it->SomeNext())
    {
        vector<int> config = it->GetNext();
        string out = writeConfiguration(config);
        cout << out << endl;
        sol = make_shared<Solution>(domains, config);
        bench->UpdateSolution(sol);
        int c = bench->solutionCost(sol);
        cout << "Cost : " << returnSTR(c) << endl;
    }
}

string returnSTR(int c)
{
    ostringstream ss;
    ss << c;
    std::string s(ss.str());
    return s;
}

string writeConfiguration(vector<int> conf)
{
    string txt = "[ ";
    vector<int>::iterator it = conf.begin();
    txt += returnSTR(*it);
    it++;
    while ( it != conf.end())
    {
        txt += ", " + returnSTR(*it);
        ++it;
    }
    return txt + " ]";
}
