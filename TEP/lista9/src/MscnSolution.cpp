//
// Created by Madatt on 14.12.2019.
//

#include <fstream>
#include <iostream>
#include "../include/MscnSolution.h"

MscnSolution::MscnSolution(double *t_sol, int t_d, int t_f, int t_m, int t_s, int& t_err) {
    xd.resize(t_f, t_d);
    xf.resize(t_m, t_f);
    xm.resize(t_s, t_m);

    for(int i = 0; i < t_f; i++) {
        for(int j = 0; j < t_d; j++) {
            xd.set(i, j, t_sol[j + i * t_d]);
        }
    }

    for(int i = 0; i < t_m; i++) {
        for(int j = 0; j < t_f; j++) {
            xf.set(i, j, t_sol[j + i * t_f + xd.getTotalSize()]);
        }
    }

    for(int i = 0; i < t_s; i++) {
        for(int j = 0; j < t_m; j++) {
            xm.set(i, j, t_sol[j + i * t_m + xf.getTotalSize() + xd.getTotalSize()]);
        }
    }
}

MscnSolution::MscnSolution(std::string t_path) {
    std::string ign;
    std::ifstream file(t_path);
    int D, F, M, S;

    file >> ign;
    file >> D;
    file >> ign;
    file >> F;
    file >> ign;
    file >> M;
    file >> ign;
    file >> S;

    file >> ign;
    xd = loadMatrixFromStream(file, F, D);
    file >> ign;
    xf = loadMatrixFromStream(file, M, F);
    file >> ign;
    xm = loadMatrixFromStream(file, S, F);

    std::cout << xd.toStr() << xf.toStr() << xm.toStr()<< std::endl;
}
