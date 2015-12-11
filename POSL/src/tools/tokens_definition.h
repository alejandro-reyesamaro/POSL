#pragma once

#define OM_S_TOK_TYPE "OM_S"
#define OM_V_TOK_TYPE "OM_V"
#define OM_SS_TOK_TYPE "OM_SS"
#define OM_D_TOK_TYPE "OM_D"
#define OMS_TOK_TYPE "OMS"

#define OM_FIXED_FIRST_CONFIGURATION_TOK "OM_S.Fix"
#define OM_RANDOM_CONFIG_GENERATION_TOK "OM_S.Rand"
#define OM_RANDOM_CONFIG_ORDERED_GENERATION_TOCK "OM_S.OrdRand"
#define OM_RANDOM_CONFIG_PERMUTATION_BY_BLOCKS_TOK "OM_S.PermBlocks"
#define OM_RANDOM_PERMUTATION_GENERATION_TOK "OM_S.PermRand"
#define OM_GOLFERS_SINGLE_SWAP_NEIGHBORHOOD_TOK "OM_V.1SwapBtwnBlocks"
#define OM_MULTI_CHANGES_NEIGHBORHOOD_TOK "OM_V.NChanges"
#define OM_MULTI_SORTED_CHANGES_NEIGHBORHOOD_TOK "OM_V.NChangesOrd"
#define OM_ONE_CHANGE_NEIHBORHOOD_TOK "OM_V.1Change"
#define OM_ONE_PERMUTATION_NEIGHBORHOOD_TOK "OM_V.1Perm"
#define OM_ADAPTIVE_SEARCH_NEIGHBORHOOD_TOK "OM_V.AS"
#define OM_ONE_SORTED_CHANGE_NEIGHBORHOOD_TOK "OM_V.1ChangeOrd"
#define OM_BEST_IMPROVEMENT_SELECTION_TOK "OM_SS.BestImpr"
#define OM_BEST_IMPROVEMENT_TABU_SELECTION_TOK "OM_SS.BestImprTABU"
#define OM_FIRST_IMPROVEMENT_SELECTION_TOK "OM_SS.FirstImpr"
#define OM_RANDOM_SELECTION_TOK "OM_SS.Rand"
#define OM_ALWAYS_IMPROVEMENT_DECISION_TOK "OM_D.AlwImpr"
#define OM_SIMULATED_ANNEALING_DECISION_TOK "OM_D.SA"
#define OMS_ITERATIONS_COUNTER_TOK "OMS.IterCounter"
#define OMS_TIME_COUNTER_TOK "OMS.TimeCounter"

#define OCH_SOLUTION_TOK_NAME "Sol"
#define OCH_NEIGHBORHOOD_TOK_NAME "V"
#define OCH_DECISIONPAIR_TOK_NAME "DP"

#define OCH_TOK "OCh"

#define OCH_SOLUTION_TOK "OCh.Sol"
#define OCH_NEIGHBORHOOD_TOK "OCh.V"
#define OCH_DECISIONPAIR_TOK "OCh.DP"

#define OP_CONDITIONAL_EXECUTION_TOK_NAME "?"
#define OP_SEQUENTIAL_EXECUTION_TOK_NAME "|->"
#define OP_CYCLIC_TOK_NAME "Cyc"
#define OP_PLORIAN_TOK_NAME "Flo"
#define OP_MIN_TOK_NAME "Min"
#define OP_RHO_TOK_NAME "Rho"
#define OP_SEND_DATA_TOK_NAME "OSend"
#define OP_SPEED_TOK_NAME "Speed"
#define OP_UNION_TOK_NAME "U"

#define OP_CONDITIONAL_EXECUTION_TOK "OP.?"
#define OP_SEQUENTIAL_EXECUTION_TOK "OP.|->"
#define OP_CYCLIC_TOK "OP.Cyc"
#define OP_PLORIAN_TOK "OP.Flo"
#define OP_MIN_TOK "OP.Min"
#define OP_RHO_TOK "OP.Rho"
#define OP_SEND_DATA_TOK "OP.OSend"
#define OP_SPEED_TOK "OP.Speed"
#define OP_UNION_TOK "OP.U"

#define BE_AND_TOK_NAME "AND"
#define BE_OR_TOK_NAME "OR"
#define BE_ITERATION_BOUND_TOK_NAME "IterBnd"
#define BE_LOOP_BOUND_TOK_NAME "LoopBnd"
#define BE_REACHED_COST_TOK_NAME "RC"
#define BE_SAME_COST_ITERATIONS_TOK_NAME "SCI"

#define BE_AND_TOK "BE.AND"
#define BE_ITERATION_BOUND_TOK "BE.IterBnd"
#define BE_LOOP_BOUND_TOK "BE.LoopBnd"
#define BE_OR_TOK "BE.OR"
#define BE_REACHED_COST_TOK "BE.RC"
#define BE_SAME_COST_ITERATIONS_TOK "BE.SCI"

#define SEQ_TOK_OPEN "<S>"
#define SEQ_TOK_CLOSE "</S>"
#define PAR_TOK_OPEN "<P>"
#define PAR_TOK_CLOSE "</P>"
#define GROPER_OPEN_TOK_SIZE 3
#define GROPER_CLOSE_TOK_SIZE 4

#define SOLVER_KEYWORD "solver"
#define CS_KEYWORD "cStrategy"
#define CS_OM_KEYWORD "oModule"
#define CS_OCH_KEYWORD "oChannel"

#define CONNECTION_KW "connections"

#define OP_CONNECTION_BC_NAME "#->"
#define OP_CONNECTION_BP_NAME "-->"
#define OP_CONNECTION_RING_NAME "<>"
#define OP_CONNECTION_NC_NAME "n.c"
