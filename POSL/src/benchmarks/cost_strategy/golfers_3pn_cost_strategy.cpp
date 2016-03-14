#include "golfers_3pn_cost_strategy.h"
#include "../../tools/tools.h"

#include <algorithm>

using namespace std;

#define TP players * groups     /* total players */
#define TG groups * weeks       /* total groups  */
#define TL (players * groups + 1) / 32 + 1
#define PENALIZATION TP

Golfers3PNCostStrategy::Golfers3PNCostStrategy(int _groups, int _players, int _weeks)
    : groups(_groups),
      players(_players),
      weeks(_weeks),
      alls(TL), // all activated
      group_partners (TP + 1, LongInt(TL, 0)),
      global_partners (TP + 1, LongInt(TL, 0)),
      repetitions (TP + 1, LongInt(TL, 0)),
      perm(Tools::generateMonotony(1, _players * _groups))

{
}

int Golfers3PNCostStrategy::solutionCost(std::vector<int> & configuration)
{
    int begin_gr, cost = 0;
    fill(global_partners.begin(), global_partners.end(), LongInt(TL, 0));
    fill(group_partners.begin(), group_partners.end(), LongInt(TL, 0));
    fill(repetitions.begin(), repetitions.end(), alls);

    std::vector<int> perm2 = Tools::generateMonotony(1, TP);
    for(int w = 0; w < weeks; w++)
    {
        cost += (is_permutation (perm2.begin(), perm2.end(), configuration.begin() + w * TP))
                ? 0
                : PENALIZATION;

        // parnerts in the group
        for(int g = 0; g < groups; g ++)
        {
            begin_gr = (w * TP) + (g * players);
            for(int i = 0; i < players; i++)
                for(int j = 0; j < players; j++)
                {
                    group_partners[configuration[begin_gr + i]].activate(configuration[begin_gr + j]);
                    //repetitions[configuration[begin_gr + i]] =
                    //        repetitions[configuration[begin_gr + i]]
                    //        & group_partners[configuration[begin_gr + i]];
                }
         }

        // partners in the tournament
        for(int i = 0; i < TP; i ++)
        {
            global_partners[configuration[i]] =
                    global_partners[configuration[i]] | group_partners[configuration[i]];
            //group_partners[configuration[i]].deactivateAll();
        }

        // finding the players playing more than once

        for(int i = 0; i < TP; i ++)
        {
            repetitions[configuration[i]] =
                    repetitions[configuration[i]] & global_partners[configuration[i]];
            group_partners[configuration[i]].deactivateAll();
        }

    }

    for(int i = 0; i < TP; i++)
        cost += repetitions[i].bitCount();

    return cost;
}

