#pragma once

#include "domain.h"

class UniformDomain : public Domain
{
    public:
        UniformDomain(int _min_value, int _max_value);
        std::vector<int> GetValues(int variable);
        int minimum(int);
        int maximum(int);

    private:
        int min_value, max_value;
};

