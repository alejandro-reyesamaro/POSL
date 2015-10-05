#pragma once

#include <vector>

class ConnectionMatrix
{
    public:
        ConnectionMatrix(int n);
        int add_connection(int a, int b, bool updating);
        int remove_connection(int a, int b, bool updating);
        int get_connectios(int a, int b);
        int projected_cost(int a, int b);
        void clear();

    private:
        std::vector<std::vector<int>> connections;
};
