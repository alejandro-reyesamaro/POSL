#pragma once

#include <memory>

template <typename T>
class BinarySearchTree
{
    public:
        BinarySearchTree(T _value, int _cost)
            : left_sons(0),
              right_sons(0),
              value(_value),
              cost(_cost)
        {}

        //int LeftSons() { return left_sons; }
        //int RightSons() { return right_sons; }

        void insert(T _value, int _cost)
        {
            if(_cost <= cost)
            {
                if (left)
                    left->insert(_value, _cost);
                else left = std::make_shared<BinarySearchTree<T>>(_value, _cost);
                left_sons++;
            }
            else
            {
                if (right)
                    right->insert(_value, _cost);
                else right =std::make_shared<BinarySearchTree<T>>(_value, _cost);
                right_sons++;
            }
        }

        bool exist_cost(int _cost)
        {
            if (cost == _cost) return true;
            if (_cost < cost && left_sons > 0)
                return left->exist_cost(_cost);
            else if (_cost > cost && right_sons > 0)
                return right->exist_cost(_cost);
            else
                return false;
        }

        T get_value_in_position(int pos)
        {
            int max = 1 + left_sons + right_sons;
            if (pos > max) pos = max;
            return get(pos, 0);
        }

    private:

        T get(int pos, int k)
        {
            int mark = k + left_sons + 1;
            if (mark > pos)
                return left->get(pos, k);
            else if(mark < pos)
                return right->get(pos, mark);
            else /* here I am */
                return value;
        }

        int left_sons, right_sons;
        T value;
        int cost;
        std::shared_ptr<BinarySearchTree<T>> left;
        std::shared_ptr<BinarySearchTree<T>> right;
};

