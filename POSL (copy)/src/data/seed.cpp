#include "seed.h"
#include <chrono>

Seed::Seed()
{
}

double Seed::seed()
{
    return chrono::system_clock::now().time_since_epoch().count();
}

vector<int> Seed::pack()
{
    throw "(POSL Exception) Not implemented (Seed.pack)";
}

int Seed::bodySize()
{
    throw "(POSL Exception) Not implemented (Seed.bodySize)";
}

vector<int> Seed::body()
{
    throw "(POSL Exception) Not implemented (Seed.body)";
}
