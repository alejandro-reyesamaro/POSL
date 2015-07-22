#include "matrix.h"

Matrix::Matrix(int n, int m) : A(n, vector<int>(m)), N(n), M(m)
{}

Matrix::Matrix(int n) : Matrix(n, n)
{}

int Matrix::elementAt(int n, int m)
{
    return A[n][m];
}

void Matrix::setValue(int row, int column, int value)
{
    A[row][column] = value;
}

vector<int> Matrix::row(int index)
{
    return A[index];
}

vector<int> Matrix::column(int index)
{
    vector<int> col;
    if(index >= M) return col;

    for(int i = 0; i < N; i++)
        col.push_back(elementAt(i,index));

    return col;
}

vector<int> Matrix::diagonalRigth(int shift)
{
    vector<int> diag;
    shift = shift % N;
    for(int i = 0; i < N; i++)
        diag.push_back(elementAt( N-(i+1), (i + (shift))%N ) );

    return diag;
}

vector<int> Matrix::diagonalLeft(int shift)
{
    vector<int> diag;
    shift = shift % N;
    for(int i = 0; i < N; i++)
        diag.push_back(elementAt( i, (i + (shift))%N ) );

    return diag;
}
