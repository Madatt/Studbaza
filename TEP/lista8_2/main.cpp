#include "table.h"
#include "test_constants.h"
#include <iostream>

int main() {
    CTable c_tab_0(C_T_NAME1, C_T_TABLE_LEN1);
    CTable c_tab_1(C_T_NAME2, C_T_TABLE_LEN2);
    CTable c_tab_2;

    c_tab_0.vFillRising();
    c_tab_1.vFillRising(C_T_VAL1);

    std::cout << std::endl;
    c_tab_2 = c_tab_0 + c_tab_1;
    c_tab_2 = c_tab_2 + c_tab_2;
    c_tab_2.vShow();

    std::cout << "Copies: " << CTable::i_debug_copy << std::endl;
    std::cout << "Moves: " << CTable::i_debug_move << std::endl;
}
