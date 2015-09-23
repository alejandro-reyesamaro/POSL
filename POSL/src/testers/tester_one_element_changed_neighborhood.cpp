#include "tester_one_element_changed_neighborhood.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_one_element_changed_neighborhood.h"
#include "../data/one_element_changed_neighborhood.h"

Tester_OneElementChangedNeighborhood::Tester_OneElementChangedNeighborhood(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_OneElementChangedNeighborhood::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    shared_ptr<Solution> sol(make_shared<Solution>(bench->Domains()));
    //bench->UpdateSolution(sol);
    shared_ptr<PSP> psp(make_shared<PSP>(ARGC, ARGV, bench));

    sol = make_shared<Solution>(psp->GetBenchmark()->Domains(), Tester::Golfers_442_1s());
    shared_ptr<OperationModule> op(make_shared<OM_OneElementChangedNeighborhood>(bench));
    //PSP> psp(make_shared<PSP(bench);
    shared_ptr<Neighborhood> V = static_pointer_cast<Neighborhood>(op->execute(psp, sol));

    shared_ptr<POSL_Iterator> it = V ->getIterator();
    it->Reset();
    int sum  = 0;
    int prod = 1;
    bool only_change_one = true;

    while(it->SomeNext())
    {
        vector<int> neighbor = it->GetNext();

        for(std::vector<int>::iterator j = neighbor.begin(); j != neighbor.end(); ++j)
        {
            int k = *j;
            sum  += k;
            prod *= k;
        }
        //Solution> aux(make_shared<Solution(bench->Domains(), neighbor);
        //cout << aux->configurationToString() << endl;


        only_change_one = only_change_one && (prod == sum - 31) && (prod != 1);
        sum  = 0;
        prod = 1;
    }
    return (only_change_one) ? "OM_OneElementChangedNeighborhood: OK !" : "OM_OneElementChangedNeighborhood: fail :/";
}
