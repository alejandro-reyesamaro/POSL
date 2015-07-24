#include "uncode_binary_operator_strategy.h"
#include "../operators/rho_operator.h"
#include "../operators/sequential_exec_operator.h"
#include "../operators/speed_operator.h"
#include "../operators/union_operator.h"
#include "uncode_compound_module_strategy.h"
#include "../tools/tools.h"

#include <boost/algorithm/string.hpp>
using namespace boost;

UncodeBinaryOperatorStrategy::UncodeBinaryOperatorStrategy()
{}

BinaryOperator * UncodeBinaryOperatorStrategy::uncode(string code)
{
    trim(code);
    char front = code.front();
    size_t pos_space = code.find_first_of(" ");
    string first = code.substr(0, pos_space);

    string rest = code.substr(pos_space + 1);
    trim(rest);
    pos_space = rest.find_first_of(" ");
    string cm1_code = code.substr(0, pos_space);
    string cm2_code = code.substr(pos_space + 1);
    trim(cm2_code);

    UncodeCompoundModuleStrategy * cm_strategy = new UncodeCompoundModuleStrategy();

    if (isdigit(front))
    {
        int oper = Tools::str2int(first);
        switch(oper){
            case 4: // Sequential execution
                return new SequentialExecOperator(cm_strategy->uncode(cm1_code), cm_strategy->uncode(cm2_code));
            break;
            case 5: // speed
                return new SpeedOperator(cm_strategy->uncode(cm1_code), cm_strategy->uncode(cm2_code));
            break;
            case 6: // Union
                return new UnionOperator(cm_strategy->uncode(cm1_code), cm_strategy->uncode(cm2_code));
            break;
        }
    }
    else
        throw "Not well coded Binary Operator";
}
