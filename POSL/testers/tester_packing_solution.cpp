#include "tester_packing_solution.h"
#include "data/solution.h"
#include "solver/psp.h"
#include "tools/tools.h"

#include <algorithm>

Tester_PackingSolution::Tester_PackingSolution()
{
}

string Tester_PackingSolution::test()
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
    string conf_str = sol->configurationToString();
    int * pack = sol->pack();

    // | ID |
    int id = * pack;
    pack ++;

    // | conf_size |
    int conf_size = * pack;
    pack ++;

    // | configuration |
    string pack_str = "[ ";
    for(int i = 0; i < conf_size - 1; i++)
        pack_str += Tools::int2str(* pack ++) + ", ";
    pack_str += Tools::int2str(* pack) +" ]";

    //cout << conf_str << endl;
    //cout << pack_str << endl;

    return  (conf_str.compare(pack_str) == 0) ? "Packing Solution: OK !" : "Packing Solution: fail :/";
}
