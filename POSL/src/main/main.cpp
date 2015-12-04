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
    int p = Tools::str2int(argv[1]);    
    int g = Tools::str2int(argv[2]);
    int w = Tools::str2int(argv[3]);
	string path = argv[4];
	//cout << path << endl;
    
    /* GOLFERS */
	shared_ptr<Golfers> gol(make_shared<Golfers>(p,g,w));
	shared_ptr<Benchmark> bench = gol;
	//shared_ptr<CreateSolverStrategy> css(make_shared<ForGolfersCSS>(gol));
	//solvers = css->create();

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
	
	int comm_size;
	MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD,&comm_size);

	try
	{
	    shared_ptr<POSL_MetaSolver> s(make_shared<POSL_MetaSolver>(path, comm_size, bench));
	    s->solve(argc, argv);
	}catch (const char* msg)
	{
	    cout << msg << endl;
	}

    MPI_Finalize();
}

/*
mpiexec.mpich -np 8 ./bin_par/POSL 4 4 2 /home/reyesamaro-a/Documents/POSL/POSL_Code4Testing/POSL_a000.posl
*/