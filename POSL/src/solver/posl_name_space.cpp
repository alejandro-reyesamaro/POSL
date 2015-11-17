#include "posl_name_space.h"

using namespace std;

POSL_NameSpace::POSL_NameSpace()
    : id_counter(2013),
      hash_table(make_shared<HashMap<string, int>>())
{}

void POSL_NameSpace::newName(string name)
{
    hash_table->insert(name, id_counter++);
}

int POSL_NameSpace::getID(string name)
{
    return hash_table->mapOf(name);
}
