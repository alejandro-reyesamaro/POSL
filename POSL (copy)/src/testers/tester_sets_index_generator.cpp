#include "tester_sets_index_generator.h"
#include "../tools/rand_index_generator.h"
#include "../tools/tools.h"

Tester_SetsIndexGenerator::Tester_SetsIndexGenerator(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_SetsIndexGenerator::test()
{
    Benchmark * bench = new Golfers(4,4,2);
    Solution * sol = new Solution(bench->Domains());
    bench->UpdateSolution(sol);
    PSP * psp = new PSP(ARGC, ARGV, bench);

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
