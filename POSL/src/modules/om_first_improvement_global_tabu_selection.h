#pragma once

#include "aom_selection_function.h"
#include "../tools/tabu_list.h"
#include "../data/dStrategy/neighbor_selecting_first_improvement_global_tabu.h"

class OM_FirstImprovementGlobalTabuSelection : public AOM_SelectionFunction
{
    public:
        OM_FirstImprovementGlobalTabuSelection(shared_ptr<Benchmark> bench, float _eps);

        shared_ptr<DecisionPair> spcf_execute(shared_ptr<PSP> psp, shared_ptr<Neighborhood> input);

        //! From Codable
        string codeToSend();

        virtual std::string Tag();

    protected:
        shared_ptr<NeighborSelectingFirstImprovementGlobalTabu> search_strategy;

        float eps;
};
