#pragma once
#include "tester.h"

class Tester_Comunication
{
    public:
        Tester_Comunication(int argc, char *argv[]);
        void test();

    protected:
        int ARGC;
        char **ARGV;
};
