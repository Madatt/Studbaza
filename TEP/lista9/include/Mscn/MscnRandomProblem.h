//
// Created by madatt on 13.01.20.
//

#ifndef LISTA9_PROBLEMGEN_H
#define LISTA9_PROBLEMGEN_H


#include "Abstract/Random.h"
#include "Mscn/MscnProblem.h"

class MscnRandomProblem {
public:
    MscnRandomProblem(int t_seed)
    :rand(t_seed) {

    }

    MscnProblem generate();

private:
    Random rand;

};


#endif //LISTA9_PROBLEMGEN_H
