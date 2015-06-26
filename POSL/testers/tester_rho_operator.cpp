#include "tester_rho_operator.h"
#include "modules/om_fixed_first_configuration.h"
#include "modules/om_random_conf_generation.h"
#include "operators/operator.h"
#include "operators/rho_operator.h"
#include "modules/grouped_computation.h"
#include "modules/grouped_sequential_computation.h"
#include "computation/tools.h"

Tester_RhoOperator::Tester_RhoOperator()
{
}

string Tester_RhoOperator::test()
{
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

    Solution * sol = new Solution(bench->GetSolution()->domains, config);
    //bench->UpdateSolution(sol);
    PSP * psp = new PSP(bench);
    psp->UpdateSolution(sol);

    CompoundModule * cm1 = new OM_FixedFirstConfiguration();
    CompoundModule * cm2 = new OM_RandomConfGeneration();

    // cm1 (rho) cm2 :
    Operator * op1 = new RhoOperator(cm1, cm2, 0.5);

    // [cm1 (rho) cm2] :
    GroupedComputation * G1 = new GroupedSequentialComputation(op1);

    int c = 0, cc = 0, i = 0;
    for(i = 0; i < 1000; i++)
    {
        Solution * solution = (Solution *)G1->execute(psp, sol);
        if(solution->equal(sol)) c++; else cc++;
    }

    string prefix = "rate: 500-" + Tools::int2str(c);
    return (cc <= c+cc) ? prefix + " -> RhoOperator: OK !" : "RhoOperator: fail :/";
}
