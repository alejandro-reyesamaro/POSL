#include "module_uncoder.h"
#include "../tools/tools.h"

#include "../modules/om_fixed_first_configuration.h"
#include "../modules/om_random_conf_generation.h"
#include "../modules/om_random_conf_permutation_by_blocks_generation.h"
#include "../modules/om_random_conf_ordered_generation.h"

#include "../modules/om_one_element_changed_neighborhood.h"
#include "../modules/om_multi_elements_changed_neighborhood.h"
#include "../modules/om_golfers_single_swap_neighborhood.h"
#include "../modules/om_multi_sorted_changes_neighborhood.h"
#include "../modules/om_one_sorted_change_neighborhood.h"

#include "../modules/om_best_improvement_selection.h"
#include "../modules/om_best_improvement_tabu_selection.h"
#include "../modules/om_random_selection.h"
#include "../modules/om_first_improvement_selection.h"

#include "../modules/om_always_improve_decision.h"
#include "../modules/om_simulated_annealing_decision.h"

#include "../operators/cyclic_operator.h"
#include "../operators/conditional_operator.h"
#include "../operators/rho_operator.h"
#include "../operators/sequential_exec_operator.h"
#include "../operators/speed_operator.h"
#include "../operators/union_operator.h"

#include "../expressions/iteretion_bound_expression.h"
#include "../expressions/loop_bound_expression.h"
#include "../expressions/reached_cost_expression.h"

#include <boost/algorithm/string.hpp>
using namespace boost;

ModuleUncoder::ModuleUncoder()
{}

BooleanExpression * ModuleUncoder::uncodeBoolExpression(string code)
{
    trim(code);
    std::size_t pos_space = code.find_first_of(" ");
    string be_code = code.substr(0, pos_space);
    string rest = code.substr(pos_space);
    trim(rest);

    int param = Tools::str2int(rest);
    char L = be_code.front();
    int  N = Tools::str2int(be_code.substr(1));

    if(L == 'b')
    {
        switch(N)
        {
            case 1: // iteration bound
                return new IteretionBoundExpression(param);
            break;
            case 2: // loob bound
                return new LoopBoundExpression(param);
            break;
            case 3: // reached cost
                return new ReachedCostExpression(param);
            break;
            default:
                throw "(POSL Exception) Not well coded BooleanExpression";
        }
    }
    else
        throw "(POSL Exception) Not well coded BooleanExpression (ID)";
}

CyclicOperator * ModuleUncoder::uncodeCyclicOperator(string code, Benchmark * bench)
{
    std::size_t pos_open = code.find_first_of("(");
    std::size_t pos_close = code.find_first_of(")");
    string be_code = code.substr(pos_open + 1, pos_close - pos_open - 1);
    string cm_code = code.substr(pos_close + 1);
    return new CyclicOperator(uncodeCompoundModule(cm_code, bench), uncodeBoolExpression(be_code));
}

ConditionalOperator * ModuleUncoder::uncodeConditionalOperator(string code, Benchmark * bench)
{
    std::size_t pos_open = code.find_first_of("(");
    std::size_t pos_close = code.find_first_of(")");
    string be_code = code.substr(pos_open + 1, pos_close - pos_open - 1);
    string rest = code.substr(pos_close + 1);
    trim(rest);
    string cm1_code = Tools::frontModule(rest);
    int sizefront = cm1_code.size();
    rest = rest.substr(sizefront);
    trim(rest);
    string cm2_code = Tools::frontModule(rest);

    return new ConditionalOperator(uncodeCompoundModule(cm1_code, bench),
                                   uncodeCompoundModule(cm2_code, bench),
                                   uncodeBoolExpression(be_code));
}

RhoOperator * ModuleUncoder::uncodeRhoOperator(string code, Benchmark * bench)
{
    std::size_t pos_open = code.find_first_of("(");
    std::size_t pos_close = code.find_first_of(")");
    string str_param = code.substr(pos_open + 1, pos_close - pos_open - 1);
    trim(str_param);
    float param = Tools::str2float(str_param);
    string rest = code.substr(pos_close + 1);
    trim(rest);
    string cm1_code = Tools::frontModule(rest);
    int sizefront = cm1_code.size();
    rest = rest.substr(sizefront);
    trim(rest);
    string cm2_code = Tools::frontModule(rest);

    return new RhoOperator(uncodeCompoundModule(cm1_code, bench), uncodeCompoundModule(cm2_code, bench), param);
}

BinaryOperator * ModuleUncoder::uncodeBinaryOperator(string code, Benchmark * bench)
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

    if (isdigit(front))
    {
        int oper = Tools::str2int(first);
        switch(oper)
        {
            case 4: // Sequential execution
                return new SequentialExecOperator(uncodeCompoundModule(cm1_code, bench), uncodeCompoundModule(cm2_code, bench));
            break;
            case 5: // speed
                return new SpeedOperator(uncodeCompoundModule(cm1_code, bench), uncodeCompoundModule(cm2_code, bench));
            break;
            case 6: // Union
                return new UnionOperator(uncodeCompoundModule(cm1_code, bench), uncodeCompoundModule(cm2_code, bench));
            break;
        }
    }
    else
        throw "Not well coded Binary Operator";
}

Operator * ModuleUncoder::uncodeOperator(string code, Benchmark * bench)
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
                return uncodeCyclicOperator(code, bench);
                break;
            case 2: // CONDITIONAL OPERATOR
                return uncodeConditionalOperator(code, bench);
                break;
            case 3: // RHO OPERATOR
                return uncodeRhoOperator(code, bench);
            break;
            default:
                return uncodeBinaryOperator(code, bench);
        }
    }
    else
        throw "Not well coded Operator";
}

GroupedSequentialComputation * ModuleUncoder::uncodeGroupedSequentialComputation(string code, Benchmark * bench)
{
    return new GroupedSequentialComputation(uncodeOperator(code, bench));
}

GroupedParallelComputation * ModuleUncoder::uncodeGroupedParallelComputation(string code, Benchmark * bench)
{
    return new GroupedParallelComputation(uncodeOperator(code, bench));
}

OperationModule * ModuleUncoder::uncodeOperationModule(string code, Benchmark * bench)
{
    trim(code);
    char L = code.front();
    int  N = Tools::str2int(code.substr(1));

    if(L == 'A') // FIRST CONFIGURATION GENERATION
    {
        switch(N)
        {
            case 1: // fixed first configuration
                return new OM_FixedFirstConfiguration(bench);
                break;
            case 2: // random first configuration
                return new OM_RandomConfGeneration(bench);
                break;
            case 3:

                break;
            case 4: // random permutation by blocks
                return new OM_RandomConfPermutationByBlocksGeneration(bench);
                break;
            case 5: // random ordered permutation
                return new OM_RandomConfOrderedGeneration(bench);
                break;
            default:
                throw "Not well coded OperationModule (First Configuration)";
        }
    }
    else if(L == 'B') // NEIGHBORHOOD
    {
        switch(N)
        {
            case 1: // one element change neighborhood
                return new OM_OneElementChangedNeighborhood(bench);
                break;
            case 2: // multi elements change neighborhood
                return new OM_MultiElementsChangedNeighborhood(bench);
                break;
            case 3: // golfers neighborhood
                return new OM_GolfersSingleSwapNeighborhood(bench);
                break;
            case 4: // golom neighborhood (multi)
                return new OM_MultiSortedChangesNeighborhood(bench);
                break;
            case 5: // golom neighborhood (one)
                return new OM_OneSortedChangeNeighborhood(bench);
                break;
            default:
                throw "Not well coded OperationModule (Neighborhood)";
        }
    }
    else if(L == 'C') // SELECTION
    {
        switch(N)
        {
            case 1: // random selection
                return new OM_RandomSelection(bench);
                break;
            case 2: // First Improvement selection
                return new OM_FirstImprovementSelection(bench);
                break;
            case 3: // Best Improvement selection
                return new OM_BestImprovementSelection(bench);
                break;
            case 4: // Best Improvement TABU selection
                return new OM_BestImprovementTabuSelection(bench);
                break;
            default:
                throw "Not well coded OperationModule (Selection)";
        }
    }
    else if(L == 'D') // DECISSION
    {
        switch(N)
        {
            case 1: // always improve
                return new OM_AlwaysImproveDecision();
                break;
            case 2: // simulated annealing
                return new OM_SimulatedAnnealingDecision();
                break;
            default:
                throw "Not well coded OperationModule (Decission)";
        }
    }
    else
        throw "Not well coded OperationModule";
}

CompoundModule * ModuleUncoder::uncodeCompoundModule(string code, Benchmark * bench)
{
    trim(code);
    char front = code.front();
    char back  = code.back();
    string sub_code = code.substr(1, code.size() - 2);

    // GROUPERS ---- '{.}': sequential, '[.]': parallel
    if (front == '{' && back == '}')
        return uncodeGroupedSequentialComputation(sub_code, bench);
    else if (front == '[' && back == ']')
        return uncodeGroupedParallelComputation(sub_code, bench);
    else
        return uncodeOperationModule(code, bench);
}

