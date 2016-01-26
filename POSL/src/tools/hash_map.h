#pragma once

#include <unordered_map>

template <typename Tkey, typename Tmap>
class HashMap
{
    public:
        HashMap(){}

        bool existsKey(Tkey key)
        {
            typename std::unordered_map<Tkey,Tmap>::const_iterator it_find = hash_table.find(key);
            return ( it_find != hash_table.end() );
        }

        Tmap mapOf(Tkey key)
        {
            //unordered_map<Tkey,Tmap>::const_iterator it_find = hash_table.find (key);
            //return ( it_find == hash_table.end() )? nullptr : hash_table.at(key);
            return hash_table.at(key);
        }

        void insert_or_replace(Tkey key, Tmap map)
        {
            typename std::unordered_map<Tkey, Tmap>::const_iterator it_find = hash_table.find(key);
            if ( it_find != hash_table.end() )
                hash_table.erase(key);
            hash_table.insert({key, map});
        }        

        HashMap<Tkey, Tmap> merge(HashMap<Tkey, Tmap> other)
        {
            HashMap<Tkey, Tmap> table;            
            for ( auto it = hash_table.begin(); it != hash_table.end(); ++it )
                table.insert(it->first, it->second);
            for ( auto it = other.hash_table.begin(); it != other.hash_table.end(); ++it )
                table.insert(it->first, it->second);
            return (table.Count() == 0) ? nullptr : table;
        }

        typename std::unordered_map<Tkey, Tmap>::iterator it_begin()
        {
            return hash_table.begin();
        }

        typename std::unordered_map<Tkey, Tmap>::iterator it_end()
        {
            return hash_table.end();
        }

        int Count() { return hash_table.size(); }

    private:
        std::unordered_map<Tkey, Tmap> hash_table;
};
