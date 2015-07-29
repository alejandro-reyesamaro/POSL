#pragma once

#include "../benchmarks/golfers.h"
#include  "../benchmarks/squaring_square.h"
#include  "../benchmarks/golomb_ruler.h"
#include "../solver/psp.h"

#include <iostream>
#include <string>

using namespace std;

enum Computation {SEQ, PAR};

class Tester
{
    public:
        Tester(int argc, char *argv[]);
        virtual string test() = 0;

    protected:
        int ARGC;
        char **ARGV;
};
