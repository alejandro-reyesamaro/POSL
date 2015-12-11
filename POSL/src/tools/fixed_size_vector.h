#pragma once

#include <vector>

template <typename T>
class FixedSizeVector
{
    public:
        FixedSizeVector(int _max_size)
            : z(_max_size),
              _size(0),
              vec(_max_size)
        {}

        T elementAt(int index)
        {
            if(index >= _size)
                throw "(POSL Exception) index out of bounds (FixedSizeVector::elementAt)";
            return vec[index];
        }

        int size() { return _size; }

        void pushBack(T element)
        {
            if (_size < z)
                vec[_size ++] = element;
        }

        void clear()
        {
            _size = 0;
        }

    private:
        int z;
        int _size;
        std::vector<T> vec;
};
