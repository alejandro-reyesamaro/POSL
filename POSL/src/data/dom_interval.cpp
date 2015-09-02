#include "dom_interval.h"

DomInterval::DomInterval(int _a, int _b)
    : a(_a), b(_b)
{}

int DomInterval::Length(){ return b - a + 1; }
