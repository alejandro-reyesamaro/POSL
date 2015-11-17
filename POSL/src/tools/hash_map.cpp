#include "hash_map.h"

using namespace std;

template<typename Tkey, typename Tmap>
HashMap<Tkey, Tmap>::HashMap()
{}

template<typename Tkey, typename Tmap>
Tmap HashMap<Tkey, Tmap>::mapOf(Tkey key)
{
    //unordered_map<Tkey,Tmap>::const_iterator it_find = hash_table.find (key);
    //return ( it_find == hash_table.end() )? nullptr : hash_table.at(key);
    return hash_table.at(key);
}

template<typename Tkey, typename Tmap>
void HashMap<Tkey, Tmap>::insert(Tkey key, Tmap map)
{
    typename unordered_map<Tkey, Tmap>::const_iterator it_find = hash_table.find(key);
    if ( it_find == hash_table.end() )
        hash_table.insert({key, map});
    else
        it_find->second = map;
}

template<typename Tkey, typename Tmap>
HashMap<Tkey, Tmap> HashMap<Tkey, Tmap>::merge(HashMap<Tkey, Tmap> other)
{
    HashMap<Tkey, Tmap> table;
    for ( auto it = hash_table.begin(); it != hash_table.end(); ++it )
        table.insert(it->first, it->second);
    for ( auto it = other.hash_table.begin(); it != other.hash_table.end(); ++it )
        table.insert(it->first, it->second);
    return (table.Count() == 0) ? nullptr : table;
}

/*
// No need to call this TemporaryFunction() function,
// it's just to avoid link error.
void TemporaryFunction ()
{
    HashMap<string, int> TempObj; // :/
}
*/
