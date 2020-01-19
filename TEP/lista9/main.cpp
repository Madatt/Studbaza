#include <iostream>
#include <Mscn/MscnRandomProblem.h>
#include "include/Mscn/MscnProblem.h"
#include "include/constants.h"
#include "include/Solvers/RandomSearch.h"
#include "include/Solvers/DEvolution.h"

int main(int argc, char *argv[]) {

    int err = 0;
    Random rnd;

    MscnProblem problem3;
    MscnRandomProblem rProb(SEED);

    problem3 = rProb.generate();
    problem3.saveToFile("random.txt");

    RandomSearch rndS(SEED);
    rndS.setProblem(&problem3);

    /*Solution sol = rndS.generateSolution();
    MscnSolution mSol(sol.data, problem3.getD(), problem3.getF(), problem3.getM(), problem3.getS());
    mSol.saveToFile("fix_before.txt");
    std::cout << STR_CS << problem3.constraintsSatisfied(sol) << std::endl << std::endl;
    problem3.getQualityAndFix(sol);
    MscnSolution mSol2(sol.data, problem3.getD(), problem3.getF(), problem3.getM(), problem3.getS());
    mSol2.saveToFile("fix_after.txt");
    std::cout  << std::endl << std::endl;
    std::cout << STR_CS << problem3.constraintsSatisfied(sol) << std::endl << std::endl;*/


    Solution sol = rndS.bestValidSolutionFromN(NN);
    std::cout << STR_QUALITY << problem3.getQuality(sol) << std::endl;
    std::cout << STR_CS << problem3.constraintsSatisfied(sol) << std::endl << std::endl;

    MscnSolution mSol(sol.data, problem3.getD(), problem3.getF(), problem3.getM(), problem3.getS());
    mSol.saveToFile("random_s.txt");

    DEvolution dE(SEED);
    dE.setProblem(&problem3);
    dE.changePool(POOL_S);
    Solution sol2 = dE.bestValidSolutionFromN(NN);
    std::cout << STR_QUALITY << problem3.getQuality(sol2) << std::endl;
    std::cout << STR_CS << problem3.constraintsSatisfied(sol2) << std::endl << std::endl;

    dE.setProblem(&problem3);
    dE.changePool(POOL_S);
    sol2 = dE.bestValidSolutionFromN(NN2);
    std::cout << STR_QUALITY << problem3.getQuality(sol2) << std::endl;
    std::cout << STR_CS << problem3.constraintsSatisfied(sol2) << std::endl << std::endl;

    dE.setProblem(&problem3);
    dE.changePool(POOL_S);
    sol2 = dE.bestValidSolutionFromN(NN3);
    std::cout << STR_QUALITY << problem3.getQuality(sol2) << std::endl;
    std::cout << STR_CS << problem3.constraintsSatisfied(sol2) << std::endl << std::endl;

    MscnSolution mSol2(sol2.data, problem3.getD(), problem3.getF(), problem3.getM(), problem3.getS());
    mSol2.saveToFile("random_s_de.txt");
}