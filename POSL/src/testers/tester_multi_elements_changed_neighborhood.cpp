#include "tester_multi_elements_changed_neighborhood.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_multi_elements_changed_neighborhood.h"
#include "../data/multi_elements_changed_neighborhood.h"

Tester_MultiElementsChangedNeighborhood::Tester_MultiElementsChangedNeighborhood(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_MultiElementsChangedNeighborhood::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    shared_ptr<Solution> sol(make_shared<Solution>(bench->Domains()));
    bench->UpdateSolution(sol);
    shared_ptr<PSP> psp(make_shared<PSP>(ARGC, ARGV, bench));

    vector<int> config(
    {
        0,  0,  0,  0,
        0,  0,  0,  0,
        0,  0,  0,  0,
        0,  0,  0,  0,

        0,  0,  0,  0,
        0,  0,  0,  0,
        0,  0,  0,  0,
        0,  0,  0,  0
    });

    sol(make_shared<Solution>(psp->GetBenchmark()->Domains(), config));

    shared_ptr<OperationModule> op(make_shared<OM_MultiElementsChangedNeighborhood>(bench));
    shared_ptr<Neighborhood> V = static_pointer_cast<Neighborhood>(op->execute(psp, sol));

    shared_ptr<POSL_Iterator<vector<int>>> it = V ->getIterator();
    it->Reset();
    int sum  = 0;
    bool changes = true;

    while(it->SomeNext())
    {
        vector<int> neighbor = it->GetNext();
        //cout << "[ ";
        for(std::vector<int>::iterator j = neighbor.begin(); j != neighbor.end(); ++j)
        {
            if(*j != 0) sum ++;
            //cout << *j << " ";
        }
        //cout << "]" << endl;
        changes = changes && (sum == 5);
        sum = 0;
    }
    return (changes) ? "OM_MultiElementsChangedNeighborhood: OK !" : "OM_MultiElementsChangedNeighborhood: fail :/";
}
