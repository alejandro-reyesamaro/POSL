#include "tester_packing_solution.h"
#include "../data/solution.h"
#include "../solver/psp.h"
#include "../tools/tools.h"
#include "../packing/packers/solution_packer.h"

#include <algorithm>

Tester_PackingSolution::Tester_PackingSolution(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_PackingSolution::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    shared_ptr<Solution> sol(make_shared<Solution>(bench->Domains()));
    bench->UpdateSolution(sol);
    shared_ptr<PSP> psp(make_shared<PSP>(ARGC, ARGV, bench));

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

    sol = make_shared<Solution>(psp->GetBenchmark()->Domains(), config);
    string conf_str = sol->configurationToString();
    shared_ptr<SolutionPacker> p(make_shared<SolutionPacker>(sol));
    vector<int> pack = p->pack();

    shared_ptr<Solution> final(make_shared<Solution>(psp->GetBenchmark()->Domains()));
    final->UpdateConfigurationFromPack(&pack[0]);
    bool succ = final->equal(sol);

    // | ID |
    int id = pack[0];

    // | conf_size |
    //int conf_size = pack[1];

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

    return  (succ && conf_str.compare(pack_str) == 0) ? "Packing Solution: (" + Tools::int2str(id) + ") : OK !" : "Packing Solution: fail :/";
}
