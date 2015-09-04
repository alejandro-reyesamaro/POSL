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
    Benchmark * bench = new Golfers(4,4,2);
    Solution * sol = new Solution(bench->Domains());
    bench->UpdateSolution(sol);
    PSP * psp = new PSP(ARGC, ARGV, bench);

    vector<int> config(
    {
        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,

        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,
    });
    sol = new Solution(psp->GetBenchmark()->Domains(), config);
    OperationModule * op = new OM_OneElementChangedNeighborhood(bench);
    //PSP * psp = new PSP(bench);
    Neighborhood * V = (Neighborhood *)op->execute(psp, sol);

    POSL_Iterator<vector<int>> * it = V ->getIterator();
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
        //Solution * aux = new Solution(bench->Domains(), neighbor);
        //cout << aux->configurationToString() << endl;


        only_change_one = only_change_one && (prod == sum - 31) && (prod != 1);
        sum  = 0;
        prod = 1;
    }
    return (only_change_one) ? "OM_OneElementChangedNeighborhood: OK !" : "OM_OneElementChangedNeighborhood: fail :/";
}
