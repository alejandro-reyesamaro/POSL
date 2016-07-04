#include "tester_golomb_subsum_conversions.h"
#include "../tools/golomb_tools.h"
#include "../tools/tools.h"

#include <algorithm>

Tester_GolombSubsumConversions::Tester_GolombSubsumConversions(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_GolombSubsumConversions::test()
{
    int order = 8;      //  6,  7,  8, 10, 12
    int length = 34;    // 17, 25, 34, 55, 85

    vector<int> posible_subsum_values = Tools::generateMonotony(1,GolombTools::max_posible_distances(order, length));

    //shared_ptr<GolombRuler> gr(make_shared<GolombRuler>(order, length));
    vector<int> c_golomb = {0, 1, 4, 9, 15, 22, 32, 34};
    vector<int> c_subsum = GolombTools::golomb2subsum(c_golomb, order, length);
    cout << "Golomb 2 Subsum : " << Tools::configurationToString(c_subsum) << endl;

    c_subsum = {1, 3, 5, 9, 4, 10, 2, 6, 8, 7, 11, 12, 13};
    c_golomb = GolombTools::subsum2golomb(c_subsum, order);
    cout << "Subsum 2 Golomb : " << Tools::configurationToString(c_golomb) << endl;

    bool ok = is_permutation(posible_subsum_values.begin(), posible_subsum_values.end(), c_subsum.begin());
    return (ok) ? "Golomb <-> Subsum Conversions: OK !" : "Golomb <-> Subsum Conversions: Fail :/";
}
