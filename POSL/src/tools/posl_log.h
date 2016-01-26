#pragma once

#include <string>
#include <fstream>

class POSL_Log
{
    public:
        POSL_Log(int pid, std::string path);

        void log(std::string text);

    private:
        std::string path;
        std::ofstream outfile;

};

