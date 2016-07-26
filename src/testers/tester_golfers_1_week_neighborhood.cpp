#include "tester_golfers_1_week_neighborhood.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_golfers_custom_week_swap_neighborhood.h"
#include "../data/one_element_changed_neighborhood.h"
#include "../modules/grouped_sequential_computation.h"
#include "../operators/sequential_exec_operator.h"
#include "../modules/om_fixed_first_configuration.h"
#include "../tools/tools.h"

Tester_Golfers1WeekNeighborhood::Tester_Golfers1WeekNeighborhood(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_Golfers1WeekNeighborhood::test()
{
    int g = 3;
    int p = 3;
    int w = 3;
    vector<int> week = {1,2};
    vector<int> first_conf = Tester::Golfers_333_c();

    shared_ptr<Benchmark> bench(make_shared<Golfers>(g,p,w));

    shared_ptr<PSP> psp(make_shared<PSP>(bench));
    bench->SetDefaultConfiguration(first_conf);

    shared_ptr<OperationModule> om_s(make_shared<OM_FixedFirstConfiguration>(bench));

    shared_ptr<OperationModule> om_v(make_shared<OM_GolfersCustomWeekSwapNeighborhood>(bench, week));
    shared_ptr<Operator> op(make_shared<SequentialExecOperator>(om_s, om_v));
    shared_ptr<GroupedComputation> G(make_shared<GroupedSequentialComputation>(op));
    shared_ptr<Neighborhood> V = static_pointer_cast<Neighborhood>(G->execute(psp, t_seed));

    shared_ptr<POSL_Iterator> it = V ->getIterator();
    it->Reset();

    for(int i = (g*p)*week[0]; i < (g*p)*(week[0]+1); i++)
        cout << first_conf[i] << " ";
    cout << endl;
    cout << endl;

    while(it->SomeNext())
    {
        vector<int> neighbor = it->GetNext();
        cout << Tools::configurationToString(neighbor) << endl;
        //for(int i = (g*p)*week; i < (g*p)*(week+1); i++)
        //    cout << neighbor[i] << " ";
        //cout << endl;
    }
    return "OM_Golfers_1Week_Neighborhood: OK !"; // : "OM_Golfers_1Week_Neighborhood: fail :/";
}
