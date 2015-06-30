#include "tester_multi_elements_changed_neighborhood.h"
#include "data/solution.h"
#include "modules/operation_module.h"
#include "modules/om_multi_elements_changed_neighborhood.h"
#include "data/multi_elements_changed_neighborhood.h"

Tester_MultiElementsChangedNeighborhood::Tester_MultiElementsChangedNeighborhood()
{
}

string Tester_MultiElementsChangedNeighborhood::test()
{
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


    Solution * sol = new Solution(bench->GetSolution()->domains, config);

    OperationModule * op = new OM_MultiElementsChangedNeighborhood();
    PSP * psp = new PSP(bench);
    Neighborhood * V = (Neighborhood *)op->execute(psp, sol);

    POSL_Iterator<vector<int>> * it = V ->getIterator();
    it->Reset();
    int sum  = 0;
    int prod = 1;
    bool only_change_one = true;

    while(it->SomeNext())
    {
        vector<int> neighbor = it->GetNext();

        cout << "[ ";
        for(std::vector<int>::iterator j = neighbor.begin(); j != neighbor.end(); ++j)
        {
            sum  += *j;
            prod *= *j;

            cout << *j << " ";
        }
        cout << "]" << endl;

        only_change_one = only_change_one && (prod == sum - 31);
        sum  = 0;
        prod = 1;
    }
    return (only_change_one) ? "OM_MultiElementsChangedNeighborhood: OK !" : "OM_MultiElementsChangedNeighborhood: fail :/";
}
