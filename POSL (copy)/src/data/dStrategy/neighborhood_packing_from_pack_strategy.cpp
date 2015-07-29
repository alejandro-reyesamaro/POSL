#include "neighborhood_packing_from_pack_strategy.h"

#include <algorithm>

NeighborhoodPackingFromPackStrategy::NeighborhoodPackingFromPackStrategy(int pack_size, int * _pack)
    :package(pack_size)
{
    copy(_pack, _pack + pack_size, package.begin());
    //for(int i = 0; i < pack_size; i++) package.push_back(_pack++);
}

vector<int> NeighborhoodPackingFromPackStrategy::pack()
{
    return package;
}

int NeighborhoodPackingFromPackStrategy::BodySize()
{
    int conf_size = package[1];
    int head_size = 3 + conf_size;
    return package.size() - head_size;
}

vector<int> NeighborhoodPackingFromPackStrategy::body()
{
    int conf_size = package[1];
    int head_size = 3 + conf_size;
    vector<int> body (BodySize());
    copy(package.begin() + head_size, package.end(), body.begin());
    return body;
}
