#pragma once

#include <vector>

class UpperMatrix
{
    public:
        UpperMatrix(int n);
        int getLineSum(int index);
        int elementAt(int a, int b);
        int set(int a, int b, int value);

    private:
        int N;
        std::vector<std::vector<int>> M;

};
