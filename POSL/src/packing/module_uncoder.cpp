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

shared_ptr<BooleanExpression> ModuleUncoder::uncodeBoolExpression(string code)
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
                return make_shared<IteretionBoundExpression>(param);
            break;
            case 2: // loob bound
                returnmake_shared<LoopBoundExpression(param);
            break;
            case 3: // reached cost
                returnmake_shared<ReachedCostExpression(param);
            break;
            default:
                throw "(POSL Exception) Not well coded BooleanExpression";
        }
    }
    else
        throw "(POSL Exception) Not well coded BooleanExpression (ID)";
}

shared_ptr<CyclicOperator> ModuleUncoder::uncodeCyclicOperator(string code, shared_ptr<Benchmark> bench)
{
    std::size_t pos_open = code.find_first_of("(");
    std::size_t pos_close = code.find_first_of(")");
    string be_code = code.substr(pos_open + 1, pos_close - pos_open - 1);
    string cm_code = code.substr(pos_close + 1);
    returnmake_shared<CyclicOperator>(uncodeCompoundModule(cm_code, bench), uncodeBoolExpression(be_code));
}

shared_ptr<ConditionalOperator> ModuleUncoder::uncodeConditionalOperator(string code, shared_ptr<Benchmark> bench)
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

    return make_shared<ConditionalOperator>(uncodeCompoundModule(cm1_code, bench),
                                   uncodeCompoundModule(cm2_code, bench),
                                   uncodeBoolExpression(be_code));
}

shared_ptr<RhoOperator> ModuleUncoder::uncodeRhoOperator(string code, shared_ptr<Benchmark> bench)
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

    return make_shared<RhoOperator>(uncodeCompoundModule(cm1_code, bench), uncodeCompoundModule(cm2_code, bench), param);
}

shared_ptr<BinaryOperator> ModuleUncoder::uncodeBinaryOperator(string code, shared_ptr<Benchmark> bench)
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
                return make_shared<SequentialExecOperator>(uncodeCompoundModule(cm1_code, bench), uncodeCompoundModule(cm2_code, bench));
            break;
            case 5: // speed
                return make_shared<SpeedOperator>(uncodeCompoundModule(cm1_code, bench), uncodeCompoundModule(cm2_code, bench));
            break;
            case 6: // Union
                return make_shared<UnionOperator>(uncodeCompoundModule(cm1_code, bench), uncodeCompoundModule(cm2_code, bench));
            break;
        }
    }
    else
        throw "Not well coded Binary Operator";
}

shared_ptr<Operator> ModuleUncoder::uncodeOperator(string code, shared_ptr<Benchmark> bench)
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

shared_ptr<GroupedSequentialComputation> ModuleUncoder::uncodeGroupedSequentialComputation(string code, shared_ptr<Benchmark> bench)
{
    return make_shared<GroupedSequentialComputation>(uncodeOperator(code, bench));
}

GroupedParallelComputation * ModuleUncoder::uncodeGroupedParallelComputation(string code, shared_ptr<Benchmark> bench)
{
    return make_shared<GroupedParallelComputation>(uncodeOperator(code, bench));
}

shared_ptr<OperationModule> ModuleUncoder::uncodeOperationModule(string code, shared_ptr<Benchmark> bench)
{
    trim(code);
    char L = code.front();
    int  N = Tools::str2int(code.substr(1));

    if(L == 'A') // FIRST CONFIGURATION GENERATION
    {
        switch(N)
        {
            case 1: // fixed first configuration
                return make_shared<OM_FixedFirstConfiguration>(bench);
                break;
            case 2: // random first configuration
                return make_shared<OM_RandomConfGeneration>(bench);
                break;
            case 3:

                break;
            case 4: // random permutation by blocks
                return make_shared<OM_RandomConfPermutationByBlocksGeneration>(bench);
                break;
            case 5: // random ordered permutation
                return make_shared<OM_RandomConfOrderedGeneration>(bench);
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
                return make_shared<OM_OneElementChangedNeighborhood>(bench);
                break;
            case 2: // multi elements change neighborhood
                return make_shared<OM_MultiElementsChangedNeighborhood>(bench);
                break;
            case 3: // golfers neighborhood
                return make_shared<OM_GolfersSingleSwapNeighborhood>(bench);
                break;
            case 4: // golom neighborhood (multi)
                return make_shared<OM_MultiSortedChangesNeighborhood>(bench);
                break;
            case 5: // golom neighborhood (one)
                return make_shared<OM_OneSortedChangeNeighborhood>(bench);
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
                return make_shared<OM_RandomSelection>(bench);
                break;
            case 2: // First Improvement selection
                return make_shared<OM_FirstImprovementSelection>(bench);
                break;
            case 3: // Best Improvement selection
                return make_shared<OM_BestImprovementSelection>(bench);
                break;
            case 4: // Best Improvement TABU selection
                return make_shared<OM_BestImprovementTabuSelection>(bench);
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
                return make_shared<OM_AlwaysImproveDecision>();
                break;
            case 2: // simulated annealing
                return make_shared<OM_SimulatedAnnealingDecision>();
                break;
            default:
                throw "Not well coded OperationModule (Decission)";
        }
    }
    else
        throw "Not well coded OperationModule";
}

shared_ptr<CompoundModule> ModuleUncoder::uncodeCompoundModule(string code, shared_ptr<Benchmark> bench)
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

