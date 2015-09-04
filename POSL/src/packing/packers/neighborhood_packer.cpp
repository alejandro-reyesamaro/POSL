#include "neighborhood_packer.h"
#include "../../data/from_pack_neighborhood.h"

#include <algorithm>

/*
 * Pack :
 * | ID | conf_size | conf | n_size | BODY |
 *
 * BODY :
 * | deg_1 | change_1 | deg_2 | change_2 | ... | deg_k | change_k | (k = n_size)
 *
 * change_i :
 * | pos_1 | value_1 | pos_2 | value_2 | ... | pos_l_i | value_l_i | (l_i = deg_i)
 * */

NeighborhoodPacker::NeighborhoodPacker(vector<int> _config, int _neighborhood_size, int size_package, int size_body)
    : Packer(size_package),
      configuration(_config),
      neighborhood_size(_neighborhood_size),
      body(size_body)
{}

vector<int> NeighborhoodPacker::pack()
{
    //cout << "packing neighborhood" << endl;
    int conf_size = configuration.size();
    //vector<int> package(conf_size + 3 + body_strategy->bodySize());
    // ID = 2
    package[0] = 658203;
    // Configuration size
    package[1] = conf_size;
    // Configuration (current)
    copy(configuration.begin(), configuration.end(), package.begin() + 2);
    // N_SIZE
    package[conf_size + 2] = neighborhood_size;

    // BODY
    packBody();
    copy(body.begin(), body.end(), package.begin() + conf_size + 3);
    return package;
}
