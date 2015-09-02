#include "neighborhood_packing_from_pack_strategy.h"

#include <algorithm>

int bSize(int conf_size, int package_size);

NeighborhoodPackingFromPackStrategy::NeighborhoodPackingFromPackStrategy(int pack_size, int * _pack)
    : package(pack_size),
      body_package(bSize(_pack[1], pack_size))
{
    update(pack_size, _pack);
}

void NeighborhoodPackingFromPackStrategy::update(int pack_size, int * _pack)
{
    copy(_pack, _pack + pack_size, package.begin());
}

int bSize(int conf_size, int package_size)
{
    int head_size = 3 + conf_size;
    return package_size - head_size;
}

vector<int> NeighborhoodPackingFromPackStrategy::pack(){ return package; }

int NeighborhoodPackingFromPackStrategy::BodySize(){ return bSize(package[1], package.size()); }

vector<int> NeighborhoodPackingFromPackStrategy::body()
{
    int conf_size = package[1];
    int head_size = 3 + conf_size;    
    copy(package.begin() + head_size, package.end(), body_package.begin());
    return body_package;
}
