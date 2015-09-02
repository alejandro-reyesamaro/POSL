#include "uncode_operator_strategy.h"
#include "uncode_cyclic_operator_strategy.h"
#include "uncode_conditional_operator_strategy.h"
#include "uncode_binary_operator_strategy.h"
#include "uncode_rho_operator_strategy.h"
#include "../tools/tools.h"

UncodeOperatorStrategy::UncodeOperatorStrategy()
{}

Operator * UncodeOperatorStrategy::uncode(string code, Benchmark * bench)
{
    trim(code);
    char front = code.front();
    std::size_t pos_space = code.find_first_of(" ");
    string first = code.substr(0, pos_space);

    if (isdigit(front))
    {
        int oper = Tools::str2int(first);
        switch(oper){
            case 1: // CICLIC OPERATOR
            {
                UncodeCyclicOperatorStrategy * Cyc_strategy = new UncodeCyclicOperatorStrategy();
                return Cyc_strategy->uncode(code, bench);
            }
                break;
            case 2: // CONDITIONAL OPERATOR
            {
                UncodeConditionalOperatorStrategy * Con_strategy = new UncodeConditionalOperatorStrategy();
                return Con_strategy->uncode(code, bench);
            }
            break;
            case 3: // RHO OPERATOR
            {
                UncodeRhoOperatorStrategy * Rho_strategy = new UncodeRhoOperatorStrategy();
                return Rho_strategy->uncode(code, bench);
            }
            break;
            default:
            {
                UncodeBinaryOperatorStrategy * Bin_strategy = new UncodeBinaryOperatorStrategy();
                return Bin_strategy->uncode(code, bench);
            }
        }
    }
    else
        throw "Not well coded Operator";
}
