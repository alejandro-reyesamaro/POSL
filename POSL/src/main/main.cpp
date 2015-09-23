#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <memory>

#include "../solver/for_golfers_css.h"
#include "../solver/for_squaring_square_css.h"
#include "../solver/for_golomb_ruler_css.h"
#include "../testers/tester_comunication.h"

#include "../solver/posl_meta_solver.h"

#include "mpi.h"

using namespace std;

int main(int argc, char **argv)
{

    vector<shared_ptr<POSL_Solver>> solvers;


    /* GOLFERS */
    shared_ptr<Golfers> g(make_shared<Golfers>(5,5,3));
    shared_ptr<Benchmark> bench = g;
    shared_ptr<CreateSolverStrategy> css(make_shared<ForGolfersCSS>(g));
    solvers = css->create();


    /* SQUARING SQUARE
    //vector<int> squares({6, 4, 4, 1, 3, 3, 3});
    //bench = new SquaringSquare(10, squares);
    vector<int> squares({2, 3, 4, 6, 7, 8, 12, 13, 14, 15, 16, 17, 18, 21, 22, 23, 24, 26, 27, 28, 50, 60});
    bench = new SquaringSquare(110, squares);
    CreateSolverStrategy * css = new ForSquaringSquareCSS();
    solvers = css->create();
    */

    /* GOLOMB RULER 
    //bench = new GolombRuler(12,85);
    //bench = new GolombRuler(8,34);
    bench = new GolombRuler(9,44);
    CreateSolverStrategy * css = new ForGolombRulerCSS();
    solvers = css->create();
    */

    try
    {
        shared_ptr<POSL_MetaSolver> s(make_shared<POSL_MetaSolver>(solvers));
        s->solve(argc, argv, bench);
    }catch (const char* msg)
    {
         cout << msg << endl;
    }
}

int mainTest(int argc, char **argv)
{
    try
    {
        Tester_Comunication * s = new Tester_Comunication(argc, argv);
        s->test();
    }catch (const char* msg)
    {
         cout << msg << endl;
    }
}


// PARALLEL
// Compile command line:
// $ make

// Execute command line:
// $ mpiexec.mpich -np 2  ./bin/POSL
