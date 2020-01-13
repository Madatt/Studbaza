//
// Created by madatt on 04.01.20.
//

#include <iostream>
#include <ctime>
#include "../../include/Solvers/RandomSearch.h"
#include "../../include/constants.h"

Solution RandomSearch::generateSolution() {
    if (problem == nullptr)
        return Solution();

    Solution sol;

    for(int i = 0; i < problem->getSize(); i++) {
        std::pair<double, double> p = problem->getSolutionMinMax(i);
        sol.data.push_back(rand.randomReal(p.first, p.second));

    }

    return sol;
}

Solution RandomSearch::generateValidSolution() {
    int ok = 0;
    int err = 0;
    Solution sol;
    do {
        sol = generateSolution();
        ok = problem->constraintsSatisfied(sol);
    } while (!ok);

    return sol;
}


Solution RandomSearch::bestValidSolutionFromN(int t_n) {
    if (t_n <= 0)
        return Solution();

    int err;
    Solution sol = generateValidSolution();
    for (int i = 0; i < t_n; i++) {
        Solution sol2 = generateSolution();

        if (problem->getQuality(sol2) > problem->getQuality(sol)  and problem->constraintsSatisfied(sol2) )
            sol = sol2;
    }

    return sol;
}

Solution RandomSearch::bestValidSolutionTimed(double t_t) {
    if (t_t <= 0)
        return Solution();

    int err;
    const clock_t start = clock();
    Solution sol = generateValidSolution();
    while(double(clock() - start)/CLOCKS_PER_SEC <= t_t) {
        Solution sol2 = generateSolution();

        if ((problem->getQuality(sol2) > problem->getQuality(sol)) and problem->constraintsSatisfied(sol2))
            sol = sol2;
    }

    return sol;
}
