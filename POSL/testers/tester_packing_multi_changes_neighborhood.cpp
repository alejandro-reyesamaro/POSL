#include "tester_packing_multi_changes_neighborhood.h"
#include "data/solution.h"
#include "solver/psp.h"
#include "tools/tools.h"
#include "modules/om_multi_elements_changed_neighborhood.h"

#include <algorithm>

Tester_PackingMultiChangesNeighborhood::Tester_PackingMultiChangesNeighborhood()
{
}

string Tester_PackingMultiChangesNeighborhood::test()
{
    vector<int> config(
    {
        1,  2,   3,  4,
        5,  6,   7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16,

        13, 10,  7,  4,
        14, 11,  8,  1,
        15, 12,  2,  5,
        16,  3,  6,  9
    });
    PSP * psp = new PSP(bench);
    Solution * sol = new Solution(bench->GetSolution()->domains, config);
    string sol_str = sol->configurationToString();

    OperationModule * op = new OM_MultiElementsChangedNeighborhood();
    Neighborhood * V = (Neighborhood *)op->execute(psp, sol);

    int * pack = V->pack();

    POSL_Iterator<vector<int>> * it = V ->getIterator();
    it->Reset();

    // | ID |
    int id = * pack;
    pack ++;

    // | conf_size |
    int conf_size = * pack;
    pack ++;

    // | configuration |
    string conf_str = "[ ";
    for(int i = 0; i < conf_size - 1; i++)
        conf_str += Tools::int2str(* pack ++) + ", ";
    conf_str += Tools::int2str(* pack ++) +" ]";
    bool legal = conf_str.compare(sol_str) == 0;

    // | n_size |
    int n_size = * pack;
    pack ++;

    while(it->SomeNext())
    {
        vector<int> neighbor = it->GetNext();
        Solution * sol_aux = new Solution(bench->GetSolution()->domains, neighbor);
        int deg = * pack;
        pack++;
        vector<int> conf_aux (32);
        copy(config.begin(), config.end(), conf_aux.begin());
        for(int i = 0; i < deg; i++)
        {
            int pos = * pack;
            pack ++;
            int value = * pack;
            pack ++;
            conf_aux[pos] = value;
        }
        Solution * neighbor_aux = new Solution(bench->GetSolution()->domains, conf_aux);
        legal = legal && sol_aux->configurationToString().compare(neighbor_aux->configurationToString()) == 0;
    }

    //cout << conf_str << endl;
    //cout << pack_str << endl;

    return  (legal)
            ? "Packing Multi Changes Neighborhood: (" + Tools::int2str(id) + ") : OK !"
            : "Packing Multi Changes Neighborhood: fail :/";
}
