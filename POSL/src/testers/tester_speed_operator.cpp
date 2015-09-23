#include "tester_speed_operator.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_fixed_first_configuration.h"
#include "../operators/speed_operator.h"
#include "../modules/grouped_parallel_computation.h"
#include "../data/multi_elements_changed_neighborhood.h"
#include "../modules/grouped_sequential_computation.h"
#include "../operators/florian_operator.h"
#include "../modules/om_random_conf_generation.h"

Tester_SpeedOperator::Tester_SpeedOperator(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_SpeedOperator::testeInMode(Computation comp)
{
    shared_ptr<Benchmark> bench =(make_shared<Golfers>(4,4,2));
    shared_ptr<Solution> sol =(make_shared<Solution>(bench->Domains()));
    //bench->UpdateSolution(sol);
    shared_ptr<PSP> psp =(make_shared<PSP>(ARGC, ARGV, bench));

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

    sol =(make_shared<Solution>(psp->GetBenchmark()->Domains(), config));

    shared_ptr<OperationModule> m1 =(make_shared<OM_FixedFirstConfiguration>(bench));
    shared_ptr<OperationModule> m2 =(make_shared<OM_RandomConfGeneration>(bench));
    shared_ptr<Operator> _op =(make_shared<FlorianOperator>(m2));
    shared_ptr<GroupedComputation> G =(make_shared<GroupedSequentialComputation>(_op));

    shared_ptr<Operator> op =(make_shared<SpeedOperator>(m1, G));

    shared_ptr<CompoundModule> G1 = (comp == SEQ)
            ? static_pointer_cast<CompoundModule>(make_shared<GroupedSequentialComputation>(op))
            : static_pointer_cast<CompoundModule>(make_shared<GroupedParallelComputation>(op));

    //cout << "Testing speed operator...... " << endl;
    shared_ptr<Solution> S = static_pointer_cast<Solution>(G1->execute(psp, sol));

    string mode_str = (comp == SEQ) ? "Operator_Speed (Sequential)" : "Operator_Speed (Parallel)";
    return (S->equal(sol)) ? mode_str + ": OK !" : mode_str + ": fail :/";
}

string Tester_SpeedOperator::test()
{
    //return testeInMode(SEQ);
    return testeInMode(SEQ) + "\n   " + testeInMode(PAR);
}
