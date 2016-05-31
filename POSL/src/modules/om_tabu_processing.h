#pragma once

#include "aom_process_configuration.h"

class OM_TabuProcessing : public AOM_ProcessConfiguration
{
    public:
        OM_TabuProcessing();

        std::shared_ptr<Solution> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Solution>);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    private:
          std::vector<int> config;
};
