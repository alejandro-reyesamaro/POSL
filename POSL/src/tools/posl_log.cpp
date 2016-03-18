#include "posl_log.h"
#include "tools.h"

#include <ctime>
#include <iostream>

using namespace std;

string get_path(int id, string path)
{
    // current date/time based on current system
    time_t now = time(0);
    //cout << "Number of sec since January 1,1970:" << now << endl;
    tm * ltm = localtime(&now);

    // print various components of tm structure.
    //cout << "Year: "<< 1900 + ltm->tm_year << endl;
    string Month = Tools::int2str(1 + ltm->tm_mon);
    string Day = Tools::int2str(ltm->tm_mday);
    return path + "/POSL_LOG_from" + Tools::int2str(id) + "[" + Month + "-" + Day + "]"; //"-" + Time + "]";
}

POSL_Log::POSL_Log(int pid, string path)
    : path(get_path(pid, path))
{
    time_t now = time(0);
    tm * ltm = localtime(&now);
    string Time = Tools::int2str(ltm->tm_hour) + ":" + Tools::int2str(1 + ltm->tm_min);// + ":" + Tools::int2str(1 + ltm->tm_sec);
    //log("\nBegin at " + Time + "\n--");
}

void POSL_Log::log(std::string text)
{
    outfile.open (path,  ios::out | ios::app);
    outfile << text << endl;
    outfile.close();
}

