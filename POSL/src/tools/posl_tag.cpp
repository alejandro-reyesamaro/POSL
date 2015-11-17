#include "posl_tag.h"

using namespace std;

/*
POSL_Tag::POSL_Tag(int _id, int _type_tag, ConnectionType _connection_type)
    : ID(_id),
      type_tag(_type_tag),
      connection_type(_connection_type),
      connection_tag(_id)
{}

bool POSL_Tag::compatible(POSL_Tag & other)
{
    // hembra y macho del mismo tipo de conectores
    return connection_type != other.connection_type && type_tag == other.type_tag;
}

void POSL_Tag::updateTag(int _connection_tag)
{
    if(connection_type == OUTLET)
        throw "(POSL Exception) trying to change OCh Tag (POSL_Tag::updateTag)";
    connection_tag = _connection_tag;
}
*/
