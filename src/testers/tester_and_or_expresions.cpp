#include "tester_and_or_expresions.h"
#include "../solver/posl_meta_solver.h"

Tester_AndOrExpresions::Tester_AndOrExpresions(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_AndOrExpresions::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));\
    vector<int> conf = Tester::Golfers_442_c4();
    bench->SetDefaultConfiguration(conf);
    shared_ptr<POSL_MetaSolver> posl_ms (make_shared<POSL_MetaSolver>("/home/reyesamaro-a/Documents/POSL/src/testers/test_codes/test_and_or_expressions.posl", 10, bench));
    posl_ms->solve_sequentially();
    return "Testing expresions OK?";
}
