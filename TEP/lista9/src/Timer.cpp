//
// Created by madatt on 13.01.20.
//

#include <ctime>
#include "../include/Timer.h"

Timer::Timer() {
    reset();
}

double Timer::reset() {
    double tmp = start;
    start = clock();
    return (clock() - tmp)/CLOCKS_PER_SEC;
}

double Timer::getElapsedTime() {
    return (clock() - start)/CLOCKS_PER_SEC;
}
