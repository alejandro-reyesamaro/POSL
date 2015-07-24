#include "tester_speed_operator.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_fixed_first_configuration.h"
#include "../modules/om_florian_random_conf_generation.h"
#include "../operators/speed_operator.h"
#include "../modules/grouped_sequential_computation.h"
#include "../modules/grouped_parallel_computation.h"
#include "../data/multi_elements_changed_neighborhood.h"

Tester_SpeedOperator::Tester_SpeedOperator(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_SpeedOperator::testeInMode(Computation comp)
{

    vector<int> config(
    {
        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,

        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1
    });

    Solution * sol = new Solution(psp->GetBenchmark()->GetSolution()->domains, config);
    //PSP * psp = new PSP(bench);

    OperationModule * m1 = new OM_FixedFirstConfiguration();
    OperationModule * m2 = new OM_FlorianRandomConfGeneration();

    Operator * op = new SpeedOperator(m1, m2);

    CompoundModule * G1 = (comp == SEQ)
            ? (CompoundModule *) new GroupedSequentialComputation(op)
            : (CompoundModule *) new GroupedParallelComputation(op);

    //cout << "Testing speed operator...... " << endl;
    Solution * S = (Solution *)G1->execute(psp, sol);

    string mode_str = (comp == SEQ) ? "Operator_Speed (Sequential)" : "Operator_Speed (Parallel)";
    return (S->equal(sol)) ? mode_str + ": OK !" : mode_str + ": fail :/";
}

string Tester_SpeedOperator::test()
{
    //return testeInMode(SEQ);
    return testeInMode(SEQ) + "\n   " + testeInMode(PAR);
}
