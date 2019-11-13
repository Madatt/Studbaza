#include <iostream>
#include "CFileLastError.h"
#include "CFileThrowEx.h"
#include "CFileErrCode.h"
#include "constants.h"

void v_open_test()
{
    CFileErrCode c_file;

    bool b_succ = false;
    for(int i = 0; i < 10 and !b_succ; i++)
    {
        b_succ = c_file.bOpenFile(C_NAME);
    }

    std::cout << b_succ << std::endl;
}


int main() {

    v_open_test();

    return 0;
}