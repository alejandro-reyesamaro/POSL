#include "send_data_operator.h"
#include "strategy/send_data_sequential_strategy.h"

#include <iostream>
using namespace std;

SendDataOperator::SendDataOperator(CompoundModule * _M1)
    : UnaryOperator(_M1, new SendDataSequentialStrategy(_M1))
{}

string SendDataOperator::codeToSend()
{
    return M1 ->codeToSend();
}
