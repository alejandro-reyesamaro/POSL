#pragma once

#include "solver/psp.h"

#include <iostream>
#include <string>

using namespace std;

class Tester
{
    public:
        Tester(int argc, char *argv[]);
        virtual string test() = 0;
    protected:
        PSP * psp;
};
