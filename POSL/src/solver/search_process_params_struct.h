#pragma once

#include <string>

class SearchProcessParamsStruct
{
    friend class PSP;
    public:
        SearchProcessParamsStruct();
        SearchProcessParamsStruct(int _pID,
                                  std::string _logs_path,
                                  int _tabu_list_size,
                                  int _tabu_norm_type,
                                  float _tabu_eps,
                                  int _max_time_miliseconds);

        int GetpID() { return pID; }
        std::string GetpLogPath() { return logs_path; }
        float GetTabuEps() { return tabu_eps; }
        int GetpTabuNormType() { return tabu_norm_type; }
        int GetpTabuListSize() { return tabu_list_size; }

        void SetID(int _pID) { pID = _pID; }
        void SetLogPath(std::string _log_path) { logs_path = _log_path; }
        void SetTabuEps(float _tabu_eps) { tabu_eps = _tabu_eps; }
        void SetTabuNormType(int _tabu_norm_type) { tabu_norm_type = _tabu_norm_type; }
        void SetTabuListSize(int _tabu_list_size) { tabu_list_size = _tabu_list_size; }

    private:
        int pID;
        std::string logs_path;
        int tabu_list_size;
        int tabu_norm_type;
        float tabu_eps;
        int max_time_miliseconds;
};
