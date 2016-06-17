#include "search_process_params_struct.h"

#define EXIT_TIME 300000
#define TABU_SIZE 15
#define TABU_EPS 7

using namespace std;

SearchProcessParamsStruct::SearchProcessParamsStruct()
    : SearchProcessParamsStruct(-1, "./logs", TABU_SIZE, 2, TABU_EPS, EXIT_TIME)
{}

SearchProcessParamsStruct::SearchProcessParamsStruct(int _pID,
                                                     std::string _logs_path,
                                                     int _tabu_list_size,
                                                     int _tabu_norm_type,
                                                     float _tabu_eps,
                                                     int _max_time_miliseconds)
    : pID(_pID),
      logs_path(_logs_path),
      tabu_list_size(_tabu_list_size),
      tabu_norm_type(_tabu_norm_type),
      tabu_eps(_tabu_eps),
      max_time_miliseconds(_max_time_miliseconds)
{}
