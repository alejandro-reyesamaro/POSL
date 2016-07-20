#pragma once

#include "tester.h"

class Tester_UnionOperator : public Tester
{
    public:
        Tester_UnionOperator(int argc, char *argv[]);
        string test();
        string testeInMode(Computation comp);
};
