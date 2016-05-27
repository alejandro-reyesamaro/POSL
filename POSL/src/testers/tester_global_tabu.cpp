#include "tester_global_tabu.h"

#include "../data/solution.h"
#include "../tools/tools.h"
#include "../tools/tabu_list.h"

#include <algorithm>

Tester_GlobalTabu::Tester_GlobalTabu(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_GlobalTabu::test()
{
    shared_ptr<Benchmark> bench(make_shared<GolombRuler>(6,17));
    vector<int> init_config ({0, 1, 4, 8, 12, 17});
    shared_ptr<TabuList> tl(make_shared<TabuList>(2));
    tl->push(init_config);
    bool tabu = true;

    vector<int> new_config1 ({0, 3, 4, 8, 12, 17});
    tabu = tabu && tl->isTabuByNorm1(new_config1, 3);
    vector<int> new_config2 ({1, 2, 3, 6, 10, 15});
    tabu = tabu && tl->isTabuByNorm2(new_config2, 4);
    vector<int> new_config3 ({1, 3, 7, 12, 17, 23});
    tabu = tabu && ! tl->isTabuByNorm2(new_config3, 9);
    tabu = tabu && tl->isTabuByNorm8(new_config3, 7);

    vector<int> new_config4({3, 5, 10, 1, 2, 3});
    vector<int> new_config5({4, 6, 12, 0, 1, 2});
    tl->push(new_config4);
    tl->push(new_config5);

    tabu = tabu && ! tl->isTabuByNorm1(new_config1, 3);

    return (tabu) ? "Global Tabu: OK !" : "Global Tabu: fail :/";
}
