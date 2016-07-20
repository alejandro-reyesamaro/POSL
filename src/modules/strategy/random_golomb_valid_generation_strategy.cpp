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

RandomGolombValidGenerationStrategy::RandomGolombValidGenerationStrategy(shared_ptr<Benchmark> _bench_subsum,
                                                                         int _golomb_order,
                                                                         int _subsum_order)
    : //bench(_bench_subsum),
      golomb_order(_golomb_order),
      CM
      (
        make_shared<GroupedSequentialComputation>
          (
             make_shared<SequentialExecOperator>
              (
                  make_shared<OM_RandomPermutationGeneration>(_bench_subsum),
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
                                          make_shared<OM_SubsumSinglePermutationNeighborhood>(_bench_subsum),
                                          //make_shared<OM_FirstImprovementSelection>(bench)
                                          make_shared<OM_FirstImprovementGlobalTabuSelection>(_bench_subsum)
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
      golomb_configuration(_golomb_order, 0),
      subsum_configuration(_subsum_order, 0)
{}

vector<int> RandomGolombValidGenerationStrategy::generate(shared_ptr<PSP> psp_subsum)
{    
    int count = 0;
    do{
        sol = static_pointer_cast<Solution>(CM->execute(psp_subsum, make_shared<Seed>()));
    }
    while(psp_subsum->BestCostSoFar() != 0 && count ++ < MAX_ATTEMPTS);
    if(psp_subsum->BestCostSoFar() != 0)
        throw "(POSL Exception) Unable to find a starting solution (RandomGolombValidGenerationStrategy::generate)";
    subsum_configuration = sol->get_conf_by_copy();
    golomb_configuration = GolombTools::subsum2golomb(subsum_configuration, golomb_order);
    //cout << "random_golomb_valid_generation_strategy.cpp new conf size: " << golomb_configuration.size() << endl;
    return golomb_configuration;
}

/*
vector<int> RandomGolombValidGenerationStrategy::generate(std::shared_ptr<TabuObject> tabu_object)
{
    shared_ptr<SearchProcessParamsStruct> params(make_shared<SearchProcessParamsStruct>(tabu_object->GetTabuListSize(),
                                                                                        tabu_object->GetTabuNormType(),
                                                                                        tabu_object->GetTabuEps()));
    psp = make_shared<PSP>(bench, params);
    shared_ptr<ListIterator> tabu_iterator = tabu_object->GetTabusIterator();
    tabu_iterator->Reset();
    while(tabu_iterator->SomeNext())
    {
        vector<int> g_tabu = tabu_iterator->GetNext();
        for(int i = 0; i < golomb_order - 1; i++)
            subsum_configuration[i] = g_tabu[i+1] - g_tabu[i];
        if(!psp->GetTabuObject()->isGlobalTabu(subsum_configuration))
        {
            //cout << "random_golomb_valid_generation_strategy.cpp tabu size: " << subsum_configuration.size() << endl;
            psp->GetTabuObject()->addTabuSolution(subsum_configuration);
        }
    }
    return generate_conf();
}

vector<int> RandomGolombValidGenerationStrategy::generate()
{
    return generate_conf();
}
*/
