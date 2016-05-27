#pragma once

#include "unary_operator.h"
//#include "strategy/send_data_sequential_strategy.h"

class TabuOperator : public UnaryOperator
{
    public:
        TabuOperator(std::shared_ptr<CompoundModule> _M1);

        //! From Codable
        std::string codeToSend();

        //!From Connectable
        std::vector<ConnectorInfo> Jacks();
        std::vector<ConnectorInfo> Outlets();
        void connect(ConnectorInfo connector, int procID);

    private:
        //std::shared_ptr<SendDataSequentialStrategy> CastMyStrategy();
};
