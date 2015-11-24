#pragma once

#include "../modules/operation_module.h"
#include "../modules/open_channel.h"

class OpenChannelUncoder
{
    public:
        OpenChannelUncoder();
        std::shared_ptr<OpenChannel> uncode(std::string code, std::shared_ptr<Benchmark> bench);
};
