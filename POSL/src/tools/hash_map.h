#pragma once

#include <unordered_map>

template <typename Tkey, typename Tmap>
class HashMap
{
    public:
        HashMap();

        Tmap mapOf(Tkey key);
        void insert(Tkey key, Tmap map);
        HashMap<Tkey, Tmap> merge(HashMap<Tkey, Tmap> other);

        int Count() { return hash_table.size(); }

    private:
        std::unordered_map<Tkey, Tmap> hash_table;
};
