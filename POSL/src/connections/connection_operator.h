#pragma once

#include "scheduler.h"

class ConnectionOperator
{
    public:
        virtual void connect(std::shared_ptr<Scheduler> scheduler) = 0;
};

