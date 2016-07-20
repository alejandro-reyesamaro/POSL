#pragma once

#include "binary_operator.h"

class NotNullOperator : public BinaryOperator
{
    public:
        NotNullOperator(std::shared_ptr<CompoundModule> _M1, std::shared_ptr<CompoundModule> _M2);

        //! From Codable
        std::string codeToSend();
};
