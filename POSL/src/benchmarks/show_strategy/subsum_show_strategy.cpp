#include "subsum_show_strategy.h"
#include "../../tools/tools.h"

using namespace std;

SubsumShowStrategy::SubsumShowStrategy(std::vector<int> _values, int _n)
    : values(_values),
      n(_n)
{}

string SubsumShowStrategy::showSolution(std::shared_ptr<Solution> solution)
{
    vector<int> config = solution->get_conf_by_ref();
    string txt = "[ ";
    vector<int>::iterator it = config.begin();
    txt += Tools::int2str(*it);
    it++;
    while ( it != config.begin()+n)
    {
        txt += ", " + Tools::int2str(*it);
        ++it;
    }
    return txt + " ]";
    return txt;
}
