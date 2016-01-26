#pragma once

#include "tester.h"

class Tester_KBestImprovementSelection : public Tester
{
    public:
        Tester_KBestImprovementSelection(int argc, char *argv[]);
        string test();
};
