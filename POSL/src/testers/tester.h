#pragma once

#include "../benchmarks/golfers.h"
#include  "../benchmarks/squaring_square.h"
#include  "../benchmarks/golomb_ruler.h"
#include "../benchmarks/n_queens.h"
#include "../solver/psp.h"
#include "../computation/flag_computation.h"
#include "../data/seed.h"

#include <iostream>
#include <string>

using namespace std;

//enum Computation {SEQ, PAR};

class Tester
{
    public:
        Tester(int argc, char *argv[]);
        virtual string test() = 0;        

        int ARGC;
        char **ARGV;

        std::shared_ptr<Seed> t_seed;

        static vector<int> Golfers_332_c6();
        static vector<int> Golfers_442_c0();
        static vector<int> Golfers_442_c4();
        static vector<int> Golfers_442_1s();
        static vector<int> Golfers_442_0s();
        static vector<int> Golfers_442_mal();
        static vector<int> Golfers_444_c();
        static vector<int> Golfers_553_c0();
        static vector<int> Golfers_554_c0();
        static vector<int> Golfers_553_c1();
        static vector<int> Golfers_662_c0();

        static vector<int> Golomb_6_17_c2();
        static vector<int> Golomb_7_25_c4();
        static vector<int> Golomb_8_34_c7();
        static vector<int> Golomb_9_44_c9();
        static vector<int> Golomb_10_55_c11();
        static vector<int> Golomb_11_72_c19();
        static vector<int> Golomb_12_85_c19();
};
