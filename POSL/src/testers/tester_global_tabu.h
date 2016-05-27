#pragma once

#include "tester.h"

class Tester_GlobalTabu : public Tester
{
    public:
        Tester_GlobalTabu(int argc, char *argv[]);
        string test();
};
