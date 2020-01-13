//
// Created by madatt on 04.01.20.
//

#ifndef LISTA9_SOLVE_H
#define LISTA9_SOLVE_H

#include "../Mscn/MscnProblem.h"

class Solve {
public:
    virtual ~Solve() {};

    void setProblem(Problem* t_prob){problem = t_prob;};
    virtual Solution bestValidSolutionFromN(int n) = 0;

protected:
    Problem* problem;
};


#endif //LISTA9_SOLVE_H
