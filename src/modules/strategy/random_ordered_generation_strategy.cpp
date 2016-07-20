#include "random_ordered_generation_strategy.h"
#include "../../data/dStrategy/factory_n_int_domain.h"

#include <algorithm>

RandomOrderedGenerationStrategy::RandomOrderedGenerationStrategy(int configuration_size)
    : config(configuration_size)
{}

void RandomOrderedGenerationStrategy::place(shared_ptr<Randomizer> rand, int a, int b, int pos_1, int pos_2)
{
    if(pos_1 > pos_2) return;
    if(pos_1 == pos_2)
    {
        int k = rand->NextInt(a, b);
        config[pos_1] = k;
    }
    else
    {
        int b_izq = (a+b)/2;
        int b_der = (a+b)/2 + 1;
        place(rand, a, b_izq, pos_1, (pos_1+pos_2)/2);
        place(rand, b_der, b, (pos_1+pos_2)/2+1, pos_2);
    }
}

std::vector<int> RandomOrderedGenerationStrategy::generate(shared_ptr<Randomizer> rand, int max)
{
    int size = config.size();
    switch (size)
    {
        case 0:
            throw "(POSL Exception) Bad generation parameters (RandomOrderedGenerationStrategy::generate)";
        break;
        case 1:
            config[0] = 0;
        break;
        case 2:
            config[0] = 0;
            config[1] = max;
        break;
        default:
            config[0] = 0;
            config[size-1] = max;
            place(rand, 1, max/2, 1, size/2);
            place(rand, max/2+1, max-1, size/2+1, size-2);
            break;
    }
    return config;
}
