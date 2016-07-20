#include "tester_longint.h"
#include "../tools/long_int.h"

#include <algorithm>

Tester_LongInt::Tester_LongInt(int argc, char *argv[])
    : Tester(argc, argv)
{
}

string Tester_LongInt::test()
{
    LongInt a(2, 64);
    LongInt b(2, 64);
    //LongInt c = a | b;
    a.activate(50);
    b.activate(50);
    bool activated = a.Equal(b);
    bool activated_50 = a.activated(50);

    LongInt d(2, 0);
    for(int i = 0; i <= 33; i++)
        d.activate(i);
    //d.activate(1);
    cout << d.toString() << endl;

    return (activated && activated_50) ?
           "LongInt: OK !" : "LongInt: fail :/";
}
