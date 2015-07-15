#include "packing_neighborhood_tester.h"
#include "tools/tools.h"

#include <algorithm>
#include <iostream>

using namespace std;

PackingNeighborhoodTester::PackingNeighborhoodTester()
{
}

string PackingNeighborhoodTester::test(Benchmark * bench, Solution * sol, POSL_Iterator<vector<int>> * neighbors, int * pack, string label)
{
    neighbors->Reset();
    string sol_str = sol->configurationToString();

    // | ID |
    int id = * pack;
    pack ++;

    // | conf_size |
    int conf_size = * pack;
    pack ++;

    // | configuration |
    string conf_str = "[ ";
    for(int i = 0; i < conf_size - 1; i++)
        conf_str += Tools::int2str(* pack ++) + ", ";
    conf_str += Tools::int2str(* pack ++) +" ]";
    bool legal = conf_str.compare(sol_str) == 0;

    // | n_size |
    int n_size = * pack;
    pack ++;

    while(neighbors->SomeNext())
    {
        vector<int> neighbor = neighbors->GetNext();
        Solution * sol_aux = new Solution(bench->GetSolution()->domains, neighbor);
        int deg = * pack;
        //cout << deg << endl;
        pack++;
        vector<int> conf_aux (32);
        copy(sol->configuration.begin(), sol->configuration.end(), conf_aux.begin());
        for(int i = 0; i < deg; i++)
        {
            int pos = * pack;
            pack ++;
            int value = * pack;
            pack ++;
            //cout << pos << " - " << value << endl;
            conf_aux[pos] = value;
        }
        Solution * neighbor_aux = new Solution(bench->GetSolution()->domains, conf_aux);
        legal = legal && sol_aux->configurationToString().compare(neighbor_aux->configurationToString()) == 0;
        delete (neighbor_aux);
    }

    //cout << conf_str << endl;
    //cout << pack_str << endl;

    return  (legal)
            ? label + ": (" + Tools::int2str(id) + ") : OK !"
            : label + ": fail :/";
}
