#include "tester_as_restart.h"
#include "../modules/strategy/all_circular_shift_around_worst_rearrange_strategy.h"
#include "../modules/strategy/add_a_constant_rearrange_strategy.h"
#include "../modules/strategy/circular_shift_around_bad_rearrange_strategy.h"

Tester_ASRestart::Tester_ASRestart(int argc, char * argv[])
    : Tester(argc, argv)
{
}

string Tester_ASRestart::test()
{    
    shared_ptr<CostasArray> ca(make_shared<CostasArray>(10));
    shared_ptr<PSP> psp(make_shared<PSP>(ca));
    shared_ptr<AllCircularShiftAroundWorstRearrangeStrategy> str (make_shared<AllCircularShiftAroundWorstRearrangeStrategy>(ca->Domains().size()));
    shared_ptr<CircularShiftAroundBadRearrangeStrategy> str3 (make_shared<CircularShiftAroundBadRearrangeStrategy>(ca->Domains().size()));
    shared_ptr<AddAConstantRearrangeStrategy> str2 (make_shared<AddAConstantRearrangeStrategy>());
    vector<int> conf {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    psp->Start(conf);
    shared_ptr<Solution> sol = str->rearrangement(psp, conf);
    shared_ptr<Solution> sol2 = str2->rearrangement(psp, conf);
    shared_ptr<Solution> sol3 = str3->rearrangement(psp, conf);
    cout << sol->configurationToString() << endl;
    cout << sol2->configurationToString() << endl;
    cout << sol3->configurationToString() << endl;
    return "ok"; //(cc <= c) ? prefix + " -> AS_Restart 1: OK !" : "AS_Restart 1: fail :/";
}
