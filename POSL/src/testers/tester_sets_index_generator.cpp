#include "tester_sets_index_generator.h"
#include "../tools/rand_index_generator.h"
#include "../tools/tools.h"

Tester_SetsIndexGenerator::Tester_SetsIndexGenerator(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_SetsIndexGenerator::test()
{
    shared_ptr<Benchmark> bench(make_shared<Golfers>(4,4,2));
    shared_ptr<Solution> sol(make_shared<Solution>(bench->Domains()));
    //bench->UpdateSolution(sol);
    shared_ptr<PSP> psp(make_shared<PSP>(bench));

    RandIndexGenerator it(20 , 3);
    //  return Tools::int2str( it.indexes[0]->value);
    unsigned int to_generate = 5;
    vector<vector<int>> inds = it.generate(to_generate);

    for (std::vector<vector<int>>::iterator it = inds.begin(); it!=inds.end(); ++it)
    {
        for (std::vector<int>::iterator jt = (*it).begin(); jt!=(*it).end(); ++jt)
        {
            //cout << *jt << " ";
        }
        //cout << endl;
    }

    return (inds.size() == to_generate)? "SetsIndexGenerator: OK !" : "SetsIndexGenerator: Fail :/";
}
