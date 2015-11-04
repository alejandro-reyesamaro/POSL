#include "posl_tag.h"

using namespace std;

POSL_Tag::POSL_Tag(string _tag)
    : tag(_tag)
{}

POSL_Tag::POSL_Tag(string _tag, shared_ptr<POSL_Tag> _next)
    : tag(_tag), next(_next)
{}

void POSL_Tag::addTag(shared_ptr<POSL_Tag> _next)
{
    next = _next;
}

string POSL_Tag::GetTag()
{
    if(next)
        return tag + next->GetTag();
    else return tag;
}
