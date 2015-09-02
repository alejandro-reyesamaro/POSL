#include "uncode_binary_operator_strategy.h"
#include "../operators/rho_operator.h"
#include "../operators/sequential_exec_operator.h"
#include "../operators/speed_operator.h"
#include "../operators/union_operator.h"
#include "uncode_compound_module_strategy.h"
#include "../tools/tools.h"

UncodeBinaryOperatorStrategy::UncodeBinaryOperatorStrategy()
{}

BinaryOperator * UncodeBinaryOperatorStrategy::uncode(string code, Benchmark * bench)
{
    trim(code);
    char front = code.front();
    size_t pos_space = code.find_first_of(" ");
    string first = code.substr(0, pos_space);

    string rest = code.substr(pos_space + 1);    
    trim(rest);
    string cm1_code = Tools::frontModule(rest);
    int sizefront = cm1_code.size();
    rest = rest.substr(sizefront);
    trim(rest);
    string cm2_code = Tools::frontModule(rest);

    UncodeCompoundModuleStrategy * cm_strategy = new UncodeCompoundModuleStrategy();

    if (isdigit(front))
    {
        int oper = Tools::str2int(first);
        switch(oper)
        {
            case 4: // Sequential execution
                return new SequentialExecOperator(cm_strategy->uncode(cm1_code, bench), cm_strategy->uncode(cm2_code, bench));
            break;
            case 5: // speed
                return new SpeedOperator(cm_strategy->uncode(cm1_code, bench), cm_strategy->uncode(cm2_code, bench));
            break;
            case 6: // Union
                return new UnionOperator(cm_strategy->uncode(cm1_code, bench), cm_strategy->uncode(cm2_code, bench));
            break;
        }
    }
    else
        throw "Not well coded Binary Operator";
}
