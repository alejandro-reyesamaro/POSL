#pragma once

#include "compound_module.h"
#include "../operators/operator.h"
#include "../expressions/boolean_expression.h"
#include "../packing/module_uncoder.h"

class CompoundModuleGeneratorFromCode : public CompoundModule
{
    public:
        CompoundModuleGeneratorFromCode(std::string code, std::shared_ptr<Benchmark> bench);

        std::shared_ptr<ComputationData> execute(std::shared_ptr<PSP> psp, std::shared_ptr<ComputationData> input);

        virtual std::string Tag() { return "cm_FromCode"; }

        //! From Codable
        std::string codeToSend();

        //! From Connectable
        std::vector<ConnectorInfo> Jacks() { return module->Jacks(); }
        std::vector<ConnectorInfo> Outlets() { return module->Outlets(); }
        void connect(ConnectorInfo connector, int procID) { module->connect(connector, procID); }

    private:
        std::shared_ptr<CompoundModule> generateFrom(std::string code, std::shared_ptr<Benchmark> bench);

        std::shared_ptr<ModuleUncoder> m_uncoder;
        std::shared_ptr<CompoundModule> module;
        std::string mycode;
};
