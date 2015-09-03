#pragma once

/*!
 * \class T_Changes t_changes.h
 * \brief Struct to a pair (positions, values) as a change in a configuration
 */
typedef struct
{
    //! Index in the configuration vector
    vector<int> positions;
    //! New values
    vector<int> new_values;
    //! Number of changes
    int dim;
}T_Changes;
