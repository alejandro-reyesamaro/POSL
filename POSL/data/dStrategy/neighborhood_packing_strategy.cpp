#include "neighborhood_packing_strategy.h"

#include <vector>
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

NeighborhoodPackingStrategy::NeighborhoodPackingStrategy(vector<int> current_config,
                                                         int _neighborhood_size,
                                                         NeighborhoodBodyPackingStrategy *_body_packing_strategy)
    : neighborhood_size(_neighborhood_size), config(current_config), body_strategy(_body_packing_strategy)
{}

int * NeighborhoodPackingStrategy::pack()
{
    int conf_size = config.size();
    int * package = new int[conf_size + 3 + body_strategy->bodySize()];
    // ID = 2
    package[0] = 2;
    // Configuration size
    package[1] = conf_size;
    // Configuration (current)
    copy(config.begin(), config.end(), package + 2);
    // N_SIZE
    *(package + conf_size + 2) = neighborhood_size;

    // BODY
    int * the_body = body_strategy->packBody();
    copy(the_body, the_body + body_strategy->bodySize(), package + conf_size + 3);

    return package;
}

int NeighborhoodPackingStrategy::BodySize()
{
    return body_strategy->bodySize();
}

int * NeighborhoodPackingStrategy::body()
{
    return body_strategy->packBody();
}
