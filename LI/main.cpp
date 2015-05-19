#include "stdio.h"
#include <iostream>
#include "long_int.h"

using namespace std;

int main(int argc, char *argv[])
{
    LongInt a(2, 64);
    LongInt b(2, 64);
    LongInt c = a | b;
    a.activate(50);
    b.activate(50);
    bool activated = a.Equal(b);
    if(activated)
        cout << "si" << endl;
    cout << c.toString() << endl;
    return 0;
}
