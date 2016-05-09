#include "random_golomb_valid_generation_strategy.h"
#include "../../data/dStrategy/factory_n_int_domain.h"
#include "../../tools/tools.h"
#include "../../tools/golomb_tools.h"

#include <algorithm>

RandomGolombValidGenerationStrategy::RandomGolombValidGenerationStrategy(int _order, int _length)
    : order(_order),
      length(_length),
      config(_order),
      possible_measures(Tools::generateMonotony(1, GolombTools::max_posible_distances(_order, _length)))
{}

vector<int> RandomGolombValidGenerationStrategy::generate(shared_ptr<Randomizer> rand)
{
    rand->vector_shuffle(possible_measures);
    return config;
}
