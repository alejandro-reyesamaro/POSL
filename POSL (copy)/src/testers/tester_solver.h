#pragma once

#include "tester.h"

class Tester_Solver : public Tester
{
    public:
        Tester_Solver(int argc, char *argv[]);
        string test();
};
