#include "golfers.h"
#include "../tools/long_int.h"
#include "../tools/tools.h"
#include "../data/dStrategy/factory_n_int_domain.h"

#include <vector>
#include <iostream>

using namespace std;

#define PENALIZATION 10

Golfers::Golfers(int g, int p, int w) : groups(g), players(p), weeks(w)
{
}

vector<Domain> Golfers::Domains()
{
    FactoryDomain * fd_integers = new Factory_NIntDomain(1,TotalPlayers());
    Domain D(fd_integers);
    vector<Domain> domains (groups * players * weeks, D);
    return domains;
}

int Golfers::solutionCost(Solution * sol)
{
    //cout << sol->configurationToString() << endl;
    int golfers = players * groups;
    int table_length = golfers / 32 + 1;                                        // how long must be the LongInt
    vector<LongInt> global_partners (golfers+1, LongInt(table_length, 0));         // player i in pos i
    vector<LongInt> group_partners (golfers+1, LongInt(table_length, 0));
    LongInt alldiff (table_length, 0);

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
                    alldiff.activate(sol->GetConfiguration()[i]);
                    if(i != j)
                    {
                        //if(i == 16) cout << sol->configuration[i] << endl;
                        //if(i == 16) cout << global_partners[sol->configuration[i]].toString() << endl;
                        LongInt new_partner (table_length, 0);
                        new_partner.activate(sol->GetConfiguration()[j]);
                        //cout << new_partner.toString() << endl;
                        //cout << i << "- " << sol->GetConfiguration()[i] << endl;
                        group_partners[sol->GetConfiguration()[i]] = group_partners[sol->GetConfiguration()[i]] | new_partner;
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
            LongInt global = *it_global & *it_group;
            cost += global.bitCount();
            *it_global = *it_global | *it_group;
            //cout << it_global->toString() << endl;
        }
        vector<LongInt> aux (golfers+1, LongInt(table_length, 0));
        group_partners = aux;

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

int Golfers::Groups(){ return groups; }

int Golfers::PlayersPerGroup(){ return players; }

int Golfers::Weeks(){ return weeks; }

int Golfers::TotalPlayers(){ return players * groups; }

string Golfers::ShowSolution(Solution * solution)
{
    string out = "";
    vector<int>::iterator it = solution->GetConfiguration().begin();
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
