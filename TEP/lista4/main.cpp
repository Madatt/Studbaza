#include <iostream>
#include "CFileLastError.h"

int main() {
    CFileLastError c_f_err;
    c_f_err.vOpenFile("text.txt");
    c_f_err.vPrintLine("sdadsad");
    c_f_err.vPrintLine("sdadsad");
    c_f_err.vPrintLine("sdadsad");
    std::cout << CFileLastError::bGetLastError();
    return 0;
}