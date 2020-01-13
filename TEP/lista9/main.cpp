#include <iostream>
#include "include/Mscn/MscnProblem.h"
#include "include/constants.h"
#include "include/Solvers/RandomSearch.h"
#include "include/Solvers/DEvolution.h"

int main(int argc, char *argv[]) {

    int err = 0;
    Random rnd;

    MscnProblem problem3;
    problem3.generateInstance(123);
    problem3.saveToFile("random.txt");

    RandomSearch rndS(123);
    rndS.setProblem(&problem3);
    Solution sol = rndS.bestValidSolutionFromN(10000);
    std::cout << STR_QUALITY << problem3.getQuality(sol) << std::endl;
    std::cout << STR_CS << problem3.constraintsSatisfied(sol) << std::endl << std::endl;

    MscnSolution mSol(sol.data, problem3.getD(), problem3.getF(), problem3.getM(), problem3.getS());
    mSol.saveToFile("random_s.txt");

    DEvolution dE(123, 20);
    dE.setProblem(&problem3);
    dE.changePool(40);
    Solution sol2 = dE.bestValidSolutionFromN(10000);
    std::cout << STR_QUALITY << problem3.getQuality(sol2) << std::endl;
    std::cout << STR_CS << problem3.constraintsSatisfied(sol2) << std::endl;

    MscnSolution mSol2(sol2.data, problem3.getD(), problem3.getF(), problem3.getM(), problem3.getS());
    mSol2.saveToFile("random_s_de.txt");
}