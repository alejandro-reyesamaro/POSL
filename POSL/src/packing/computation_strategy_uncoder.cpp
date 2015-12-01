#include "computation_strategy_uncoder.h"
#include "../tools/coding_tools.h"
#include "../modules/compound_module_generator_from_code.h"

using namespace std;

ComputationStrategyUncoder::ComputationStrategyUncoder()
{}

shared_ptr<CompoundModule> ComputationStrategyUncoder::uncode(string code,
                                                              vector<string> om_instances,
                                                              vector<std::string> och_instances,
                                                              shared_ptr<Benchmark> bench)
{
    pair<vector<string>, vector<string>> p = CodingTools::extractModulesNamesFromDeclaration(code);

    string cm_code = CodingTools::extractCompoundModuleCodeFromCS(code);
    vector<string> om_names = p.first;
    vector<string> och_names = p.second;

    if(om_names.size() > 0)
        CodingTools::replace(cm_code, om_names, om_instances);
    if(och_names.size() > 0)
        CodingTools::replace(cm_code, och_names, och_instances);
    return make_shared<CompoundModuleGeneratorFromCode>(cm_code, bench);
}
