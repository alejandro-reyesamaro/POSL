#include "upper_matrix.h"

using namespace std;

vector<vector<int>> create_matrix(int n)
{
    vector<vector<int>> v_result;
    for(int i = 0; i <= n - 1; i++)
    {
        vector<int> v (n - i, 0);
        v_result.push_back(v);
    }
    return v_result;
}

UpperMatrix::UpperMatrix(int n)
    : N(n),
      M(create_matrix(n))
{}

int UpperMatrix::getLineSum(int index)
{
    if(index < 0 || index >= N)
        throw "(POSL Exception) bad index (UpperMatrix::getLineSum)";
    int sum = 0;
    for(int i = 0; i < N; i++)
        sum += elementAt(i, index);
    return sum;
}

int UpperMatrix::elementAt(int a, int b)
{
    int ia = min(a, b);
    int ib = max(a, b);
    return M[ia][ib-ia];
}

void UpperMatrix::set(int a, int b, int value)
{
    int ia = min(a, b);
    int ib = max(a, b);
    M[ia][ib-ia] = value;
}
