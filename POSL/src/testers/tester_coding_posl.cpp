#include "tester_coding_posl.h"
#include "../modules/compound_module_generator_from_code.h"
#include "../tools/tools.h"

Tester_CodingPOSL::Tester_CodingPOSL(int argc, char *argv[])
    : ARGC(argc), ARGV(argv)
{}

void Tester_CodingPOSL::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    string code = Tools::textFromFile("/home/reyesamaro-a/Documents/POSL/POSL_Code4Testing/strat1.posl");
    shared_ptr<CompoundModule> cm (make_shared<CompoundModuleGeneratorFromCode>(code, bench));
}
