
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
#include "om_one_element_changed_neighborhood.h"
#include "neighborhood.h"
#include "one_element_changed_neighborhood.h"
#include "operator.h"
#include "sequential_exec_operator.h"

using namespace std;

void TEST_CostOfSolution(vector<Domain> domains, vector<int> config);
void TEST_OM_FirstRandomConfiguration_Trivial(vector<Domain> domains);
void TEST_OM_FirstRandomConfiguration_Florian(vector<Domain> domains);
void TEST_OneElementChangedNeighborhood(vector<Domain> domains, vector<int> config);
void TEST_SequentialOperator(vector<Domain> domains);
string returnSTR(int c);
string writeConfiguration(vector<int> conf);

int main(int argc, char *argv[])
{
    FactoryDomain * fd_integers = new Factory_NIntDomain(1,16);
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

    vector<int> config3(
    {
        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,

        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,
    });

    //TEST_CostOfSolution(domains, config2);
    //TEST_OM_FirstRandomConfiguration_Trivial(domains);
    //TEST_OM_FirstRandomConfiguration_Florian(domains);
    //TEST_OneElementChangedNeighborhood(domains, config3);
    TEST_SequentialOperator(domains);
}

void TEST_CostOfSolution(vector<Domain> domains, vector<int> config)
{
    Solution * sol = new Solution(domains, config);
    Benchmark * bench = new Golfers(4,4,2);
    int c = bench->solutionCost(sol);
    cout << "Cost : " + returnSTR(c) << endl;
}

void TEST_OM_FirstRandomConfiguration_Trivial(vector<Domain> domains)
{
    Solution * sol = new Solution(domains);
    Benchmark * bench = new Golfers(4,4,2);
    OperationModule * op1 = new OM_RandomConfGeneration();
    bench->UpdateSolution(sol);
    sol = (Solution *)op1->execute(bench, new Seed());
    bench->UpdateSolution(sol);
    int c = bench->solutionCost(sol);
    cout << "Cost : " + returnSTR(c) << endl;
}

void TEST_OM_FirstRandomConfiguration_Florian(vector<Domain> domains)
{
    Solution * sol = new Solution(domains);
    Benchmark * bench = new Golfers(4,4,2);
    OperationModule * op1 = new OM_FlorianRandomConfGeneration();
    bench->UpdateSolution(sol);
    sol = (Solution *)op1->execute(bench, new Seed());
    bench->UpdateSolution(sol);
    int c = bench->solutionCost(sol);
    cout << "Cost : " + returnSTR(c) << endl;
}

void TEST_OneElementChangedNeighborhood(vector<Domain> domains, vector<int> config)
{
    Solution * sol = new Solution(domains, config);
    Benchmark * bench = new Golfers(4,4,2);

    Neighborhood * V = new OneElementChangedNeighborhood(sol);
    vector<int> conf = (*V)[5];

    POSL_Iterator<vector<int>> * it = V ->getIterator();
    it->Reset();
    while(it->SomeNext())
    {
        vector<int> config = it->GetNext();
        string out = writeConfiguration(config);
        cout << out << endl;
        sol = new Solution(domains, config);
        bench->UpdateSolution(sol);
        int c = bench->solutionCost(sol);
        cout << "Cost : " << returnSTR(c) << endl;
    }
}

void TEST_SequentialOperator(vector<Domain> domains)
{
    Solution * sol = new Solution(domains);
    Benchmark * bench = new Golfers(4,4,2);
    bench->UpdateSolution(sol);

    CompoundModule * cm1 = new OM_FlorianRandomConfGeneration();
    CompoundModule * cm2 = new OM_OneElementChangedNeighborhood();

    Operator * op = new SequentialExecOperator(cm1, cm2);

    Neighborhood * V = (Neighborhood *)op->evaluateSequentially(bench, new Seed());

    POSL_Iterator<vector<int>> * it = V ->getIterator();

    it->Reset();
    while(it->SomeNext())
    {
        vector<int> config = it->GetNext();
        string out = writeConfiguration(config);
        cout << out << endl;
        sol = new Solution(domains, config);
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
