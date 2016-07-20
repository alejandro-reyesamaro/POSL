#pragma once

#include "aom_process_configuration.h"

class OM_TabuConfigurationProcessing : public AOM_ProcessConfiguration
{
    public:
        OM_TabuConfigurationProcessing();

        std::shared_ptr<Solution> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<Solution> input);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    //private:
    //      std::vector<int> config;
};
