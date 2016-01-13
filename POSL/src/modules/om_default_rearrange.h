#pragma once

#include "aom_rearrange_configuration.h"

class OM_DefaultRearrange : public AOM_RearrangeConfiguration
{
    public:
        OM_DefaultRearrange();

        std::shared_ptr<Solution> spcf_execute(std::shared_ptr<PSP>, std::shared_ptr<Solution>);

        //! From Codable
        std::string codeToSend();

        virtual std::string Tag();

    private:
          std::vector<int> config;
};
