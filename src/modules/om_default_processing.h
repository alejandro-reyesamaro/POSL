#pragma once

#include "aom_process_configuration.h"

class OM_DefaultProcessing : public AOM_ProcessConfiguration
{
    public:
        OM_DefaultProcessing();

        std::shared_ptr<Solution> spcf_execute(std::shared_ptr<PSP>, std::shared_ptr<Solution>);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();
};
