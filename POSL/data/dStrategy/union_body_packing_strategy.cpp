#include "union_body_packing_strategy.h"

#include <algorithm>

using namespace std;

UnionBodyPackingStrategy::UnionBodyPackingStrategy(Packable *_V1, Packable *_V2)
    : V1(_V1), V2(_V2)
{}

int UnionBodyPackingStrategy::bodySize()
{
    // Each change * (deg, pos and value)
    // MAL : debe calcularse por cada cambio
    return V1->bodySize() + V2->bodySize();
}

int * UnionBodyPackingStrategy::packBody()
{
    int * body = new int[bodySize()];
    int * body1 = V1->body();
    int * body2 = V2->body();
    copy(body1, body1 + V1->bodySize(), body);
    copy(body2, body2 + V2->bodySize(), body + V1->bodySize());
    return body;
}
