//
// Created by madatt on 04.01.20.
//

#include "../include/RandomSearch.h"

MscnSolution RandomSearch::generateSolution() {
    if(problem == nullptr)
        return MscnSolution();

    std::vector<double> sol;
    std::vector<double> xd;
    std::vector<double> xf;
    std::vector<double> xm;

    int d = problem->getD();
    int f = problem->getF();
    int m = problem->getM();
    int s = problem->getS();

    int fd = f * d;
    int mf = m * f;
    int sm = s * m;
    int c = 0;
    int sum = 0;
    double rat = 0;


    for (int i = 0; i < d; i++) {
        for (int j = 0; j < f; j++) {
            xd[c] = rand.randomReal<double>(MSCN_SOLVE_MIN, MSCN_SOLVE_MAX);
            sum += xd[c];
            c++;
        }

        rat =

    }

    for (int i = 0; i < mf; i++) {
        xf[i] = rand.randomReal<double>(MSCN_SOLVE_MIN, MSCN_SOLVE_MAX);
    }

    for (int i = 0; i < sm; i++) {
        xm[i] = rand.randomReal<double>(MSCN_SOLVE_MIN, MSCN_SOLVE_MAX);
    }




    for (int i = 0; i < d; i++) {
        if (t_sol.xd.rowSum(i) > sd[i]) ok = 0;
    }

    for (int i = 0; i < f; i++) {
        if (t_sol.xf.rowSum(i) > sf[i]) ok = 0;
    }

    for (int i = 0; i < m; i++) {
        if (t_sol.xm.rowSum(i) > sm[i]) ok = 0;
    }

    for (int i = 0; i < s; i++) {
        if (t_sol.xm.colSum(i) > ss[i]) ok = 0;
    }

    for (int i = 0; i < f; i++) {
        if (t_sol.xd.colSum(i) < t_sol.xf.rowSum(i)) ok = 0;
    }


}
