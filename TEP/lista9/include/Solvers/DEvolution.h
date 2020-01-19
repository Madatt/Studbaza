//
// Created by Madatt on 11.01.2020.
//

#ifndef LISTA9_DEVOLUTION_H
#define LISTA9_DEVOLUTION_H


#include "../Abstract/Solve.h"
#include "RandomSearch.h"

const double DE_CROSS_PROB = 0.5;
const double DE_DIFF_W = 2;

class DEvolution : public Solve{
public:
    DEvolution(int t_seed, double t_crossP = DE_CROSS_PROB, double t_diffW = DE_DIFF_W);
    ~DEvolution() override;

    void changePool(int t_n);
    Solution bestValidSolutionFromN(int t_n);

private:
    Random rand;
    RandomSearch rs;
    double crossP;
    double diffW;
    std::vector<Solution> pool;

    Solution& randInd();
    bool diffInd(Solution& t_i1, Solution& t_i2, Solution& t_i3, Solution& t_i4);
};


#endif //LISTA9_DEVOLUTION_H
