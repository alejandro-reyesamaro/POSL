#include "golfers_default_show_strategy.h"
#include "../../tools/tools.h"

using namespace std;

GolfersDefaultShowStrategy::GolfersDefaultShowStrategy(int _groups, int _players, int _weeks)
    : groups(_groups),
      players(_players),
      weeks(_weeks)
{}

string GolfersDefaultShowStrategy::showSolution(shared_ptr<Solution> solution)
{
    string out =  "Golfers: players-" + Tools::int2str(players);
           out += ", groups-" + Tools::int2str(groups);
           out += ", weeks-" + Tools::int2str(weeks) + "\n";
    vector<int> config = solution->GetConfiguration();
    vector<int>::iterator it = config.begin();
    for(int w = 0; w < weeks; w ++)
    {
        for(int g = 0; g < groups; g ++)
        {
            for(int p = 0; p < players; p ++)
            {
                int value = *it;
                out += Tools::int2str(value) + "\t";
                it ++;
            }
            out += "\n";
        }
        out += "--\n";
    }
    return out;
}
