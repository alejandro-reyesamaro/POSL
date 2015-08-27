#pragma once

#include "tester.h"

class Tester_Solver_GolombRuler : public Tester
{
    public:
        Tester_Solver_GolombRuler(int argc, char *argv[]);
        string test();
};
