//
// Created by Madatt on 11.01.2020.
//

#ifndef LISTA9_PROBLEM_H
#define LISTA9_PROBLEM_H


#include "Solution.h"

class Problem {
public:
    virtual ~Problem() {

    }

    virtual std::pair<double, double> getSolutionMinMax(int) = 0;
    virtual int getSize() = 0;
    virtual double getQuality(Solution&) = 0;
    virtual bool constraintsSatisfied(Solution&) = 0;
};


#endif //LISTA9_PROBLEM_H
