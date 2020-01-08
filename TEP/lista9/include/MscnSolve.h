//
// Created by madatt on 04.01.20.
//

#ifndef LISTA9_MSCNSOLVE_H
#define LISTA9_MSCNSOLVE_H

#include "MscnProblem.h"

class MscnSolve {
public:
    virtual ~MscnSolve() = 0;

    void setProblem(MscnProblem* t_prob){problem = t_prob;};

    virtual MscnSolution generateSolution() = 0;


protected:
    MscnProblem* problem;
};


#endif //LISTA9_MSCNSOLVE_H
