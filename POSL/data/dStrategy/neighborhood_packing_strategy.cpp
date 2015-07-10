#include "neighborhood_packing_strategy.h"

#include <vector>
#include <algorithm>

/*
 * Pack :
 * | ID | conf_size | conf | n_size | BODY |
 *
 * BODY :
 * | deg | change_1 | change_2 | ... | change_k | (k = n_size)
 *
 * change_i :
 * | pos_1 | value_1 | pos_2 | value_2 | ... | pos_l | value_l | (l = deg)
 * */

NeighborhoodPackingStrategy::NeighborhoodPackingStrategy(vector<int> current_config,
                                                         Neighborhood * _neighborhood,
                                                         NeighborhoodBodyPackingStrategy *_body_packing_strategy)
    : neighborhood(_neighborhood), config(current_config), body(_body_packing_strategy)
{}

int * NeighborhoodPackingStrategy::pack()
{
    int conf_size = config.size();
    int * package = new int[conf_size + 3 + body->bodySize()];
    // ID = 2
    package[0] = 2;
    // Configuration size
    package[1] = conf_size;
    // Configuration (current)
    copy(config.begin(), config.end(), package + 2);

    // BODY
    int * the_body = body->packBody();
    copy(the_body, the_body + body->bodySize(), package + conf_size + 2);

    return package;
}
