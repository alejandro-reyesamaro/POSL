#include "tester_golfers_as_neighborhood.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_golfers_adaptive_search_neigborhood.h"
#include "../data/one_element_changed_neighborhood.h"
#include "../modules/grouped_sequential_computation.h"
#include "../operators/sequential_exec_operator.h"
#include "../modules/om_fixed_first_configuration.h"

Tester_GolfersASNeighborhood::Tester_GolfersASNeighborhood(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_GolfersASNeighborhood::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4, 4, 2));

    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    shared_ptr<OperationModule> om_s(make_shared<OM_FixedFirstConfiguration>(bench, Tester::Golfers_442_c4()));
    shared_ptr<OperationModule> om_v(make_shared<OM_GolfersAdaptiveSearchNeigborhood>(bench));
    shared_ptr<Operator> op(make_shared<SequentialExecOperator>(om_s, om_v));
    shared_ptr<GroupedComputation> G(make_shared<GroupedSequentialComputation>(op));
    shared_ptr<Neighborhood> V = static_pointer_cast<Neighborhood>(G->execute(psp, t_seed));

    shared_ptr<POSL_Iterator> it = V ->getIterator();
    it->Reset();

    while(it->SomeNext())
    {
        vector<int> neighbor = it->GetNext();
        shared_ptr<Solution> aux(make_shared<Solution>(bench->Domains(), neighbor));
        cout << aux->configurationToString() << endl;
    }
    return "OM_Golfers_AS_Neighborhood: OK !"; // : "OM_Golfers_AS_Neighborhood: fail :/";
}
