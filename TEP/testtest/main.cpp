#include <iostream>
#include <sstream>
#include "constants.h"
#include "mscnproblem.h"
#include "mysmartpointer.h"


int main()
{
    std::ifstream file("test.txt");
    MscnProblem test(file);

    double sol[] = {30.0, 15.0, 30.0, 30.0, 25.0, 25.0, 100.0};
    double sol2[] = {30.0, 15.0, 3440.0, 30.0, 25.0, 25.0, 100.0};
    int err = 5;
    std::cout << test.getQuality(sol, 7, err);
    std::cout << std::endl << err;
    return 0;
}
