#pragma once

#include <ctime>

using namespace std;

class Chronometer
{
    public:
        Chronometer();
        void start();
        int TimeMiliseconds();
        int TimeSeconds();
        void stop();
        void reset();
        bool isRunning();

    private:
        bool running;
        clock_t begin;
        clock_t end;
};
