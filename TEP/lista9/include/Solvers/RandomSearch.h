//
// Created by madatt on 04.01.20.
//

#ifndef LISTA9_RANDOMSEARCH_H
#define LISTA9_RANDOMSEARCH_H

#include "../Abstract/Solve.h"
#include "../Abstract/Random.h"

class RandomSearch : public Solve {
public:
    RandomSearch(int t_seed)
            : rand(t_seed) {
        problem = nullptr;
    }

    ~RandomSearch(){};

    Solution generateSolution();
    Solution generateValidSolution();

    Solution bestValidSolutionFromN(int t_n);
    Solution bestValidSolutionTimed(double t_t);

private:
    Random rand;
};


#endif //LISTA9_RANDOMSEARCH_H
