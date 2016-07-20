#pragma once
#include "tester.h"

class Tester_BinarySearchTree : public Tester
{
    public:
        Tester_BinarySearchTree(int argc, char *argv[]);
        string test();

    protected:
        int ARGC;
        char **ARGV;
};
