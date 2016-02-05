#include "operation_module_simulated_anealing_uncoder.h"
#include "../tools/coding_tools.h"
#include "../tools/tools.h"
#include "../tools/tokens_definition.h"

#include "../modules/om_always_improve_decision.h"
#include "../modules/om_simulated_annealing_decision.h"

using namespace std;

OperationModuleSimulatedAnealingUncoder::OperationModuleSimulatedAnealingUncoder()
{
}

shared_ptr<OperationModule> OperationModuleSimulatedAnealingUncoder::uncode(string code, shared_ptr<Benchmark>)
{
    pair<string, string> p = CodingTools::extractInnerCode(code, "(", ")", false, true);
    vector<string> params = CodingTools::split_string(p.first, '-');
    float start_prob = Tools::str2float(params[0]);
    float fall_rate  = Tools::str2float(params[1]);
    float t_iters    = Tools::str2float(params[2]);

    return make_shared<OM_SimulatedAnnealingDecision>(start_prob, fall_rate, t_iters);
}
