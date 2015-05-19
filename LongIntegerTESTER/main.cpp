#include "stdio.h"
#include <iostream>
#include "../LongInteger/long_int.h"

using namespace std;

int main(int argc, char *argv[])
{
    LongInt a(3);
    LongInt b(2, 64);
    LongInt c = a | b;
    a.activate(50);
    b.activate(50);
    bool activated = a.Equal(b);
    if(activated)
        cout << "si" << endl;
    c.deactivateAll();
    cout << c.toString() << endl;
    cout << c.bitCount() << endl;
    return 0;
}

