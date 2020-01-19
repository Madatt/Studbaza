//
// Created by Madatt on 11.01.2020.
//

#include <ctime>
#include <iostream>
#include "../../include/Solvers/DEvolution.h"

DEvolution::DEvolution(int t_seed, double t_crossP, double t_diffW)
        : rs(t_seed), rand(t_seed) {
    crossP = t_crossP;
    diffW = t_diffW;
    problem = nullptr;
}

DEvolution::~DEvolution() {

}

void DEvolution::changePool(int t_n) {
    if(t_n <= 0)
        t_n = 1;

    if(problem == nullptr)
        return;

    pool.clear();
    rs.setProblem(problem);
    for (int i = 0; i < t_n; i++) {
        pool.push_back(rs.generateValidSolution());
    }
}

Solution &DEvolution::randInd() {
    return pool[rand.randomInteger<int>(0, pool.size() - 1)];
}

bool DEvolution::diffInd(Solution &t_i1, Solution &t_i2, Solution &t_i3, Solution &t_i4) {
    return t_i1.data != t_i2.data and
           t_i1.data != t_i3.data and
           t_i1.data != t_i4.data and
           t_i2.data != t_i3.data and
           t_i2.data != t_i4.data and
           t_i3.data != t_i4.data;
}

Solution DEvolution::bestValidSolutionFromN(int t_n) {
    if(pool.size() <= 0 or problem == nullptr)
        return Solution();

    Solution best = pool[0];
    int c = 0;
    while (c < t_n) {
        for (int i = 0; i < pool.size() and c < t_n; i++) {
            Solution& fI = pool[i];
            Solution bI = randInd();
            Solution aI0 = randInd();
            Solution aI1 = randInd();

            if (diffInd(fI, bI, aI0, aI1)) {
                Solution nI;
                nI.data.resize(problem->getSize());
                for(int g = 0; g < problem->getSize(); g++) {
                    if(rand.randomReal<double>(0, 1) < crossP) {
                        nI.data[g] = bI.data[g] + diffW * (aI0.data[g] - aI1.data[g]);
                    }
                    else {
                        nI.data[g] = fI.data[g];
                    }
                }

                double q = problem->getQualityAndFix(nI);
                int cs = problem->constraintsSatisfied(nI);

                if(!cs)
                    std::cout << "ERROR" << std::endl;

                c++;

                if((q > problem->getQuality(fI)) and cs) {
                    fI.data = nI.data;
                }

                if((q > problem->getQuality(best)) and cs) {
                    best.data = nI.data;
                }
            }
        }
    }

    return best;
}

