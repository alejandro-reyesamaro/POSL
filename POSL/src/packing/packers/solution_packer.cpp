#include "solution_packer.h"

SolutionPacker::SolutionPacker(shared_ptr<Solution> solution)
    : Packer(solution->GetConfiguration().size() + 2),
      configuration(solution->GetConfiguration())
{
}

void SolutionPacker::update(vector<int> _configuration)
{
    copy(_configuration.begin(), _configuration.end(), configuration.begin());
}

vector<int> SolutionPacker::pack()
{
    //cout << "packing solution" << endl;
    int conf_size = configuration.size();
    //vector<int> package(conf_size + 2);

    // ID = 0
    package[0] = SOLUTION_PACKING_ID;
    // Configuration size
    package[1] = conf_size;
    // Configuration
    copy(configuration.begin(), configuration.end(), package.begin() + 2);
    return package;
}

/*
Solution * SolutionPacker::unpack(int * pack, vector<Domain> domains)
{
    int conf_size = pack[1];
    vector<int> config(conf_size);
    copy(pack + 2, pack + 2 + conf_size, config.begin());
    Solution * s = new Solution(domains, config);
    return s;
}
*/
