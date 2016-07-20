#include "neighbor_selecting_k_best_improvement.h"

using namespace std;

NeighborSelectingKBestImprovement::NeighborSelectingKBestImprovement(shared_ptr<Domain> domain, int dimension, int k)
    : K(k),
      rPair(make_shared<DecisionPair>(make_shared<Solution>(domain, dimension), make_shared<Solution>(domain, dimension)))
{}

shared_ptr<DecisionPair> NeighborSelectingKBestImprovement::select(shared_ptr<PSP> psp, shared_ptr<Neighborhood> V)
{
    current_config = psp->GetCurrentSolution()->get_conf_by_copy();
    int current_cost = psp->CurrentCost();
    //best_found_config = psp->GetCurrentSolution()->GetConfiguration();
    //int best_found_cost = current_cost;
    int c;

    it = V->getIterator();
    it->Reset();
    selection_tree.reset();

    while(it->SomeNext())
    {
        neighbor = it->GetNext();
        c = psp->GetBenchmark()->relativeSolutionCost(neighbor);
        if(c < current_cost)
        {
            if (selection_tree)
            {
                if (!selection_tree->exist_cost(c))
                    selection_tree->insert(neighbor, c);
            }
            else selection_tree = make_shared<BinarySearchTree<std::vector<int>>>(neighbor, c);
        }
    }

    if(selection_tree)
    {
        neighbor = selection_tree->get_value_in_position(K);
        rPair->update(current_config, neighbor);
    }
    else
        rPair->update(current_config, current_config);
    return rPair;
}
