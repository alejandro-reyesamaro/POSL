#include "singleton_expression.h"
#include "../tools/tools.h"
#include "../tools/tokens_definition.h"

using namespace std;

SingletonExpression::SingletonExpression()
    : executed(false)
{}

bool SingletonExpression::evaluate(shared_ptr<PSP>)
{
    if(!executed)
    {
        executed = true;
        return true;
    }
    else return false;
}

string SingletonExpression::codeToSend()
{
    return string(BE_SINGLETON_TOK);
}
