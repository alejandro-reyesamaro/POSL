#pragma once

/**
 * POSL
 *
 * \file golomb_measures_struct.h
 * \brief Struct to represent the information about meausures in Golomb Ruler Problem
 * \author Alejandro Reyes
 * \date 2016-05-31
 */

#include <vector>
#include <list>

/*!
 * \class GolombMeasuresStruct golomb_measures_struct.h
 * \brief Struct to represent the information about meausures in Golomb Ruler Problem
 */
class GolombMeasuresStruct
{
    public:
        //! Default constructor.
        /*!
            \param size Problem order: number of marks.
         */
        GolombMeasuresStruct(int size);

        //! Clears all the measures lists.
        void clear();

        //! Adds a measure of a variable.
        /*!
            \param variable_index Index of the variable.
            \param distance Distance to add.
         */
        void addVariableDistance(int variable_index, int distance);

        //! Removes a measure of a variable.
        /*!
            \param variable_index Index of the variable.
            \param distance Distance to remove.
         */
        void removeDistanceFromVariable(int variable_index, int distance);

        //! Returns the number of measures of a variable.
        /*!
            \param variable_index Index of the variable.
            \return The number of measures.
         */
        int measuresOfVariable(int variable_index);

    private:
        //! A counter of the measures for each variable
        std::vector<std::list<int>> measures;
        //! An auxiliar container for the measures of a variable
        std::list<int> aux_measures;
};

