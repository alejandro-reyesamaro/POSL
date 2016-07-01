#pragma once

#include "aom_process_configuration_set.h"

class OM_TabuConfigurationSetProcessing : public AOM_ProcessConfigurationSet
{
    public:
        OM_TabuConfigurationSetProcessing();

        std::shared_ptr<ConfigurationSet> spcf_execute(std::shared_ptr<PSP> psp, std::shared_ptr<ConfigurationSet>);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    private:
          std::vector<int> config;
          shared_ptr<POSL_Iterator> it;
};
