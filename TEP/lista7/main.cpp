#include <iostream>
#include "CMySmartPointer.h"


void v_smart_test1() {
    CMySmartPointer<int> c_p1(new int(1));
    CMySmartPointer<int> c_p2(c_p1);

    CMySmartPointer<float> c_p3(new float(0));
    CMySmartPointer<float> c_p4(new float(0));
    c_p4 = c_p3;
}


int main() {
    v_smart_test1();
    return 0;
}