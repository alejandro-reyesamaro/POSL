#include "tester_iteration_golfers.h"

#include <algorithm>

Tester_IterationGolfers::Tester_IterationGolfers(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_IterationGolfers::test()
{
    shared_ptr<Benchmark> bench332(make_shared<Golfers>(3,3,2));
    vector<int> init_config = Tester::Golfers_332_c6();
    shared_ptr<Solution> sol332(make_shared<Solution>(bench332->Domains(), init_config));
    shared_ptr<PSP> psp332(make_shared<PSP>(ARGC, ARGV, bench332));
    int cA = bench332->solutionCost(sol332);

    psp332->Start(sol332->GetConfiguration());

    vector<int> cc(init_config.size());
    copy(init_config.begin(), init_config.end(), cc.begin());

    cc[10] = 9;
    cc[15] = 4;

    int cR1 = bench332->relativeSolutionCost(cc);
    //cout << cR1 << endl;

    cc[14] = 1;
    cc[16] = 8;

    int cR2 = bench332->relativeSolutionCost(cc);
    //cout << cR2 << endl;

    bool ok = cA == 6 && cR1 == 4 && cR2 == 0;
    // ************************************************

    copy(init_config.begin(), init_config.end(), cc.begin());
    cc[10] = 9;
    cc[15] = 4;

    psp332->UpdateSolution(cc);
    int current_cost = psp332->CurrentCost();
    cout << current_cost << endl;

    cc[14] = 1;
    cc[16] = 8;

    cR1 = bench332->relativeSolutionCost(cc);
    cout << cR1 << endl;

    ok = ok && current_cost == 4 && cR1 == 0;

    return (ok  ) ?
           "One Iteration (Golfers): OK !" : "One Iteration (Golfers): fail :/";
}
