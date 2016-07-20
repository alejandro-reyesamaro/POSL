#pragma once
#include "tester.h"

class Tester_CodingPOSL : public Tester
{
    public:
        Tester_CodingPOSL(int argc, char *argv[]);
        string test();

    protected:
        int ARGC;
        char **ARGV;
};
