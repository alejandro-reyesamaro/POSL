#include "tester.h"
#include "data/solution.h"
#include "data/domain.h"
#include "data/dStrategy/factory_n_int_domain.h"
#include "benchmarks/benchmark.h"
#include "benchmarks/golfers.h"

Tester::Tester(int argc, char *argv[])
{
    FactoryDomain * fd_integers = new Factory_NIntDomain(1,16);
    Domain D(fd_integers);
    vector<Domain> domains (32,D);
    Solution * sol = new Solution(domains);    
    Benchmark * bench = new Golfers(4,4,2);
    bench->UpdateSolution(sol);
    psp = new PSP(argc, argv, bench);
}
