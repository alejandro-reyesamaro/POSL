#include "tester_one_2d_change_neighborhood.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_one_2d_change_neighborhood.h"
#include "../modules/grouped_sequential_computation.h"
#include "../operators/sequential_exec_operator.h"
#include "../modules/om_fixed_first_configuration.h"

Tester_One2DChangeNeighborhood::Tester_One2DChangeNeighborhood(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_One2DChangeNeighborhood::test()
{
    vector<int> squares({6, 4, 4, 1, 3, 3, 3});
    shared_ptr<Benchmark> bench(make_shared<SquaringSquare>(10, squares));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    vector<int> config({0, 0, 6, 4, 5, 7, 4,    0, 6, 0, 6, 6, 7, 7});

    shared_ptr<OperationModule> om_s(make_shared<OM_FixedFirstConfiguration>(bench, config));
    shared_ptr<OperationModule> om_v(make_shared<OM_One2DChangeNeighborhood>(bench));
    shared_ptr<Operator> op(make_shared<SequentialExecOperator>(om_s, om_v));
    shared_ptr<GroupedComputation> G(make_shared<GroupedSequentialComputation>(op));
    shared_ptr<Neighborhood> V = static_pointer_cast<Neighborhood>(G->execute(psp, t_seed));

    shared_ptr<POSL_Iterator> it = V ->getIterator();
    it->Reset();
    int sum  = 0;
    int prod = 1;
    bool only_change_one = true;

    while(it->SomeNext())
    {
        vector<int> neighbor = it->GetNext();
        /*
        for(std::vector<int>::iterator j = neighbor.begin(); j != neighbor.end(); ++j)
        {
            int k = *j;
            sum  += k;
            prod *= k;
        }
        */
        shared_ptr<Solution> aux(make_shared<Solution>(bench->Variable_Domain(), neighbor));
        cout << aux->configurationToString() << endl;
    }
    return (only_change_one) ? "OM_One2DChangeNeighborhood: OK !" : "OM_One2DChangeNeighborhood: fail :/";
}
