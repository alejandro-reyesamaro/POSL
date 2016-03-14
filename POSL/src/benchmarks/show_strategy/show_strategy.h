#pragma once

#include <memory>
#include <string>
#include "../../data/solution.h"

class ShowStrategy
{
    public:
        virtual std::string showSolution(std::shared_ptr<Solution> & solution) = 0;
};

