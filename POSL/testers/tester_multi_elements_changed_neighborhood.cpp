#include "tester_multi_elements_changed_neighborhood.h"
#include "data/solution.h"
#include "modules/operation_module.h"
#include "modules/om_multi_elements_changed_neighborhood.h"
#include "data/multi_elements_changed_neighborhood.h"

Tester_MultiElementsChangedNeighborhood::Tester_MultiElementsChangedNeighborhood(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_MultiElementsChangedNeighborhood::test()
{
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

    Solution * sol = new Solution(psp->GetBenchmark()->GetSolution()->domains, config);

    OperationModule * op = new OM_MultiElementsChangedNeighborhood();
    //PSP * psp = new PSP(bench);
    Neighborhood * V = (Neighborhood *)op->execute(psp, sol);

    POSL_Iterator<vector<int>> * it = V ->getIterator();
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
