#include "golfers_long_int_cost_strategy.h"
#include "../../tools/tools.h"

#include <algorithm>
#include <iostream>

using namespace std;

#define TP players * groups     /* total players */
#define TG groups * weeks       /* total groups  */
#define TL players * groups / 32 + 1
#define PENALIZATION 10

GolfersLongIntCostStrategy::GolfersLongIntCostStrategy(int _groups, int _players, int _weeks)
    : groups(_groups),
      players(_players),
      weeks(_weeks),
      alldiff (TL, 0),
      new_partner (TL, 0),
      global_partnership (TL, 0),
      global_partners (TP + 1, LongInt(TL, 0)),
      group_partners (TP + 1, LongInt(TL, 0))
{}

int GolfersLongIntCostStrategy::solutionCost(std::vector<int> configuration)
{
    int golfers = TP; //players * groups;
    int table_length = TL; //golfers / 32 + 1; // how long must be the LongInt
    fill(global_partners.begin(), global_partners.end(), LongInt(table_length, 0));
    fill(group_partners.begin(), group_partners.end(), LongInt(table_length, 0));

    alldiff.deactivateAll();

    int cost = 0;

    for(int w = 0; w < weeks; w++)
    {
        for(int g = 0; g < groups; g++)
        {
            int start_tournament = (w * TP) + (g * players);
            int end_tournament   = start_tournament + players;

            for(int i = start_tournament; i < end_tournament; i++)
                for(int j = start_tournament; j < end_tournament; j++)
                {
                    alldiff.activate(configuration[i]-1); // 0-based
                    if(i != j)
                    {
                        //new_partner.deactivateAll(); //new_partner.clearBits();// LongInt new_partner (table_length, 0);
                        //new_partner.activate(configuration[j]);
                        //group_partners[configuration[i]] = group_partners[configuration[i]] | new_partner;
                        group_partners[configuration[i]].activate(configuration[j]-1);
                    }
                }
        }
        for(vector<LongInt>::iterator it_global = global_partners.begin(), it_group = group_partners.begin(); it_global != global_partners.end(); ++it_global, ++it_group)
        {
            global_partnership.deactivateAll();
            global_partnership = *it_global & *it_group;
            cost += global_partnership.bitCount();
            *it_global = *it_global | *it_group;
        }
        fill(group_partners.begin(), group_partners.end(), LongInt(table_length, 0));
        //cout << alldiff.toString() << endl;
        // all differents cost
        int bc = alldiff.bitCount();
        cost += (golfers - alldiff.bitCount()) * PENALIZATION;
        alldiff.deactivateAll();
    }// O ( p^2 * g * w ) = O ( p * n )
    return cost;
}

