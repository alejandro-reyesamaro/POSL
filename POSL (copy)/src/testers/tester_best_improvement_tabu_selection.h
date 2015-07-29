#pragma once
#include "tester.h"

class Tester_BestImprovementTabuSelection : public Tester
{
    public:
        Tester_BestImprovementTabuSelection(int argc, char *argv[]);
        string test();
};
