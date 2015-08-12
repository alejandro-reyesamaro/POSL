#include "tester_one_sorted_change_neighborhood.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_one_sorted_change_neighborhood.h"
#include "../tools/tools.h"

Tester_OneSortedChangeNeighborhood::Tester_OneSortedChangeNeighborhood(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_OneSortedChangeNeighborhood::test()
{
    Benchmark * bench = new GolombRuler(12,85);
    Solution * sol = new Solution(bench->Domains());
    bench->UpdateSolution(sol);
    PSP * psp = new PSP(ARGC, ARGV, bench);

    vector<int> config( { 0, 2, 6, 24, 29, 40, 43, 55, 68, 75, 76, 85 } );

    sol = new Solution(psp->GetBenchmark()->Domains(), config);
    OperationModule * op = new OM_OneSortedChangeNeighborhood();
    //PSP * psp = new PSP(bench);
    Neighborhood * V = (Neighborhood *)op->execute(psp, sol);

    POSL_Iterator<vector<int>> * it = V ->getIterator();
    it->Reset();

    int ch = 0;
    bool v = true;

    while(it->SomeNext())
    {
        vector<int> neighbor = it->GetNext();
        ch = Tools::mismatches(neighbor, config);

        cout << "[ ";
        for(std::vector<int>::iterator j = neighbor.begin(); j != neighbor.end(); ++j)
            cout << *j << " ";
        cout << "]" << endl;

        v = v && (ch <= 3 || ch >= 1);
        v = v && is_sorted(neighbor.begin(), neighbor.end());
    }
    return (v) ? "OM_OneElementChangedNeighborhood: OK !" : "OM_OneElementChangedNeighborhood: fail :/";
}
