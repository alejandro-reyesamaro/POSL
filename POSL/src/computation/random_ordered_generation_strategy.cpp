#include "random_ordered_generation_strategy.h"
#include "../data/dStrategy/factory_n_int_domain.h"

#include <algorithm>

RandomOrderedGenerationStrategy::RandomOrderedGenerationStrategy() : rand()
{}

void RandomOrderedGenerationStrategy::place (int a, int b, int pos_1, int pos_2, vector<int> & config)
{
    if(pos_1 > pos_2) return;
    if(pos_1 == pos_2)
    {
        int k = rand.NextInt(a, b);
        config[pos_1] = k;
    }
    else
    {
        int b_izq = (a+b)/2;
        int b_der = (a+b)/2 + 1;
        place(a, b_izq, pos_1, (pos_1+pos_2)/2, config);
        place(b_der, b, (pos_1+pos_2)/2+1, pos_2, config);
    }
}

Solution * RandomOrderedGenerationStrategy::generate(int size, int max)
{
    vector<int> config(size);
    switch (size)
    {
        case 0:
            throw "(POSL Exception) Bad generation parameters";
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
            place(1, max/2, 1, size/2, config);
            place(max/2+1, max-1, size/2+1, size-2, config);
            break;
    }

    FactoryDomain * fd_integers = new Factory_NIntDomain(0, max);
    Domain D(fd_integers);
    vector<Domain> domains (size, D);
    Solution * new_solution = new Solution(domains, config);
    return new_solution;
}
