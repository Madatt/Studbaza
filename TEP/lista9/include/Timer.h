//
// Created by madatt on 13.01.20.
//

#ifndef LISTA9_TIMER_H
#define LISTA9_TIMER_H


class Timer {
public:
    Timer();

    double reset();
    double getElapsedTime();
private:
    double start;
};


#endif //LISTA9_TIMER_H
