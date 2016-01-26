#include "tester_daniel_restart.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_fixed_first_configuration.h"
#include "../modules/om_daniel_as_restart_rearrange.h"
#include "../modules/grouped_sequential_computation.h"
#include "../operators/sequential_exec_operator.h"

Tester_DanielRestart::Tester_DanielRestart(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_DanielRestart::test()
{
    shared_ptr<Benchmark> bench(make_shared<CostasArray>(15));

    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    //[ 12, 9, 0, 13, 1, 7, 8, 6, 11, 3, 2, 5, 14, 10, 4 ] - [ 13, 10, 1, 14, 2, 8, 9, 7, 12, 4, 3, 6, 15, 11, 5 ]
    vector<int> conf ({12, 9, 0, 13, 1, 7, 8, 6, 11, 3, 2, 5, 14, 10, 4 });
    shared_ptr<OperationModule> om_s(make_shared<OM_FixedFirstConfiguration>(bench, conf));
    shared_ptr<OperationModule> om_r(make_shared<OM_DanielASRestartRearrange>());
    shared_ptr<Operator> op(make_shared<SequentialExecOperator>(om_s, om_r));
    shared_ptr<GroupedComputation> G(make_shared<GroupedSequentialComputation>(op));

    shared_ptr<Solution> solution = static_pointer_cast<Solution>(G->execute(psp, t_seed));
    cout << solution->configurationToString() << endl;

    return "OM_Daniel_Reset: OK !"; // : "OM_Daniel_Reset: fail :/";
}
