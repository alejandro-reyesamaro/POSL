#include "chronometer.h"

Chronometer::Chronometer() : running(false), begin(clock()), end(clock())
{}

void Chronometer::start()
{
    running = true;
    begin = clock();
}

int Chronometer::TimeMiliseconds()
{
    clock_t _end = (running) ? clock() : end;
    int elapsed_milisecs = int((double(_end - begin) / CLOCKS_PER_SEC)*1000);
    return elapsed_milisecs;
}

int Chronometer::TimeSeconds()
{
    clock_t _end = (running) ? clock() : end;
    int elapsed_secs = int(double(_end - begin) / CLOCKS_PER_SEC);
    return elapsed_secs;
}

int Chronometer::TimeTics()
{
    clock_t _end = (running) ? clock() : end;
    int elapsed_tics = int(_end - begin);
    return elapsed_tics;
}

void Chronometer::stop()
{
    end = clock();
}

void Chronometer::reset()
{
    running = false;
    begin = clock();
    end = clock();
}

bool Chronometer::isRunning()
{
    return running;
}
