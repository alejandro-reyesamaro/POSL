#include "florian_operator.h"
#include "strategy/florian_sequential_strategy.h"

#include <iostream>
using namespace std;

FlorianOperator::FlorianOperator(shared_ptr<CompoundModule> _M1)
    : UnaryOperator(_M1, make_shared<FlorianSequentialStrategy>(_M1))
{}

string FlorianOperator::codeToSend()
{
    return "7 " + M1 ->codeToSend();
}
