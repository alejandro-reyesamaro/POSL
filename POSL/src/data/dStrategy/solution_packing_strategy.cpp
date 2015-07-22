#include "solution_packing_strategy.h"

#include <algorithm>

SolutionPackingStrategy::SolutionPackingStrategy(vector<int> _config)
    : configuration(_config)
{
}

vector<int> SolutionPackingStrategy::pack()
{
    int conf_size = configuration.size();    
    vector<int> package(conf_size + 2);

    // ID = 0
    package[0] = 0;
    // Configuration size
    package[1] = conf_size;
    // Configuration
    copy(configuration.begin(), configuration.end(), package.begin() + 2);
    return package;
}

int SolutionPackingStrategy::BodySize()
{
    throw "Not implemented";
}

vector<int> SolutionPackingStrategy::body()
{
    throw "Not implemented";
}
