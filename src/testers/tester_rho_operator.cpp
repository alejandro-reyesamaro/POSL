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
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    shared_ptr<Solution> sol = make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), Tester::Golfers_442_c4());

    shared_ptr<CompoundModule> cm1(make_shared<OM_FixedFirstConfiguration>(bench));
    shared_ptr<CompoundModule> cm2(make_shared<OM_RandomConfGeneration>(bench));

    // cm1 (rho) cm2 :
    shared_ptr<Operator> op1(make_shared<RhoOperator>(cm1, cm2, 0.5));

    // [cm1 (rho) cm2] :
    shared_ptr<GroupedComputation> G1(make_shared<GroupedSequentialComputation>(op1));

    int c = 0, cc = 0, i = 0;
    for(i = 0; i < 1000; i++)
    {
        bench->SetDefaultConfiguration(sol->get_conf_by_ref());
        shared_ptr<Solution> solution = static_pointer_cast<Solution>(G1->execute(psp, t_seed));
        if(solution->equal(sol)) c++; else cc++;
    }

    string prefix = "rate: 500-" + Tools::int2str(c);
    return (cc <= c+cc) ? prefix + " -> RhoOperator: OK !" : "RhoOperator: fail :/";
}
