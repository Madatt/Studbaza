#include <iostream>
#include "include/MscnProblem.h"

int main() {
    MscnProblem problem("test.txt");
    MscnSolution solution("test_s.txt");
    int err = 0;
    std::cout << problem.getQuality(solution, err) << std::endl;
    std::cout << err;
    return 0;
}