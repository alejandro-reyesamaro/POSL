#include "om_golomb_valid_generation.h"
#include "../tools/tokens_definition.h"
#include "../tools/tools.h"
#include "../tools/golomb_tools.h"

#include <random>
#include <iostream>

using namespace std;

OM_GolombValidGeneration::OM_GolombValidGeneration(shared_ptr<Benchmark> bench)
    : AOM_FirstConfigurationGeneration(bench),
      rsolution(make_shared<Solution>(bench->Variable_Domain(), bench->Dimension())),
      object_bench(dynamic_pointer_cast<GolombRuler>(bench)),      
      golomb_order(object_bench->Order()),
      golomb_length(object_bench->Length()),
      subsum(object_bench->Length()),
      n(object_bench->Order()-1),
      values(Tools::generateMonotony(1, GolombTools::max_posible_distances(object_bench->Order(), object_bench->Length()))),
      object_subsum(make_shared<Subsum>(values, subsum, n)),
      subsum_psp(nullptr),
      subsum_configuration(values.size(), 0),
      rconf_strategy(make_shared<RandomGolombValidGenerationStrategy>(object_subsum,
                                                                      object_bench->Order(),
                                                                      object_bench->Length()))
{}

shared_ptr<Solution> OM_GolombValidGeneration::spcf_execute(shared_ptr<PSP> psp, std::shared_ptr<Seed>)
{
    if(!subsum_psp)
    {
        shared_ptr<SearchProcessParamsStruct> params =
                make_shared<SearchProcessParamsStruct>(psp->GetTabuObject()->GetTabuListCapacity(),
                                                       psp->GetTabuObject()->GetTabuNormType(),
                                                       psp->GetTabuObject()->GetTabuEps());
        subsum_psp = make_shared<PSP>(object_subsum, params);
    }

    // The tabu list remains, but the rest is restarted
    subsum_psp->clear_information();

    // TABU coming from inside
    if(psp->GetTabuObject()->ThereIsTabu())
    {
        vector<int> g_tabu = psp->GetTabuObject()->GetLastArrivedTabu();
        subsum_configuration = GolombTools::golomb2subsum(g_tabu, golomb_order, golomb_length);
        if(!subsum_psp->GetTabuObject()->isGlobalTabu(subsum_configuration))
        {
            subsum_psp->GetTabuObject()->addTabuSolution(subsum_configuration);
        }
    }

    rsolution->UpdateConfiguration(rconf_strategy->generate(subsum_psp));
    psp->Start(rsolution->get_conf_by_ref());

    /*
    //int it = psp->GetIterations();
    //int cost = psp->BestCostSoFar();
    if(psp->GetTabuObject()->ThereIsTabu())
    {
        //cout << "tabu arrived" << endl;
        //last_global_tabu_configuration = psp->GetTabuObject()->GetLastArrivedTabu();
        //rsolution->UpdateConfiguration(rconf_strategy->generate(last_global_tabu_configuration));
        rsolution->UpdateConfiguration(rconf_strategy->generate(psp->GetTabuObject()));
    }
    else
        rsolution->UpdateConfiguration(rconf_strategy->generate(psp->GetTabuObject()));
    psp->Start(rsolution->get_conf_by_ref());
    */
    //psp->log("Start ");
    //cout << rsolution->configurationToString() << endl;//"OM_S" << endl;
    return rsolution;
}

string OM_GolombValidGeneration::codeToSend()
{
    return OM_RANDOM_CONFIG_GOLOMB_VALID_TOK;
}

string OM_GolombValidGeneration::Tag()
{
    return "Golomb_first";
}
