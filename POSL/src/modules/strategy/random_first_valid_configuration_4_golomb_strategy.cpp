#include "random_first_valid_configuration_4_golomb_strategy.h"

#include "../../tools/tools.h"
#include "../../benchmarks/subsum.h"

#include "../../modules/om_random_permutation_generation.h"
#include "../../modules/om_subsum_single_permutation_neighborhood.h"
#include "../../modules/om_first_improvement_selection.h"
#include "../../modules/om_always_improve_decision.h"
#include "../../modules/grouped_sequential_computation.h"

#include "../../operators/sequential_exec_operator.h"
#include "../../operators/cyclic_operator.h"

#include "../../expressions/loop_bound_expression.h"

#include <algorithm>
#include <iostream>

using namespace std;

RandomFirstValidConfiguration4GolombStrategy::RandomFirstValidConfiguration4GolombStrategy()
{}

std::vector<int> RandomFirstValidConfiguration4GolombStrategy::generate(shared_ptr<Randomizer> rand, int subsum, int n, int set_size)
{
    shared_ptr<Benchmark> bench(make_shared<Subsum>(Tools::generateMonotony(1,set_size), subsum, n));
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    shared_ptr<CompoundModule> OM_S (make_shared<OM_RandomPermutationGeneration>(bench));
    shared_ptr<CompoundModule> OM_V (make_shared<OM_SubsumSinglePermutationNeighborhood>(bench));
    shared_ptr<CompoundModule> OM_SS (make_shared<OM_FirstImprovementSelection>(bench));
    shared_ptr<CompoundModule> OM_D (make_shared<OM_AlwaysImproveDecision>());

    shared_ptr<Operator> sec_1(make_shared<SequentialExecOperator>(OM_V, OM_SS));
    shared_ptr<GroupedComputation> Gsec1(make_shared<GroupedSequentialComputation>(sec_1));

    shared_ptr<Operator> sec_2(make_shared<SequentialExecOperator>(Gsec1, OM_D));
    shared_ptr<GroupedComputation> Gsec2(make_shared<GroupedSequentialComputation>(sec_2));

    shared_ptr<Operator> cyc(make_shared<CyclicOperator>(Gsec2, make_shared<LoopBoundExpression>(2000)));
    shared_ptr<GroupedComputation> Gcyc(make_shared<GroupedSequentialComputation>(cyc));

    shared_ptr<Operator> sec_3(make_shared<SequentialExecOperator>(OM_S, Gcyc));
    shared_ptr<GroupedComputation> Gsec3(make_shared<GroupedSequentialComputation>(sec_3));

    shared_ptr<Solution> sol = static_pointer_cast<Solution>(Gsec3->execute(psp, make_shared<Seed>()));
    if(psp->BestCostSoFar() != 0)
        throw "(POSL Exception) Unable to find a starting solution (RandomFirstValidConfiguration4GolombStrategy::generate)";
    return sol->get_conf_by_copy();
}
