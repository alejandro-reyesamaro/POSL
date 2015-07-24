#pragma once

#include "tester.h"

class Tester_SpeedOperator : public Tester
{
    public:
        Tester_SpeedOperator(int argc, char *argv[]);
        string test();
        string testeInMode(Computation comp);
};
