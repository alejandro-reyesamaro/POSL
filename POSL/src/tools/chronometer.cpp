#include "chronometer.h"

Chronometer::Chronometer() : running(false), begin(clock()), end(clock())
{}

void Chronometer::start()
{
    running = true;
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
    int elapsed_milisecs = int(double(_end - begin) / CLOCKS_PER_SEC);
    return elapsed_milisecs;
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
