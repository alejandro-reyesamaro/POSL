#include "tester_subsum_single_swap_neighborhood.h"
#include "../data/solution.h"
#include "../modules/operation_module.h"
#include "../modules/om_subsum_single_permutation_neighborhood.h"
#include "../tools/tools.h"

#include <algorithm>

Tester_SubsumSingleSwapNeighborhood::Tester_SubsumSingleSwapNeighborhood(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_SubsumSingleSwapNeighborhood::test()
{
    vector<int> conf({1, 2, 3, 4, 5, 6, 7});
    shared_ptr<Benchmark> bench(make_shared<Subsum>(conf, 17, 5));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    shared_ptr<Solution> sol = make_shared<Solution>(psp->GetBenchmark()->Variable_Domain(), conf);
    shared_ptr<OperationModule> op(make_shared<OM_SubsumSinglePermutationNeighborhood>(bench));
    shared_ptr<Neighborhood> V = static_pointer_cast<Neighborhood>(op->execute(psp, sol));

    shared_ptr<POSL_Iterator> it = V ->getIterator();
    it->Reset();

    int ch = 0;

    while(it->SomeNext())
    {
        vector<int> neighbor = it->GetNext();
        ch = Tools::mismatches(neighbor, conf);

        cout << "[ ";
        for(std::vector<int>::iterator j = neighbor.begin(); j != neighbor.end(); ++j)
            cout << *j << " ";
        cout << "]" << endl;
    }
    return "OM_SubsumSinglePermutationNeighborhood: OK !";// : "OM_SubsumSinglePermutationNeighborhood: fail :/";
}
