//
// Created by madatt on 04.01.20.
//

#include <iostream>
#include <ctime>
#include "../include/RandomSearch.h"
#include "../include/constants.h"

MscnSolution RandomSearch::generateSolution() {
    if (problem == nullptr)
        return MscnSolution();

    std::vector<double> sol;

    int d = problem->getD();
    int f = problem->getF();
    int m = problem->getM();
    int s = problem->getS();

    for (int i = 0; i < d; i++) {
        for (int j = 0; j < f; j++) {
            std::pair<double, double> p = problem->getXdMinMax(i, j);
            sol.push_back(rand.randomReal(p.first, p.second) / d);
        }
    }

    for (int i = 0; i < f; i++) {
        for (int j = 0; j < m; j++) {
            std::pair<double, double> p = problem->getXfMinMax(i, j);
            sol.push_back(rand.randomReal(p.first, p.second) / f);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < s; j++) {
            std::pair<double, double> p = problem->getXmMinMax(i, j);
            sol.push_back(rand.randomReal(p.first, p.second) / m);
        }
    }

    return MscnSolution(sol, d, f, m, s);
}

MscnSolution RandomSearch::generateValidSolution() {
    int ok = 0;
    int err = 0;
    MscnSolution sol;
    do {
        sol = generateSolution();
        ok = problem->constraintsSatisfied(sol, err);
    } while (!ok);

    return sol;
}

MscnSolution RandomSearch::bestSolutionFromN(int t_n) {
    if (t_n <= 0)
        return MscnSolution();

    MscnSolution sol = generateSolution();
    int err;
    for (int i = 0; i < t_n - 1; i++) {
        MscnSolution sol2 = generateSolution();
        if (problem->getQuality(sol2, err) > problem->getQuality(sol, err))
            sol = sol2;
    }

    return sol;

}

MscnSolution RandomSearch::bestValidSolutionFromN(int t_n) {
    if (t_n <= 0)
        return MscnSolution();

    int err;
    MscnSolution sol = generateValidSolution();
    for (int i = 0; i < t_n; i++) {
        MscnSolution sol2 = generateValidSolution();

        if (problem->getQuality(sol2, err) > problem->getQuality(sol, err))
            sol = sol2;
    }

    return sol;
}

MscnSolution RandomSearch::bestSolutionTimed(double t_t) {
    if (t_t <= 0)
        return MscnSolution();

    int err;
    const clock_t start = clock();
    MscnSolution sol = generateValidSolution();
    while(double(clock() - start)/CLOCKS_PER_SEC <= t_t) {
        MscnSolution sol2 = generateValidSolution();

        if (problem->getQuality(sol2, err) > problem->getQuality(sol, err))
            sol = sol2;
    }

    return sol;
}
