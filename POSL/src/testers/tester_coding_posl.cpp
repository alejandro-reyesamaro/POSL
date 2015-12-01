#include "tester_coding_posl.h"
#include "../modules/compound_module_generator_from_code.h"
#include "../tools/coding_tools.h"
#include "../tools/tokens_definition.h"
#include "../computation/computation_strategy.h"

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
        //string code = CodingTools::textFromFile("/home/reyesamaro-a/Documents/POSL/POSL_Code4Testing/a002.posl");
        //string code = CodingTools::textFromFile("/home/reyesamaro-a/Documents/POSL/POSL_Code4Testing/ra000.posl");
        string code = CodingTools::textFromFile("/home/reyesamaro-a/Documents/POSL/POSL_Code4Testing/sa000.posl");
        shared_ptr<CompoundModule> cm (make_shared<CompoundModuleGeneratorFromCode>(code, bench));

        //"OM_S", "OM_V", "OM_SS", "OM_D"
        vector<string> modules_instances = { OM_RANDOM_CONFIG_PERMUTATION_BY_BLOCKS_TOK,
                                             OM_GOLFERS_SINGLE_SWAP_NEIGHBORHOOD_TOK,
                                             OM_FIRST_IMPROVEMENT_SELECTION_TOK,
                                             OM_ALWAYS_IMPROVEMENT_DECISION_TOK};
        vector<string> ochannels_instances = {};

        string cs_code = CodingTools::textFromFile("/home/reyesamaro-a/Documents/POSL/POSL_Code4Testing/CS_a000.posl");
        //shared_ptr<ComputationStrategy> cs (make_shared<ComputationStrategy>(cs_code, modules_instances, ochannels_instances, bench));
    }
    catch (const char* msg)
    {
         return string("Tabu Selection: fail :/ [") + msg + "]";
    }

    return "CodingPOSL: OK !";
}
