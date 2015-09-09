#include "domain.h"

#include <algorithm>

Domain::Domain(std::shared_ptr<FactoryDomain> fd) : D(fd->BuildDomain())
{}

std::vector<int> Domain::GetValues(){ return D; }

int Domain::minimum(){ return *min_element(D.begin(), D.end()); }

int Domain::maximum(){ return *max_element(D.begin(), D.end()); }
