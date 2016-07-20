#pragma once

#include "tester.h"

class Tester_ASRestart : public Tester
{
    public:
        Tester_ASRestart(int argc, char *argv[]);
        string test();
};
