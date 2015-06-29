#include "tester_sets_index_generator.h"

#include "tools/rand_index_generator.h"

#include "modules/om_random_conf_generation.h"
#include "operators/operator.h"
#include "operators/rho_operator.h"
#include "modules/grouped_computation.h"
#include "modules/grouped_sequential_computation.h"
#include "computation/tools.h"

Tester_SetsIndexGenerator::Tester_SetsIndexGenerator()
{
}

string Tester_SetsIndexGenerator::test()
{
    RandIndexGenerator it(5 , 3);
    //  return Tools::int2str( it.indexes[0]->value);
    vector<vector<int>> inds = it.generate(20);
    cout << inds.size() << endl;
    for (std::vector<vector<int>>::iterator it = inds.begin(); it!=inds.end(); ++it)
    {
        for (std::vector<int>::iterator jt = (*it).begin(); jt!=(*it).end(); ++jt)
        {
            cout << *jt << " ";
        }
        cout << endl;
    }
    return "OK";
}
