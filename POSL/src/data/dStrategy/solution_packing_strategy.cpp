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
    package[0] = SOLUTION_PACKING_ID;
    // Configuration size
    package[1] = conf_size;
    // Configuration
    copy(configuration.begin(), configuration.end(), package.begin() + 2);
    return package;
}

Solution * SolutionPackingStrategy::unpack(int * pack, vector<Domain> domains)
{
    int conf_size = pack[1];
    vector<int> config(conf_size);
    copy(pack + 2, pack + 2 + conf_size, config.begin());
    Solution * s = new Solution(domains, config);
    return s;
}

int SolutionPackingStrategy::BodySize()
{
    throw "Not implemented";
}

vector<int> SolutionPackingStrategy::body()
{
    throw "Not implemented";
}
