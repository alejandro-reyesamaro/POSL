#include "tester.h"
#include "../data/solution.h"
#include "../data/domain.h"
#include "../data/dStrategy/factory_n_int_domain.h"
#include "../benchmarks/benchmark.h"

Tester::Tester(int argc, char *argv[])
    :ARGC(argc), ARGV(argv)
{}

vector<int> Tester::Golfers_442_c0()
{
    vector<int> config(
    {
        1,  2,   3,  4,
        5,  6,   7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16,

        13, 10,  7,  4,
        14, 11,  8,  1,
        15, 12,  2,  5,
        16,  3,  6,  9
    });
    return config;
}

vector<int> Tester::Golfers_442_c4()
{
    vector<int> config(
    {
        1,  2,   3,  4,
        5,  6,   7,  8,
        9,  10, 11, 12,
        13, 14, 15, 16,

        13, 10,  7,  8,
        14, 11,  4,  1,
        15, 12,  2,  5,
        16,  3,  6,  9
    });
    return config;
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
    vector<int> config(
    {
        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,

        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,
        1,  1,  1,  1,
    });
    return config;
}

vector<int> Tester::Golfers_442_0s()
{
    vector<int> config(
    {
        0,  0,  0,  0,
        0,  0,  0,  0,
        0,  0,  0,  0,
        0,  0,  0,  0,

        0,  0,  0,  0,
        0,  0,  0,  0,
        0,  0,  0,  0,
        0,  0,  0,  0
    });
    return config;
}

vector<int> Tester::Golfers_553_c0()
{
    vector<int> config(
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
    });
    return config;
}

vector<int> Tester::Golfers_553_c1()
{
    vector<int> config(
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
    });
    return config;
}

vector<int> Tester::Golomb_6_17_c2()
{
    vector<int> config({0, 1, 4, 10, 12, 17}); // costo 2
    return config;
}

vector<int> Tester::Golomb_7_25_c4()
{
    vector<int> config({0, 1, 4, 10, 18, 23, 25}); // costo 4
    return config;
}

vector<int> Tester::Golomb_8_34_c7()
{
    vector<int> config({0, 1, 4, 9, 15, 22, 32, 34}); // costo 7
    return config;
}

vector<int> Tester::Golomb_9_44_c9()
{
    vector<int> config({0, 1, 5, 12, 25, 27, 35, 41, 44}); // costo 9
    return config;
}

vector<int> Tester::Golomb_10_55_c11()
{
    vector<int> config({0, 1, 6, 10, 23, 26, 34, 41, 53, 55}); // costo 11
    return config;
}

vector<int> Tester::Golomb_11_72_c19()
{
    vector<int> config({0, 1, 4, 13, 28, 33, 47, 54, 64, 70, 72}); // costo 19
    return config;
}

vector<int> Tester::Golomb_12_85_c19()
{
    vector<int> config({0, 2, 6, 24, 29, 40, 43, 55, 68, 75, 76, 85}); // costo 20
    return config;
}
