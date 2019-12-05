#include <iostream>
#include <string>
#include "CMySmartPointer.h"


void v_smart_test1() {
    CMySmartPointer<int> c_p1(new int(1));
    CMySmartPointer<int> c_p2(c_p1);

    CMySmartPointer<float> c_p3(new float(0));
    CMySmartPointer<float> c_p4(new float(0));
    c_p4 = c_p3;

    CMySmartPointer<int> c_p5(new int(C_ITVAL1));
    CMySmartPointer<int> c_p6(new int(C_ITVAL2));
    std::cout << *c_p5 << std::endl;
    std::cout << *c_p6 << std::endl;
    c_p5 = c_p6;
    *c_p5 = C_ITVAL3;
    std::cout << *c_p5 << std::endl;
    std::cout << *c_p6 << std::endl;

    CMySmartPointer<std::string> c_p7 = new std::string(C_STVAL1);
    CMySmartPointer<std::string> c_p8 = c_p7;
    std::cout << *c_p7 << std::endl;
    std::cout << *c_p8 << std::endl;
    c_p7 = c_p8;
    *c_p8 = C_STVAL2;
    std::cout << *c_p7 << std::endl;
    std::cout << *c_p8 << std::endl;
    CMySmartPointer<std::string> c_p9 = c_p8.cDuplicate();
    std::cout << *c_p9 << std::endl;
}


int main() {
    v_smart_test1();
    return 0;
}