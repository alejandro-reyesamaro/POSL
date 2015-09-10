#include "golfers_long_int_cost_strategy.h"
#include "../../tools/tools.h"

#include <algorithm>

using namespace std;

#define TP players * groups     /* total players */
#define TG groups * weeks       /* total groups  */
#define TL players * groups / 32 + 1
#define PENALIZATION 10

GolfersLongIntCostStrategy::GolfersLongIntCostStrategy(int _groups, int _players, int _weeks)
    : groups(_groups),
      players(_players),
      weeks(_weeks),alldiff (TL, 0),
      new_partner (TL, 0),
      global_partnership (TL, 0),
      global_partners (TP + 1, LongInt(TL, 0)),
      group_partners (TP + 1, LongInt(TL, 0))
{}

int GolfersLongIntCostStrategy::solutionCost(std::vector<int> configuration)
{
    //cout << sol->configurationToString() << endl;
    int golfers = players * groups;
    int table_length = golfers / 32 + 1; // how long must be the LongInt
    //vector<LongInt> global_partners (golfers+1, LongInt(table_length, 0)); // player i in pos i
    fill(global_partners.begin(), global_partners.end(), LongInt(table_length, 0));
    //vector<LongInt> group_partners (golfers+1, LongInt(table_length, 0));
    fill(group_partners.begin(), group_partners.end(), LongInt(table_length, 0));

    alldiff.deactivateAll(); //alldiff.clearBits(); // LongInt alldiff (table_length, 0);

    int cost = 0;

    for(int w = 0; w < weeks; w++)
    {
        //int start_week_group = w * (players * groups);
        //int end_week_group = start_week_group + groups;

        for(int g = 0; g < groups; g++)
        {
            int start_tournament = g * players + w * (groups * players);
            int end_tournament   = start_tournament + players;

            //cout << start_tournament << ", " << end_tournament << endl;

            for(int i = start_tournament; i < end_tournament; i++)
            {
                for(int j = start_tournament; j < end_tournament; j++)
                {
                    alldiff.activate(configuration[i]);
                    if(i != j)
                    {
                        //if(i == 16) cout << sol->configuration[i] << endl;
                        //if(i == 16) cout << global_partners[sol->configuration[i]].toString() << endl;
                        new_partner.deactivateAll(); //new_partner.clearBits();// LongInt new_partner (table_length, 0);
                        new_partner.activate(configuration[j]);
                        //cout << new_partner.toString() << endl;
                        //cout << i << "- " << sol->GetConfiguration()[i] << endl;
                        group_partners[configuration[i]] = group_partners[configuration[i]] | new_partner;
                        //cout << group_partners[sol->GetConfiguration()[i]].toString() << endl;
                    }
                    //cout << group_partners[sol->configuration[i]].toString() << endl;
                }
                //cout << "GROUP Partners of :" << sol->configuration[i] << ": " << group_partners[sol->configuration[i]].toString() << endl;
                //cout << "GLOBALPartners of :" << sol->configuration[i] << ": " << global_partners[sol->configuration[i]].toString() << endl;
            }
        }
        //actual cost

        //cout << "Computing current cost" << endl;
        for(vector<LongInt>::iterator it_global = global_partners.begin(), it_group = group_partners.begin(); it_global != global_partners.end(); ++it_global, ++it_group)
        {
            //cout << it_group->toString() << endl;
            global_partnership.deactivateAll(); //global_partnership.clearBits();
            global_partnership = *it_global & *it_group;
            cost += global_partnership.bitCount();
            *it_global = *it_global | *it_group;
            //cout << it_global->toString() << endl;
        }
        //vector<LongInt> aux (golfers+1, LongInt(table_length, 0));
        //group_partners = aux;
        fill(group_partners.begin(), group_partners.end(), LongInt(table_length, 0));

        // all differents cost
        //cout << alldiff.toString() << endl;
        //cout << "Partial cost " << cost << endl;
        cost += (golfers - alldiff.bitCount()) * PENALIZATION; // PENALISATION

        //cout << "Cost week " << w+1 << " = " << cost << endl;

        alldiff.deactivateAll();

        //cout << "End week " << w+1 << endl;

    }// O ( p^2 * g * w ) = O ( p * n )

    //cout << "End" << endl;
    return cost;
}

