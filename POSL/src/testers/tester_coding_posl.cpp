#include "tester_coding_posl.h"
#include "../modules/compound_module_generator_from_code.h"
#include "../tools/coding_tools.h"

Tester_CodingPOSL::Tester_CodingPOSL(int argc, char *argv[])
    : Tester(argc, argv)
{}

string Tester_CodingPOSL::test()
{
    try
    {
        shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
        //string code = CodingTools::textFromFile("/home/reyesamaro-a/Documents/POSL/POSL_Code4Testing/a000.posl");
        //string code = CodingTools::textFromFile("/home/reyesamaro-a/Documents/POSL/POSL_Code4Testing/a001.posl");
        string code = CodingTools::textFromFile("/home/reyesamaro-a/Documents/POSL/POSL_Code4Testing/a002.posl");
        shared_ptr<CompoundModule> cm (make_shared<CompoundModuleGeneratorFromCode>(code, bench));
    }catch (const char* msg)
    {
         return string("Tabu Selection: fail :/ [") + msg + "]";
    }

    return "CodingPOSL: OK !";
}
