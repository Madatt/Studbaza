//
// Created by Madatt on 14.12.2019.
//

#ifndef LISTA9_MSCNSOLUTION_H
#define LISTA9_MSCNSOLUTION_H


#include <vector>
#include "Matrix.h"

struct MscnSolution {
    MscnSolution(double* t_sol, int t_d, int t_f, int t_m, int t_s, int& t_err);
    MscnSolution(std::string t_path);

    Matrix xd;
    Matrix xf;
    Matrix xm;
};


#endif //LISTA9_MSCNSOLUTION_H
