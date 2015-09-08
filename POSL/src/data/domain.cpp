#include "domain.h"

#include <algorithm>

Domain::Domain(shared_ptr<FactoryDomain> fd) : D(fd->BuildDomain())
{}

vector<int> Domain::GetValues(){ return D; }

int Domain::minimum(){ return *min_element(D.begin(), D.end()); }

int Domain::maximum(){ return *max_element(D.begin(), D.end()); }
