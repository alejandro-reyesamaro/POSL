#include "om_golomb_valid_generation_fromset.h"
#include "../tools/tokens_definition.h"
#include "../tools/tools.h"
#include "../tools/golomb_tools.h"

#include <random>
#include <iostream>

using namespace std;

OM_GolombValidGenerationFromSet::OM_GolombValidGenerationFromSet(shared_ptr<Benchmark> bench)
    : AOM_FirstConfigurationGenerationFromSet(bench),
      rsolution(make_shared<Solution>(bench->Variable_Domain(), bench->Dimension())),
      object_golomb(dynamic_pointer_cast<GolombRuler>(bench)),
      golomb_order(object_golomb->Order()),
      subsum(object_golomb->Length()),
      n(object_golomb->Order()-1),
      values(Tools::generateMonotony(1, GolombTools::max_posible_distances(object_golomb->Order(), object_golomb->Length()))),
      object_subsum(make_shared<Subsum>(values, subsum, n)),
      subsum_psp(nullptr),
      subsum_configuration(values.size(), 0),
      rconf_strategy(make_shared<RandomGolombValidGenerationStrategy>(object_subsum,
                                                                      object_golomb->Order(),
                                                                      object_golomb->Length()))
{}

shared_ptr<Solution> OM_GolombValidGenerationFromSet::spcf_execute(shared_ptr<PSP> psp, std::shared_ptr<ConfigurationSet> conf_set)
{    
    //cout << "om_golomb_valid_generation_from_set..." << endl;
    if(!subsum_psp)
    {
        shared_ptr<SearchProcessParamsStruct> params =
                make_shared<SearchProcessParamsStruct>(psp->GetTabuObject()->GetTabuListSize(),
                                                       psp->GetTabuObject()->GetTabuNormType(),
                                                       psp->GetTabuObject()->GetTabuEps());
        subsum_psp = make_shared<PSP>(object_subsum, params);
    }

    // The tabu list remains, but the rest is restarted
    subsum_psp->clear_information();

    // TABU coming from outside    
    if(conf_set)
    {
        shared_ptr<POSL_Iterator> tabu_iterator = conf_set->getIterator();
        tabu_iterator->Reset();

        while(tabu_iterator->SomeNext())
        {
            vector<int> g_tabu = tabu_iterator->GetNext();
            for(int i = 0; i < golomb_order - 1; i++)
                subsum_configuration[i] = g_tabu[i+1] - g_tabu[i];
            if(!subsum_psp->GetTabuObject()->isGlobalTabu(subsum_configuration))
            {
                subsum_psp->GetTabuObject()->addTabuSolution(subsum_configuration);
            }
        }
    }

    // TABU coming from inside
    if(psp->GetTabuObject()->ThereIsTabu())
    {
        vector<int> g_tabu = psp->GetTabuObject()->GetLastArrivedTabu();
        for(int i = 0; i < golomb_order - 1; i++)
            subsum_configuration[i] = g_tabu[i+1] - g_tabu[i];
        if(!subsum_psp->GetTabuObject()->isGlobalTabu(subsum_configuration))
        {
            subsum_psp->GetTabuObject()->addTabuSolution(subsum_configuration);
        }
    }

    rsolution->UpdateConfiguration(rconf_strategy->generate(subsum_psp));
    psp->Start(rsolution->get_conf_by_ref());

    /*
    if(psp->GetTabuObject()->ThereIsTabu())
    {
        //cout << "tabu arrived" << endl;
        //last_global_tabu_configuration = psp->GetTabuObject()->GetLastArrivedTabu();
        //rsolution->UpdateConfiguration(rconf_strategy->generate(last_global_tabu_configuration));
        rsolution->UpdateConfiguration(rconf_strategy->generate(psp->GetTabuObject()));
    }
    else
        rsolution->UpdateConfiguration(rconf_strategy->generate(psp->GetTabuObject()));
    */
    //psp->log("Start ");
    //cout << rsolution->configurationToString() << endl;//"OM_S" << endl;
    return rsolution;
}

string OM_GolombValidGenerationFromSet::codeToSend()
{
    return OM_RANDOM_CONFIG_GOLOMB_VALID_FROM_SET_TOK;
}

string OM_GolombValidGenerationFromSet::Tag()
{
    return "Golomb_first_fromSet";
}
