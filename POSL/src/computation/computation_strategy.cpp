#include "computation_strategy.h"
#include "../data/seed.h"
#include "../tools/coding_tools.h"
#include "../modules/compound_module_generator_from_code.h"

#include <iostream>
using namespace std;

ComputationStrategy::ComputationStrategy(shared_ptr<FactoryComputationStrategy> builder)
    : TAG(builder->TAG),
      module(builder->buildModule())
{}

shared_ptr<CompoundModule> init_module(string code, vector<string> om_instances, vector<std::string> och_instances, shared_ptr<Benchmark> bench)
{
    pair<vector<string>, vector<string>> p = CodingTools::extractModulesNamesFromCS(code);
    string cm_code = CodingTools::extractCompoundModuleCodeFromCS(code);
    vector<string> om_names = p.first;
    vector<string> och_names = p.second;

    CodingTools::replace(cm_code, om_names, om_instances);
    CodingTools::replace(cm_code, och_names, och_instances);
    return make_shared<CompoundModuleGeneratorFromCode>(code, bench);
}

ComputationStrategy::ComputationStrategy(string code, vector<string> om_names, vector<string> och_names, shared_ptr<Benchmark> bench)
    : TAG(CodingTools::extractComputationStrategyName(code)),
      module(init_module(code, om_names, och_names, bench))
{}


shared_ptr<Solution> ComputationStrategy::execute(shared_ptr<PSP> psp)
{
    return static_pointer_cast<Solution>(module->execute(psp, make_shared<Seed>()));
}
