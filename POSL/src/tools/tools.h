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
#include <boost/algorithm/string.hpp>

using namespace boost;
using namespace std;

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
        static string int2str(int c);
        static string float2str(float f);
        static int str2int(string str);
        static float str2float(string str);
        static string configurationToString(vector<int> config);
        static string frontModule(string code);
        static int segmentIntersection(int a1, int b1, int a2, int b2);
        static vector<int> vector_possible_values_to_hold_sorted(int index, vector<int> current_configuration);
        static int mismatches(vector<int> vector_1, vector<int> vector_2);
        static int * vector2array(vector<int> vec);
        static void shuffle(vector<int> & vec);
        static vector<int> generateMonotony(int N);
};
