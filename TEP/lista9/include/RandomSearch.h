//
// Created by madatt on 04.01.20.
//

#ifndef LISTA9_RANDOMSEARCH_H
#define LISTA9_RANDOMSEARCH_H

#include "MscnSolve.h"
#include "Random.h"

const double MSCN_SOLVE_MIN = 1.0;
const double MSCN_SOLVE_MAX = 1000.0;

class RandomSearch : public MscnSolve {
public:
    RandomSearch(int t_seed)
            : rand(t_seed) {
        problem = nullptr;
    }

    ~RandomSearch(){};

    MscnSolution generateSolution() override;

private:
    Random rand;
};


#endif //LISTA9_RANDOMSEARCH_H
