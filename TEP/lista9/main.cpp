#include <iostream>
#include "include/MscnProblem.h"

int main() {
    MscnProblem problem("test.txt");
    MscnSolution solution("test_s.txt");
    int err = 0;
    std::cout << problem.getQuality(solution, err) << std::endl;
    double sol[] = {30.0, 15.0, 30.0, 30.0, 25.0, 25.0, 100.0};
    std::cout << problem.getQuality(sol, 7, err) << std::endl;
    std::cout << err;
    return 0;
}