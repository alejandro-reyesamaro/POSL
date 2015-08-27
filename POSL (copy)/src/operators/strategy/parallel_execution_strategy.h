#pragma once

/**
 * POSL
 *
 * \file parallel_execution_strategy.h
 * \brief (Abstract) Class to represent a strategy of computation in parallel
 * \author Alejandro Reyes
 * \date 2015-05-28
 */

#include "execution_strategy.h"
#include "../../solver/psp.h"

/*!
 * \class ParallelExecutionStrategy parallel_execution_strategy.h
 * \brief (Abstract) Class to represent a strategy of computation in parallel
 */
class ParallelExecutionStrategy : public ExecutionStrategy
{};
