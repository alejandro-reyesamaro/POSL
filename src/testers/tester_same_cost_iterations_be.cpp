#include "tester_same_cost_iterations_be.h"
#include "../expressions/same_cost_iterations_bound_expression.h"
#include "../tools/tools.h"

Tester_SameCostIterationsBE::Tester_SameCostIterationsBE(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_SameCostIterationsBE::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));
    shared_ptr<SameCostIterationsBoundExpression> be(make_shared<SameCostIterationsBoundExpression>(4));
    vector<int> g_442_c4 = Tester::Golfers_442_c4();
    psp->UpdateSolution(g_442_c4);

    int c1 = 0, c2 = 0;
    for(int i = 0; i < 10; i++)
    {
        if(be->evaluate(psp))
            c1++;
        else c2++;
    }

    string prefix = "true: " + Tools::int2str(c1) + ", false: " + Tools::int2str(c2);
    //cout << prefix << endl;
    return (c1 == 4 && c2 == 6) ? prefix + " -> SCI (BE): OK !" : "SCI (BE): fail :/";
}
