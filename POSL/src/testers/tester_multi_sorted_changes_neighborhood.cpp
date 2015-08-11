#include "tester_multi_sorted_changes_neighborhood.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_multi_sorted_changes_neighborhood.h"
#include "../data/multi_elements_changed_neighborhood.h"

#include <algorithm>

Tester_MultiSortedChangesNeighborhood::Tester_MultiSortedChangesNeighborhood(int argc, char *argv[])
    : Tester(argc, argv)
{
}

int changes(vector<int> neighbor, vector<int> config)
{
    int c = 0;
    for(int i = 0; i < neighbor.size(); i++)
        if(neighbor[i] != config[i])
            c++;
    return c;
}

string Tester_MultiSortedChangesNeighborhood::test()
{
    Benchmark * bench = new GolombRuler(5, 11);
    Solution * sol = new Solution(bench->Domains());
    bench->UpdateSolution(sol);
    PSP * psp = new PSP(ARGC, ARGV, bench);

    vector<int> config( { 0, 1, 4, 9, 11 } );

    sol = new Solution(psp->GetBenchmark()->Domains(), config);

    OperationModule * op = new OM_MultiSortedChangesNeighborhood();
    //PSP * psp = new PSP(bench);
    Neighborhood * V = (Neighborhood *)op->execute(psp, sol);

    POSL_Iterator<vector<int>> * it = V ->getIterator();
    it->Reset();
    int ch  = 0;
    bool v  = true;

    while(it->SomeNext())
    {
        vector<int> neighbor = it->GetNext();

        ch = changes(neighbor, config);
        cout << "[ ";
        for(std::vector<int>::iterator j = neighbor.begin(); j != neighbor.end(); ++j)
            cout << *j << " ";
        cout << "]" << endl;

        v = v && (ch == 2 || ch == 1);
        v = v && is_sorted(neighbor.begin(), neighbor.end());
    }
    return (v) ? "OM_MultiSortedChangesNeighborhood: OK !" : "OM_MultiSortedChangesNeighborhood: fail :/";
}
