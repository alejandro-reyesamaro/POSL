#pragma once

#include <vector>

using namespace std;

class Matrix
{
    public:
        Matrix(int n, int m);
        Matrix(int n);
        int elementAt(int n, int m);
        void setValue(int row, int column, int value);

        vector<int> row(int index);
        vector<int> column(int index);
        vector<int> diagonalRigth(int shift);
        vector<int> diagonalLeft(int shift);

    private:
        vector<vector<int>> A;
        int N, M;
};
