#include "florian_operator.h"
#include "strategy/florian_sequential_strategy.h"

#include <iostream>
using namespace std;

FlorianOperator::FlorianOperator(CompoundModule * _M1)
    : UnaryOperator(_M1, new FlorianSequentialStrategy(_M1))
{}

string FlorianOperator::codeToSend()
{
    return "7 " + M1 ->codeToSend();
}
