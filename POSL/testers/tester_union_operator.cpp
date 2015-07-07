#include "tester_union_operator.h"
#include "data/solution.h"
#include "modules/operation_module.h"
#include "modules/om_multi_elements_changed_neighborhood.h"
#include "modules/om_one_element_changed_neighborhood.h"
#include "operators/union_operator.h"
#include "modules/grouped_sequential_computation.h"
#include "data/multi_elements_changed_neighborhood.h"

Tester_UnionOperator::Tester_UnionOperator()
{
}

string Tester_UnionOperator::test()
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
        1,  1,  1,  1
    });

    Solution * sol = new Solution(bench->GetSolution()->domains, config);
    PSP * psp = new PSP(bench);


    OperationModule * m1 = new OM_MultiElementsChangedNeighborhood();
    OperationModule * m2 = new OM_OneElementChangedNeighborhood();

    Operator * op = new UnionOperator(m1, m2);
    CompoundModule * G1 = new GroupedSequentialComputation(op);

    Neighborhood * V = (Neighborhood *)G1->execute(psp, sol);

    POSL_Iterator<vector<int>> * it = V ->getIterator();
    it->Reset();
    int changes = 0;
    int sum  = 0;
    int prod = 1;
    int count = 0;
    bool the_changes = true;

    while(it->SomeNext())
    {
        vector<int> neighbor = it->GetNext();
        //cout << "[ ";
        for(std::vector<int>::iterator j = neighbor.begin(); j != neighbor.end(); ++j)
        {
            if(*j != 1) changes ++;
            sum  += *j;
            prod *= *j;
            //cout << *j << " ";
        }
        //cout << "]" << endl;
        if(count ++ < 10)
            the_changes = the_changes && (changes == 5);
        else
            the_changes = the_changes && (prod == sum - 31);
        sum  = 0;
        prod = 1;
        changes = 0;
    }
    return (the_changes) ? "Operator_Union: OK !" : "Operator_Union: fail :/";
}
