#include <iostream>
#include "CTab.h"

CTab c_test1() {
    CTab c_tab;

    return std::move(c_tab);
}


CTab c_test2() {
    CTab c_tab;

    return c_tab;
}


int main() {
    c_test1();
    c_test2();
    return 0;
}