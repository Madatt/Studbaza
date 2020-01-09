//
// Created by madatt on 04.01.20.
//

#ifndef LISTA9_RANDOMSEARCH_H
#define LISTA9_RANDOMSEARCH_H

#include "MscnSolve.h"
#include "Random.h"

class RandomSearch : public MscnSolve {
public:
    RandomSearch(int t_seed)
            : rand(t_seed) {
        problem = nullptr;
    }

    ~RandomSearch(){};

    MscnSolution generateSolution() override;
    MscnSolution generateValidSolution() override;

    MscnSolution bestSolutionFromN(int t_n);
    MscnSolution bestValidSolutionFromN(int t_n);

    MscnSolution bestSolutionTimed(double t_t);

private:
    Random rand;
};


#endif //LISTA9_RANDOMSEARCH_H
