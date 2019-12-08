#include "table.h"
#include "test_constants.h"
#include <iostream>

int main() {
    CTable c_tab_0(C_T_NAME1, C_T_TABLE_LEN1);
    CTable c_tab_1(C_T_NAME2, C_T_TABLE_LEN2);
    CTable c_tab_2;

    c_tab_0.vFillRising();
    c_tab_1.vFillRising(C_T_VAL1);
    c_tab_1.bSetValue(1, C_T_VAL2);

    std::cout << std::endl;
    c_tab_2 = c_tab_0 + c_tab_1;
    c_tab_0.vShow();
    c_tab_1.vShow();
    c_tab_2.vShow();
    std::cout << std::endl;

    c_tab_2 /= C_T_DIV;
    c_tab_2.vShow();
    c_tab_2 /= 1;
    c_tab_2.vShow();
    std::cout << c_tab_2.iGetSize() << std::endl;

}
