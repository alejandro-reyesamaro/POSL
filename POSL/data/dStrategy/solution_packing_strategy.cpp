#include "solution_packing_strategy.h"

SolutionPackingStrategy::SolutionPackingStrategy(vector<int> _config)
    : configuration(_config)
{
}

int * SolutionPackingStrategy::pack()
{
    int conf_size = configuration.size();
    int * package = new int[conf_size + 2];
    // ID = 0
    package[0] = 0;
    // Configuration size
    package[1] = conf_size;

    int count = 2;

    // Configuration
    for(vector<int>::iterator it = configuration.begin(); it != configuration.end(); ++it)
        package[count++] = *it;

    return package;
}
