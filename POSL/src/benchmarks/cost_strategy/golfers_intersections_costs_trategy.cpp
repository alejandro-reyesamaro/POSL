#include "golfers_intersections_costs_trategy.h"
#include "../../tools/tools.h"

#include <algorithm>

using namespace std;

#define TP players * groups     /* total players */
#define TG groups * weeks       /* total groups  */

GolfersIntersectionsCostStrategy::GolfersIntersectionsCostStrategy(int _groups, int _players, int _weeks)
    : groups(_groups),
      players(_players),
      weeks(_weeks),
      perm(Tools::generateMonotony(1, TP))
{}


int group_coincidences(vector<int>::iterator it_lg_begin,
                       vector<int>::iterator it_lg_end,
                       vector<int>::iterator it_rg_begin,
                       vector<int>::iterator it_rg_end)
{
    vector<int>::iterator it;
    it = find_first_of(it_lg_begin, it_lg_end, it_rg_begin, it_rg_end);
    if(it == it_lg_end)
        return 0;
    it = find_first_of(it + 1, it_lg_end, it_rg_begin, it_rg_end);
    return (it == it_lg_end)? 0 : 1;
}


int GolfersIntersectionsCostStrategy::solutionCost(std::vector<int> configuration)
{
    int cost = 0, i = 0;
    int N = configuration.size();

    for(i = 0; i < weeks; i++)
        cost += (is_permutation(configuration.begin() + i * TP, configuration.begin() + (i+1) * TP, perm.begin()))
                ? 0
                : N;

    for(i = 0; i < TG; i++)
        sort(configuration.begin() + i * players, configuration.begin() + (i+1) * players);

    int lg_begin, lg_end, rg_begin, rg_end, j = 0, w = 0;
    for(w = 0; w < weeks; w++)
    {
        for(i = 0; i < groups; i++)
        {
            lg_begin = (w * TP) + i * players;
            lg_end   = (w * TP) + (i+1) * players;

            for(j = 0; j < groups; j++)
            {
                rg_begin = (w * TP) + TP + j * players;
                rg_end   = (w * TP) + TP + (j+1) * players;
                cost += group_coincidences(configuration.begin()+lg_begin,
                                           configuration.begin()+lg_end,
                                           configuration.begin()+rg_begin,
                                           configuration.begin()+rg_end);
            }

        }
    }

    return cost;
}

