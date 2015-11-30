#include "computation_strategy.h"
#include "../data/seed.h"
#include "../tools/coding_tools.h"
//#include "../modules/compound_module_generator_from_code.h"

#include <iostream>
using namespace std;

ComputationStrategy::ComputationStrategy(shared_ptr<FactoryComputationStrategy> builder)
    : TAG(builder->TAG),
      module(builder->buildModule())
{}

/*
shared_ptr<CompoundModule> init_module(string code, vector<string> om_instances, vector<std::string> och_instances, shared_ptr<Benchmark> bench)
{
    pair<vector<string>, vector<string>> p = CodingTools::extractModulesNamesFromCS(code);
    string cm_code = CodingTools::extractCompoundModuleCodeFromCS(code);
    vector<string> om_names = p.first;
    vector<string> och_names = p.second;

    if(om_names.size() > 0)
        CodingTools::replace(cm_code, om_names, om_instances);
    if(och_names.size() > 0)
        CodingTools::replace(cm_code, och_names, och_instances);
    return make_shared<CompoundModuleGeneratorFromCode>(cm_code, bench);
}
*/

ComputationStrategy::ComputationStrategy(string code, vector<string> om_instances, vector<string> och_instances, shared_ptr<Benchmark> bench)
    : TAG(CodingTools::extractDeclarationName(code)),
      cs_code(code),
      module(cs_uncoder.uncode(code, om_instances, och_instances, bench))
{}

ComputationStrategy::ComputationStrategy(string code)
    : TAG(CodingTools::extractDeclarationName(code)),
      cs_code(code)
{}


void ComputationStrategy::Instantiate(vector<string> om_instances, vector<string> och_instances, shared_ptr<Benchmark> bench)
{
    module = cs_uncoder.uncode(cs_code, om_instances, och_instances, bench);
}

shared_ptr<Solution> ComputationStrategy::execute(shared_ptr<PSP> psp)
{
    if(module)
        return static_pointer_cast<Solution>(module->execute(psp, make_shared<Seed>()));
    else
        throw "(POSL Exception) The compound module is not ready (ComputationStrategy::execute)";
}
