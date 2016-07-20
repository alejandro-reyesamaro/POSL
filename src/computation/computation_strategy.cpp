#include "computation_strategy.h"
#include "../data/seed.h"
#include "../tools/coding_tools.h"

#include <iostream>
using namespace std;

ComputationStrategy::ComputationStrategy(string name, string code)
    : TAG(name),
      cs_code(code)
{}


void ComputationStrategy::Instantiate(vector<string> & om_instances,
                                      vector<string> & och_instances,
                                      shared_ptr<Benchmark> bench,
                                      shared_ptr<SearchProcessParamsStruct> psp_params)
{
    module = cs_uncoder.uncode(cs_code, om_instances, och_instances, bench, psp_params);
}

shared_ptr<Solution> ComputationStrategy::execute(shared_ptr<PSP> psp)
{
    if(module)
        return static_pointer_cast<Solution>(module->execute(psp, make_shared<Seed>(0)));
    else
        throw "(POSL Exception) The compound module is not ready (ComputationStrategy::execute)";
}
