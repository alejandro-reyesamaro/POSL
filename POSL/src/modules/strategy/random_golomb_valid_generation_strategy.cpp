#include "random_golomb_valid_generation_strategy.h"
#include "../../tools/tools.h"
#include "../../tools/golomb_tools.h"
#include "../../benchmarks/subsum.h"

#include "../../modules/om_random_permutation_generation.h"
#include "../../modules/om_subsum_single_permutation_neighborhood.h"
#include "../../modules/om_first_improvement_selection.h"
#include "../../modules/om_first_improvement_global_tabu_selection.h"
#include "../../modules/om_always_improve_decision.h"
#include "../../modules/grouped_sequential_computation.h"

#include "../../operators/sequential_exec_operator.h"
#include "../../operators/cyclic_operator.h"

#include "../../expressions/loop_bound_expression.h"

#include <algorithm>
#include <iostream>

using namespace std;

#define MAX_ATTEMPTS 100
#define MAX_ITERS 2000
#define EPS 4

RandomGolombValidGenerationStrategy::RandomGolombValidGenerationStrategy(int _order, int _length)
    : subsum(_length),
      n(_order - 1),
      golomb_order(_order),
      values(Tools::generateMonotony(1, GolombTools::max_posible_distances(_order, _length))),
      bench(make_shared<Subsum>(values, subsum, n)),
      psp(make_shared<PSP>(bench)),
      CM
      (
        make_shared<GroupedSequentialComputation>
          (
             make_shared<SequentialExecOperator>
              (
                  make_shared<OM_RandomPermutationGeneration>(bench),
                  make_shared<GroupedSequentialComputation>
                  (
                      make_shared<CyclicOperator>
                      (
                          make_shared<GroupedSequentialComputation>
                          (
                              make_shared<SequentialExecOperator>
                              (
                                  make_shared<GroupedSequentialComputation>
                                  (
                                      make_shared<SequentialExecOperator>
                                      (
                                          make_shared<OM_SubsumSinglePermutationNeighborhood>(bench),
                                          //make_shared<OM_FirstImprovementSelection>(bench)
                                          make_shared<OM_FirstImprovementGlobalTabuSelection>(bench, EPS)
                                      )
                                  ),
                                  make_shared<OM_AlwaysImproveDecision>()
                              )
                          ),
                          make_shared<LoopBoundExpression>(MAX_ITERS)
                      )
                  )
              )
          )
      ),
      golomb_configuration(_order, 0),
      subsum_configuration(_order - 1, 0)
{}

vector<int> RandomGolombValidGenerationStrategy::generate_conf()
{
    int count = 0;
    do{
        sol = static_pointer_cast<Solution>(CM->execute(psp, make_shared<Seed>()));
    }
    while(psp->BestCostSoFar() != 0 && count ++ < MAX_ATTEMPTS);
    if(psp->BestCostSoFar() != 0)
        throw "(POSL Exception) Unable to find a starting solution (RandomGolombValidGenerationStrategy::generate)";
    subsum_configuration = sol->get_conf_by_copy();
    for(int i = 0; i < golomb_order - 1; i++)
        golomb_configuration[i+1] = golomb_configuration[i] + subsum_configuration[i];
    return golomb_configuration;
}

vector<int> RandomGolombValidGenerationStrategy::generate(vector<int> & configuration_tabu)
{
    for(int i = 0; i < golomb_order - 1; i++)
        subsum_configuration[i] = configuration_tabu[i+1] - configuration_tabu[i];
    if(!psp->GetTabuObject()->isGlobalTabu(subsum_configuration))
        psp->GetTabuObject()->addTabuSolution(subsum_configuration);
    return generate_conf();
}

vector<int> RandomGolombValidGenerationStrategy::generate()
{
    return generate_conf();
}
