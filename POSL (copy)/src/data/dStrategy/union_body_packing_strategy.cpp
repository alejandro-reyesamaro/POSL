#include "union_body_packing_strategy.h"

#include <algorithm>

UnionBodyPackingStrategy::UnionBodyPackingStrategy(Neighborhood *_V1, Neighborhood *_V2)
    : V1(_V1), V2(_V2),
      body(_V1->bodySize() + _V2->bodySize())
{}

int UnionBodyPackingStrategy::bodySize()
{
    return V1->bodySize() + V2->bodySize();
}

vector<int> UnionBodyPackingStrategy::packBody()
{
    //vector<int> body(bodySize());
    vector<int> body1 = V1->body();
    vector<int> body2 = V2->body();
    copy(body1.begin(), body1.end(), body.begin());
    copy(body2.begin(), body2.end(), body.begin() + V1->bodySize());
    return body;
}
