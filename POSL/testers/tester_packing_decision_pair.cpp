#include "tester_packing_decision_pair.h"
#include "data/solution.h"
#include "solver/psp.h"
#include "data/decision_pair.h"
#include "tools/tools.h"

#include <algorithm>

Tester_PackingDecisionPair::Tester_PackingDecisionPair(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_PackingDecisionPair::test()
{
    vector<int> config1(
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

    vector<int> config2(
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


    //PSP * psp = new PSP(bench);
    Solution * sol_current = new Solution(psp->GetBenchmark()->GetSolution()->domains, config1);
    Solution * sol_found = new Solution(psp->GetBenchmark()->GetSolution()->domains, config2);
    DecisionPair * pair = new DecisionPair(sol_current, sol_found);

    string current_str = sol_current->configurationToString();
    string found_str = sol_found->configurationToString();
    vector<int> pack = pair->pack();

    // | ID |
    int id = pack[0];

    // | conf_size |
    int conf_size = pack[1];

    // | configuration 1|
    string pack_current_str = "[ ";
    for(vector<int>::iterator it = pack.begin() + 2; it != pack.begin() + conf_size + 2 - 1; ++it)
        pack_current_str += Tools::int2str(* it) + ", ";
    pack_current_str += Tools::int2str(*(pack.begin() + conf_size + 2 - 1)) +" ]";

    /*
    for(int i = 0; i < conf_size - 1; i++)
        pack_current_str += Tools::int2str(* pack ++) + ", ";
    pack_current_str += Tools::int2str(* pack ++) +" ]";
    */

    // | configuration 1|
    string pack_found_str = "[ ";
    for(vector<int>::iterator it = pack.begin() + conf_size + 2; it != pack.end() - 1; ++it)
        pack_found_str += Tools::int2str(* it) + ", ";
    pack_found_str += Tools::int2str(pack.back()) +" ]";

    /*
    for(int i = 0; i < conf_size - 1; i++)
        pack_found_str += Tools::int2str(* pack ++) + ", ";
    pack_found_str += Tools::int2str(* pack) +" ]";
    */

    //cout << conf_str << endl;
    //cout << pack_str << endl;

    return  (current_str.compare(pack_current_str) == 0 && found_str.compare(pack_found_str) == 0)
            ? "Packing DecisionPair (" + Tools::int2str(id) + ") : OK !"
            : "Packing DecisionPair: fail :/";
}
