#include "tester_rho_operator.h"
#include "../modules/om_fixed_first_configuration.h"
#include "../modules/om_random_conf_generation.h"
#include "../operators/operator.h"
#include "../operators/rho_operator.h"
#include "../modules/grouped_computation.h"
#include "../modules/grouped_sequential_computation.h"
#include "../tools/tools.h"

Tester_RhoOperator::Tester_RhoOperator(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_RhoOperator::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    shared_ptr<Solution> sol(make_shared<Solution>(bench->Domains()));
    bench->UpdateSolution(sol);
    shared_ptr<PSP> psp(make_shared<PSP>(ARGC, ARGV, bench));

    vector<int> config(
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

    sol(make_shared<Solution>(psp->GetBenchmark()->Domains(), config));
    //bench->UpdateSolution(sol);
    //PSP> psp(make_shared<PSP(bench);
    psp->UpdateSolution(sol);

    shared_ptr<CompoundModule> cm1(make_shared<OM_FixedFirstConfiguration>(bench));
    shared_ptr<CompoundModule> cm2(make_shared<OM_RandomConfGeneration>(bench));

    // cm1 (rho) cm2 :
    shared_ptr<Operator> op1(make_shared<RhoOperator>(cm1, cm2, 0.5));

    // [cm1 (rho) cm2] :
    shared_ptr<GroupedComputation> G1(make_shared<GroupedSequentialComputation>(op1));

    int c = 0, cc = 0, i = 0;
    for(i = 0; i < 1000; i++)
    {
        shared_ptr<Solution> solution = static_pointer_cast<Solution>(G1->execute(psp, sol));
        if(solution->equal(sol)) c++; else cc++;
    }

    string prefix = "rate: 500-" + Tools::int2str(c);
    return (cc <= c+cc) ? prefix + " -> RhoOperator: OK !" : "RhoOperator: fail :/";
}
