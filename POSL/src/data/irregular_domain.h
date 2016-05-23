#pragma once

#include "domain.h"

class IrregularDomain : public Domain
{
    public:
        IrregularDomain(std::vector<int> _min_values, std::vector<int> _max_values);
        std::vector<int> GetValues(int variable);
        int minimum(int variable);
        int maximum(int variable);

    private:
        std::vector<int> min_values;
        std::vector<int> max_values;
};
