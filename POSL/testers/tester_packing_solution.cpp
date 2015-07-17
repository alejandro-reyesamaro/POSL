#include "tester_packing_solution.h"
#include "data/solution.h"
#include "solver/psp.h"
#include "tools/tools.h"

#include <algorithm>

Tester_PackingSolution::Tester_PackingSolution(int argc, char *argv[])
    : Tester(argc, argv)
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
    //PSP * psp = new PSP(bench);
    Solution * sol = new Solution(psp->GetBenchmark()->GetSolution()->domains, config);
    string conf_str = sol->configurationToString();
    vector<int> pack = sol->pack();

    // | ID |
    int id = pack[0];

    // | conf_size |
    int conf_size = pack[1];

    // | configuration |
    string pack_str = "[ ";
    for(vector<int>::iterator it = pack.begin() + 2; it != pack.end() - 1; ++it)
        pack_str += Tools::int2str(* it) + ", ";
    pack_str += Tools::int2str(pack.back()) +" ]";

    /*
    for(int i = 0; i < conf_size - 1; i++)
        pack_str += Tools::int2str(* pack ++) + ", ";
    pack_str += Tools::int2str(* pack) +" ]";
    */

    //cout << conf_str << endl;
    //cout << pack_str << endl;

    return  (conf_str.compare(pack_str) == 0) ? "Packing Solution: (" + Tools::int2str(id) + ") : OK !" : "Packing Solution: fail :/";
}
