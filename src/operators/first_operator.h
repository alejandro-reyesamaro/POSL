#pragma once

#include "binary_operator.h"

class FirstOperator : public BinaryOperator
{
    public:
        FirstOperator(std::shared_ptr<CompoundModule> _M1, std::shared_ptr<CompoundModule> _M2);

        //! From Codable
        std::string codeToSend();
};
