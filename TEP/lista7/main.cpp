#include <iostream>
#include "CMySmartPointer.h"


void v_smart_test1() {
    CMySmartPointer<int> c_p1(new int(1));
    CMySmartPointer<int> c_p2(c_p1);

    CMySmartPointer<float> c_p3(new float(0));
    CMySmartPointer<float> c_p4(new float(0));
    c_p4 = c_p3;

    CMySmartPointer<int> c_p5(new int(C_TVAL1));
    CMySmartPointer<int> c_p6(new int(C_TVAL2));
    std::cout << *c_p5 << std::endl;
    std::cout << *c_p6 << std::endl;
    c_p5 = c_p6;
    std::cout << *c_p5 << std::endl;
    std::cout << *c_p6 << std::endl;

}


int main() {
    v_smart_test1();
    return 0;
}