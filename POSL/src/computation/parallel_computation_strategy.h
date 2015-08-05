#pragma once

/**
 * POSL
 *
 * \file parallel_computation_strategy.h
 * \brief (Abstract) Class to represent a strategy of computation in parallel
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include "computation_strategy.h"
#include "../solver/psp.h"

/*!
 * \class ParallelComputationStrategy parallel_computation_strategy.h
 * \brief (Abstract) Class to represent a strategy of computation in parallel
 */
class ParallelComputationStrategy : public ComputationStrategy
{};
