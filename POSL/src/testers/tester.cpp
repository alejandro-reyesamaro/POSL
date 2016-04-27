#include "tester.h"
#include "../data/solution.h"
#include "../data/domain.h"
#include "../data/dStrategy/factory_n_int_domain.h"
#include "../benchmarks/benchmark.h"

Tester::Tester(int argc, char *argv[])
    : ARGC(argc), ARGV(argv),
      t_seed(make_shared<Seed>())
{}

vector<int> Tester::Golfers_332_c6()
{
    return
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,

        3, 4, 5,
        6, 7, 8,
        9, 1, 2
    };
}

vector<int> Tester::Golfers_333_c()
{
    return
    {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9,

        3, 4, 5,
        6, 7, 8,
        9, 1, 2,

        1, 4, 7,
        2, 5, 8,
        3, 6, 9,
    };
}

vector<int> Tester::Golfers_442_c0()
{
    return
    {
        1,  2,   3,  4,
        5,  6,   7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16,

        13, 10,  7,  4,
        14, 11,  8,  1,
        15, 12,  2,  5,
        16,  3,  6,  9
    };
}

vector<int> Tester::Golfers_442_c14()
{
    return
    {
        1,  2,   3,  4,
        5,  6,   7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16,

         1,  5,   7,  9,
         2, 11,  10,  13,
        15, 12,  16,  14,
         4,  3,   6,  8
    };
}

vector<int> Tester::Golfers_442_repeted()
{
    return
    {
        1,  2,   3,  4,
        5,  6,   7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16,

        1,  2,   3,  4,
        5,  6,   7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16,
    };
}

vector<int> Tester::Golfers_444_c()
{
    return
    {
        1,  2,   3,  4,
        5,  6,   7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16,

        13, 10,  7,  4,
        14, 11,  8,  1,
        15, 12,  2,  5,
        16,  3,  6,  9,

         1,  5,  9,  13,
         2,  6, 10,  14,
         3,  7, 11,  15,
         4,  8, 12,  16,

         1,  6, 11,  13,
         2,  5, 10,  15,
         3,  8,  9,  14,
         4,  7, 12,  16
    };
}

vector<int> Tester::Golfers_442_c4()
{
    return
    {
        1,  2,   3,  4,
        5,  6,   7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16,

        13, 10,  7,  8,
        14, 11,  4,  1,
        15, 12,  2,  5,
        16,  3,  6,  9
    };
}

vector<int> Tester::Golfers_442_mal()
{
    vector<int> config = Golfers_442_c4();
    config[4] = 4;
    config[5] = 4;
    return config;
}

vector<int> Tester::Golfers_442_1s()
{
    return
    {
        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,

        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,
    };
}

vector<int> Tester::Golfers_442_0s()
{
    return
    {
        0,  0,  0,  0,
        0,  0,  0,  0,
        0,  0,  0,  0,
        0,  0,  0,  0,

        0,  0,  0,  0,
        0,  0,  0,  0,
        0,  0,  0,  0,
        0,  0,  0,  0
    };
}

vector<int> Tester::Golfers_553_c0()
{
    return
    {
        1,   2,  3,  4,  5,
        6,   7,  8,  9, 10,
        11, 12, 13, 14, 15,
        16, 17, 18, 19, 20,
        21, 22, 23, 24, 25,

        1, 6, 11, 16, 21,
        2, 7, 12, 17, 22,
        3, 8, 13, 18, 23,
        4, 9, 14, 19, 24,
        5, 10, 15, 20, 25,

        5, 9, 13, 17, 21,
        10, 14, 18, 22, 1,
        15, 19, 23, 6, 2,
        20, 24, 11, 7, 3,
        25, 4, 8, 12, 16
    };
}

vector<int> Tester::Golfers_554_c0()
{
    return
    {
        1,   2,  3,  4,  5,
        6,   7,  8,  9, 10,
        11, 12, 13, 14, 15,
        16, 17, 18, 19, 20,
        21, 22, 23, 24, 25,

        1, 6, 11, 16, 21,
        2, 7, 12, 17, 22,
        3, 8, 13, 18, 23,
        4, 9, 14, 19, 24,
        5, 10, 15, 20, 25,

        5, 9, 13, 17, 21,
        10, 14, 18, 22, 1,
        15, 19, 23, 6, 2,
        20, 24, 11, 7, 3,
        25, 4, 8, 12, 16,

        1,  7,  13, 19, 25,
        6,  12, 18, 24, 5,
        11, 17, 23, 4, 10,
        16, 22, 3, 9, 15,
        2, 8, 14, 20, 21
    };
}

vector<int> Tester::Golfers_553_c1()
{
    return
    {
        1,   2,  3,  4,  5,
        6,   7,  8,  9, 10,
        11, 12, 13, 14, 15,
        16, 17, 18, 19, 20,
        21, 22, 23, 24, 25,

        1, 6, 11, 16, 21,
        2, 7, 12, 17, 22,
        3, 8, 13, 18, 23,
        4, 9, 14, 19, 24,
        5, 10, 15, 20, 25,

        5, 9, 12, 17, 21,
        10, 14, 18, 22, 1,
        15, 19, 23, 6, 2,
        20, 24, 11, 7, 3,
        25, 4, 8, 13, 16
    };
}

vector<int> Tester::Golfers_662_c0()
{
    return
    {
        1,   2,  3,  4,  5, 6,
        7,   8,  9, 10, 11, 12,
        13, 14, 15, 16, 17, 18,
        19, 20, 21, 22, 23, 24,
        25, 26, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36,

         1,  7, 13, 19, 25, 31,
         2,  8, 14, 20, 26, 32,
         3,  9, 15, 21, 27, 33,
         4, 10, 16, 22, 28, 34,
         5, 11, 17, 23, 29, 35,
         6, 12, 18, 24, 30, 36
    };
}

vector<int> Tester::Golomb_6_17_c2(){ return {0, 1, 4, 10, 12, 17}; } // costo 2 - 0
vector<int> Tester::Golomb_7_25_c4(){ return { 0, 1, 4, 10, 18, 23, 25}; } // costo 4 - 0
vector<int> Tester::Golomb_7_25_m3(){ return { 0, 1, 4, 11, 18, 23, 25}; } // m_cost 3
vector<int> Tester::Golomb_8_34_c7(){ return {0, 1, 4, 9, 15, 22, 32, 34}; } // costo 7
vector<int> Tester::Golomb_9_44_c9(){ return {0, 1, 5, 12, 25, 27, 35, 41, 44}; } // costo 9
vector<int> Tester::Golomb_10_55_c11(){ return {0, 1, 6, 10, 23, 26, 34, 41, 53, 55}; } // costo 11
vector<int> Tester::Golomb_11_72_c19(){ return {0, 1, 4, 13, 28, 33, 47, 54, 64, 70, 72}; } // costo 19
vector<int> Tester::Golomb_12_85_c19(){ return {0, 2, 6, 24, 29, 40, 43, 55, 68, 75, 76, 85}; } // costo 20

vector<int> Tester::NQueens_10_c0(){ return {4, 9, 3, 8, 2, 7, 1, 6, 0, 5}; } // costo 0
vector<int> Tester::NQueens_10_c6(){ return {4, 3, 9, 8, 2, 7, 1, 6, 0, 5}; } // costo 6
vector<int> Tester::NQueens_10_c11(){ return {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}; } // costo 11
vector<int> Tester::NQueens_10_c10(){ return {4, 8, 3, 8, 2, 7, 1, 6, 0, 5}; } // costo 10


vector<int> Tester::Costas_6_c0(){ return {4,2,3,6,5,1}; }
vector<int> Tester::Costas_16_c0(){ return {12, 8, 2, 1, 3, 9, 13, 16, 7, 5, 10, 11, 6, 15, 4, 14}; }
vector<int> Tester::Costas_18_c0(){ return {9, 3, 12, 1, 17, 14, 18, 2, 10, 16, 6, 11, 13, 5, 4, 7, 8, 15}; }

