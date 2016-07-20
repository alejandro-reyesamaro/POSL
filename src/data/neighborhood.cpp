#include "neighborhood.h"

using namespace std;

Neighborhood::Neighborhood(vector<int> _current_configuration)
    : current_configuration(_current_configuration)
{}

Neighborhood::Neighborhood(int _config_size)
    : current_configuration(_config_size)
{}

int Neighborhood::comapareTo(shared_ptr<ComputationData> other,
                             function<int(shared_ptr<ComputationData>)>)
{
    if(other->Tag() == TAGNEIGHBORHOOD)
    {
        int ranking_this = size();
        int ranking_other = static_pointer_cast<Neighborhood>(other)->size();
        int difference = ranking_this - ranking_other;
        return (difference == 0) ? 0 : difference / abs(difference);
    }
    else throw "(POSL Exception) Not compearing allowed (Neighborhood::comapareTo)";
}
