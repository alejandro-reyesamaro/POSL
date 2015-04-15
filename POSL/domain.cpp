#include "domain.h"

Domain::Domain(shared_ptr<FactoryDomain> fd) : D(fd->BuildDomain())
{}

vector<int> Domain::GetValues()
{
    return D;
}
