#include <iostream>
#include "include/MscnProblem.h"
#include "include/constants.h"
#include "include/RandomSearch.h"

int main(int argc, char *argv[]) {

    int err = 0;
    /*MscnProblem problem(FILE_PROB, err);
    std::cout << STR_ERROR_CON << errorToString(err) << std::endl;
    MscnSolution solution = loadSolution(FILE_SOL, err);
    std::cout << STR_ERROR << errorToString(err) << std::endl ;
    std::cout << STR_CS << problem.constraintsSatisfied(solution, err) << std::endl;
    std::cout << STR_ERROR << errorToString(err) << std::endl << std::endl;
    err = 0;
    std::cout << STR_QUALITY << problem.getQuality(solution, err) << std::endl;
    std::cout << STR_ERROR << errorToString(err) << std::endl << std::endl;


    problem.saveToFile(FILE_SAVE);*/

    Random rnd;

    MscnProblem problem3;
    problem3.generateInstance(123);
    problem3.saveToFile("random.txt");

    RandomSearch rndS(1223);
    rndS.setProblem(problem3);
    MscnSolution sol = rndS.bestSolutionTimed(10);
    std::cout << STR_QUALITY << problem3.getQuality(sol, err) << std::endl;
    std::cout << STR_ERROR << errorToString(err) << std::endl ;
    std::cout << STR_CS << problem3.constraintsSatisfied(sol, err) << std::endl;
    std::cout << STR_ERROR << errorToString(err) << std::endl ;

    sol.saveToFile("random_s.txt");
}