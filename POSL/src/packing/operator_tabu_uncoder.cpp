#include "operator_tabu_uncoder.h"
#include "../tools/coding_tools.h"
#include "compound_module_uncoder.h"
#include "../operators/tabu_operator.h"

using namespace std;

OperatorTabuUncoder::OperatorTabuUncoder()
{
}

shared_ptr<Operator> OperatorTabuUncoder::uncode(string code, shared_ptr<Benchmark> bench)
{
    pair<pair<string, string>, string> p = CodingTools::separateTokenAndCode(code);

    //string type = p.first.first;        //token type (OP)
    //string name = p.first.second;       //token name (Tabu)
    string module = p.second;

    CompoundModuleUncoder cm_unc;
    return make_shared<TabuOperator>(cm_unc.uncode(module, bench));
}
