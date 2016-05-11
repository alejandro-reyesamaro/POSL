#include "om_golomb_valid_generation.h"
#include "../tools/tokens_definition.h"

#include <random>
#include <iostream>

using namespace std;

OM_GolombValidGeneration::OM_GolombValidGeneration(shared_ptr<Benchmark> bench)
    : AOM_FirstConfigurationGeneration(bench),
      rsolution(make_shared<Solution>(bench->Variable_Domain(), bench->Dimension())),
      object_bench(dynamic_pointer_cast<GolombRuler>(bench)),
      rconf_strategy(make_shared<RandomGolombValidGenerationStrategy>(object_bench->Order(),
                                                                      object_bench->Length())),
      order(object_bench->Order()),
      golomb_configuration(object_bench->Order(),0),
      subsum_configuration(object_bench->Order())
{}

shared_ptr<Solution> OM_GolombValidGeneration::spcf_execute(shared_ptr<PSP> psp, std::shared_ptr<Seed>)
{
    subsum_configuration = rconf_strategy->generate();
    //golomb_configuration[0] = 0; // --> already done in constructor
    for(int i = 0; i < order-1; i++)
        golomb_configuration[i+1] = golomb_configuration[i] + subsum_configuration[i];
    rsolution->UpdateConfiguration(golomb_configuration);
    psp->Start(golomb_configuration);//(rsolution->get_conf_by_ref());
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
