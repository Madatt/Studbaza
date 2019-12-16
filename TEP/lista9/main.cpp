#include <iostream>
#include "include/MscnProblem.h"

int main(int argc, char* argv[]) {

    int err = 0;
    MscnProblem problem("test.txt", err);
    std::cout << "Error code constructor: " << err  << std::endl;
    std::vector<double> solution = loadSolution("test_s.txt");
    std::cout << "CS: "<<problem.constraintsSatisfied(solution , err)  << std::endl;
    std::cout << "Error code: " << err  << std::endl<< std::endl;
    err = 0;
    std::cout << "Quality: " << problem.getQuality(solution , err) << std::endl;
    std::cout <<  "Error code: " << err  << std::endl<< std::endl;


    problem.saveToFile("test_save.txt");

    MscnProblem problem2("test_save.txt", err);
    std::cout << "Error code constructor: " << err  << std::endl;
    err = 0;
    std::cout << "CS: "<<problem2.constraintsSatisfied(solution , err)  << std::endl;
    std::cout << "Error code: " << err  << std::endl<< std::endl;
    err = 0;
    std::cout << "Quality: " << problem2.getQuality(solution , err) << std::endl;
    std::cout <<  "Error code: " << err  << std::endl;

}