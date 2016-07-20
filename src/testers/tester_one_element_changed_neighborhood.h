#pragma once

#include "tester.h"

class Tester_OneElementChangedNeighborhood : public Tester
{
    public:
        Tester_OneElementChangedNeighborhood(int argc, char *argv[]);
        string test();
};
