#include "seed.h"
#include <chrono>
#include <cmath>

using namespace std;

Seed::Seed()
    : Seed(time(0))//abs(chrono::system_clock::now().time_since_epoch().count()))
{}

Seed::Seed(int _seed)
    : my_seed(_seed)
{}

std::shared_ptr<FactoryPacker> Seed::BuildPacker(){ throw "Not implemented yet"; }

int Seed::comapareTo(shared_ptr<ComputationData> other,
                     function<int(shared_ptr<ComputationData>)>)
{
    if(other->Tag() == TAGSEED)
    {
        int difference = my_seed - static_pointer_cast<Seed>(other)->seed();
        return (difference == 0) ? 0 : difference / abs(difference);
    }
    else throw "(POSL Exception) Not compearing allowed (Seed::comapareTo)";
}
