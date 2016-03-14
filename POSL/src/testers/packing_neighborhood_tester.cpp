#include "packing_neighborhood_tester.h"
#include "../data/neighborhood.h"
#include "../tools/tools.h"
#include "../packing/packers/neighborhood_packer.h"
#include "../data/from_pack_neighborhood.h"

#include <algorithm>
#include <iostream>

using namespace std;

PackingNeighborhoodTester::PackingNeighborhoodTester()
{
}

string PackingNeighborhoodTester::test(shared_ptr<Solution> sol, shared_ptr<POSL_Iterator> neighbors, vector<int> pack, string label)
{
    neighbors->Reset();
    string sol_str = sol->configurationToString();

    shared_ptr<Neighborhood> final(make_shared<FromPackNeighborhood>(&pack[0]));
    bool succ = final->size() != 0; // No me gusta :/

    // | ID |
    int id = pack[0];

    // | conf_size |
    int conf_size = pack[1];

    // | configuration |
    string conf_str = "[ ";
    int count = 2;
    for(vector<int>::iterator it = pack.begin() + 2; it != pack.begin() + conf_size + 2 - 1; ++it)
    {
        conf_str += Tools::int2str(* it) + ", ";
        count ++;
    }
    conf_str += Tools::int2str(*(pack.begin() + conf_size + 2 - 1)) +" ]";
    count ++;

    bool legal = conf_str.compare(sol_str) == 0;

    // | n_size |
    //int n_size = pack[count];
    count++;
    shared_ptr<Solution> sol_aux;
    shared_ptr<Solution> neighbor_aux;
    vector<int> conf_aux (32);
    vector<Domain> dom = sol->GetDomains();

    while(neighbors->SomeNext())
    {
        vector<int> neighbor = neighbors->GetNext();
        //cout << "new config... " << Tools::configurationToString(neighbor) << endl;
        sol_aux = make_shared<Solution>(dom, neighbor);
        //cout << sol_aux->configurationToString() << endl;
        int deg = pack[count++];
        vector<int> sol_conf = sol->get_conf_by_copy();
        copy(sol_conf.begin(), sol_conf.end(), conf_aux.begin());
        for(int i = 0; i < deg; i++)
        {
            int pos = pack[count++];
            int value = pack[count++];
            //cout << pos << " - " << value << endl;
            conf_aux[pos] = value;
        }                
        neighbor_aux = make_shared<Solution>(dom, conf_aux);
        //string sol_aux_str = sol_aux->configurationToString();
        //string neighbor_aux_str = neighbor_aux->configurationToString();
        legal = legal && sol_aux->configurationToString().compare(neighbor_aux->configurationToString()) == 0;
        //if(!legal) return "fail";
    }

    //cout << conf_str << endl;
    //cout << pack_str << endl;

    return  (succ && legal)
            ? label + ": (" + Tools::int2str(id) + ") OK !"
            : label + ": fail :/";
}
