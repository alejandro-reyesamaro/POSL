#pragma once

/**
 * POSL
 *
 * \file tools.h
 * \brief (Static) Class to represent useful methods
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include <string>
#include <vector>
#include "t_changes.h"

/*!
 * \class Tools tools.h
 * \brief (Static) Class to represent useful methods
 */

class Tools
{
    public:
        //! Convert an integer in a string
        /*!
        * \param c A given integer
        * \return The resulting string
        */
        static std::string int2str(int c);
        static std::string float2str(float f);
        static int str2int(std::string str);
        static float str2float(std::string str);
        static bool isANumber(std::string str);
        static std::string configurationToString(std::vector<int> & config);
        static int segmentIntersection(int a1, int b1, int a2, int b2);
        static int mismatches(std::vector<int> &vector_1, std::vector<int> &vector_2);
        static int * vector2array(std::vector<int> & vec);
        //static void shuffle(std::vector<int> & vec, int seed);
        static std::vector<int> generateMonotony(int N);
        static std::vector<int> generateMonotony(int a, int b);
        static void sortAscendent(std::vector<int> & v);        
        static T_Changes GetChanges(std::vector<int> &config_before, std::vector<int> &config_after);
        static float norm1(std::vector<int> & v1, std::vector<int> & v2);
        static float norm2(std::vector<int> & v1, std::vector<int> & v2);
        static float norm8(std::vector<int> & v1, std::vector<int> & v2);
        static int element_mismatches(std::vector<int> & v1, std::vector<int> & v2, int distance);
        static int element_mismatches(std::vector<int> & v1, std::vector<int> & v2, int end, int distance);

        static int max(std::vector<int> & v);
        static int min(std::vector<int> & v);
        static int sum(std::vector<int> &v);
        static int sum(std::vector<int> & v, int first_k_elements);
        static int zero_bounded_decrease(int x);
        static int identity(int x, int base = 1);
        static int sqr(int b);
        static int sign(int x);
        static bool equals_vectors(std::vector<int> &v1, std::vector<int> &v2);

        static void activateBit(int & integer, int bit);
        static int bitsCount(int integer);

        template<typename T>
        static std::vector<T> concat(std::vector<T> vector1, std::vector<T> vector2)
        {
            int v1size = vector1.size();
            int v2size = vector2.size();
            std::vector<T> vec(v1size + vector2.size());
            if(v1size > 0)
                std::copy(vector1.begin(), vector1.end(), vec.begin());
            if(v2size > 0)
                std::copy(vector2.begin(), vector2.end(), vec.begin() + v1size);
            return vec;
        }        
};
