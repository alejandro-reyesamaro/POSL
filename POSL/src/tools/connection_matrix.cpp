#include "connection_matrix.h"

using namespace std;

vector<vector<int>> buildConnectios(int n)
{
    vector<vector<int>> connections;
    for(int i = 1; i <= n ; i++)
         connections.push_back(vector<int>(i,0));
    return connections;
}

ConnectionMatrix::ConnectionMatrix(int n)
    : connections(buildConnectios(n))
{
}

int ConnectionMatrix::add_connection(int a, int b, bool updating)
{
    if(a == b) return 0;
    int pa = max(a, b)-1;
    int pb = min(a, b)-1;
    if(updating)
    {
        connections[pa][pb]++;
        // RETURNS cost modification factor
        return (connections[pa][pb] > 1) ? 2 : 0;
    }
    else
        return (connections[pa][pb] + 1 > 1) ? 2 : 0;
}

int ConnectionMatrix::remove_connection(int a, int b, bool updating)
{
    if(a == b) return 0;
    int pa = max(a, b)-1;
    int pb = min(a, b)-1;
    if (updating)
    {
        connections[pa][pb] = max(0, connections[pa][pb]-1);
        // RETURNS cost modification factor
        return (connections[pa][pb] > 0) ? -2 : 0;
    }
    else
        return (connections[pa][pb] - 1 > 0) ? -2 : 0;
}

int ConnectionMatrix::get_connectios(int a, int b)
{
    if(a == b) return 0;
    int pa = max(a, b)-1;
    int pb = min(a, b)-1;
    return connections[pa][pb];
}

int ConnectionMatrix::projected_cost(int a, int b)
{
    if(a == b) return 0;
    int pa = max(a, b)-1;
    int pb = min(a, b)-1;
    return (connections[pa][pb] < 2)
            ? 0
            : (connections[pa][pb] - 1) * 2;
}

void ConnectionMatrix::clear()
{
    for(int i = 0; i < connections.size() ; i++)
         fill(connections[i].begin(), connections[i].end(), 0);
}
