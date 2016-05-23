#include "tester_all_permutations_neighborhood.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_all_permutations_neighborhood.h"
#include "../data/one_element_changed_neighborhood.h"

#include <algorithm>

Tester_AllPermutationsNeighborhood::Tester_AllPermutationsNeighborhood(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_AllPermutationsNeighborhood::test()
{
    shared_ptr<Benchmark> bench(make_shared<AllIntervals>(18));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));
    vector<int> v ({16, 2, 15, 0, 17, 1, 13, 3, 14, 5, 12, 4, 10, 8, 9, 6, 11, 7});
    shared_ptr<Solution> sol = make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), v);
    shared_ptr<OperationModule> op(make_shared<OM_AllPermutationsNeighborhood>(bench));
    shared_ptr<Neighborhood> V = static_pointer_cast<Neighborhood>(op->execute(psp, sol));

    shared_ptr<POSL_Iterator> it = V ->getIterator();
    it->Reset();

    //cout << aux->configurationToString() << endl;

    bool two_permutations = true;
    int changes = 0;

    while(two_permutations && it->SomeNext())
    {
        changes = 0;
        vector<int> neighbor = it->GetNext();
        two_permutations = two_permutations && is_permutation(v.begin(), v.end(), neighbor.begin());
        for(int i = 0; i < neighbor.size(); i++)
            if(v[i] != neighbor[i]) changes ++;
        two_permutations = two_permutations && (changes == 0 || changes == 2)   ;

        //aux = make_shared<Solution>(bench->Variable_Domain(), v);
        //cout << aux->configurationToString() << endl;
        //aux = make_shared<Solution>(bench->Variable_Domain(), neighbor);
        //cout << aux->configurationToString() << endl;
        //cout << endl;
    }
    return (two_permutations) ? "OM_AllPermutationsNeighborhood: OK !" : "OM_AllPermutationsNeighborhood: fail :/";
}
