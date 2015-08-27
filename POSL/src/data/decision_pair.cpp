#include "decision_pair.h"
#include "dStrategy/decision_pair_packing_strategy.h"

#include <iostream>
using namespace std;

DecisionPair::DecisionPair(Solution *_current, Solution *_found)
    : current(_current), found(_found), packing_strategy(new DecisionPairPackingStrategy(this))
{}

bool DecisionPair::equals()
{
    return current->equal(found);
}

Solution * DecisionPair::GetCurrent()
{
    return current;
}

Solution * DecisionPair::GetFound()
{
    return found;
}

vector<int> DecisionPair::pack()
{
    //cout << "pack" << endl;
    return packing_strategy->pack();
}

int DecisionPair::bodySize()
{
    //cout << "size" << endl;
    return packing_strategy->BodySize();
}

vector<int> DecisionPair::body()
{
    //cout << "body" << endl;
    return packing_strategy->body();
}
