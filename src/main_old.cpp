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
#include "../tools/tools.h"
#include "../solver/posl_meta_solver.h"

#include "mpi.h"

using namespace std;

int main(int argc, char *argv[])
{
	/*
	    if (argc < 5) { // Check the value of argc. If not enough parameters have been passed, inform user and exit.
		std::cout << "Usage is -in <infile> -out <outdir>\n"; // Inform the user of how to use the program
		std::cin.get();
		exit(0);
	    } else { // if we got enough parameters...
	*/
        int p = Tools::str2int(argv[1]);
        int g = Tools::str2int(argv[2]);
        int w = Tools::str2int(argv[3]);
	int opt = Tools::str2int(argv[4]);
        //std::cout << argv[0];
/*
        for (int i = 1; i < argc; i++) { 
            if (i + 1 != argc) // Check that we haven't finished parsing already
                if (argv[i] == "-p") {
                    // We know the next argument *should* be the ...
                    p = Tools::str2int(argv[++i]);
                } else if (argv[i] == "-g") {
                    g = Tools::str2int(argv[++i]);
                } else if (argv[i] == "-w") {
                    w = Tools::str2int(argv[++i]);
                } else {
                    //cout << "Not enough or invalid arguments, please try again.\n";                    
                    //exit(0);
            	}
            cout << argv[i] << (argv[i] == "-p") << endl;
        }
    	//}
*/

	//cout << p << g << w << endl; 
	//exit(0);
	

	vector<shared_ptr<POSL_Solver>> solvers;

	/* GOLFERS */
	shared_ptr<Golfers> gol(make_shared<Golfers>(p,g,w));
	shared_ptr<Benchmark> bench = gol;
	shared_ptr<CreateSolverStrategy> css(make_shared<ForGolfersCSS>(gol));
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
	    s->solve(argc, argv, bench, opt);
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
