#include <iostream>
#include <string>
#include "TreeDynamic.h"
#include "test_vals.h"

void v_tree_test2()
{
    std::cout << std::endl;
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << std::endl;
    CTreeDynamic<std::string> c_tree;
    c_tree.pcGetRoot()->vAddNewChild(C_STR5);
    c_tree.pcGetRoot()->vAddNewChild(C_STR6);
    c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(C_STR1);
    c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(C_STR2);
    c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild(C_STR1);
    c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild(C_STR2);
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(C_STR1);
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(C_STR2);
    c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild(C_STR3);
    c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild(C_STR4);
    c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(C_STR3);
    c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(C_STR4);

    CTreeDynamic<std::string> c_tree2;
    c_tree2.pcGetRoot()->vAddNewChild(C_STR5);
    c_tree2.pcGetRoot()->vAddNewChild(C_STR6);
    c_tree2.pcGetRoot()->pcGetChild(0)->vSetValue(C_STR5);
    c_tree2.pcGetRoot()->pcGetChild(1)->vSetValue(C_STR2);
    c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild(C_STR3);
    c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild(C_STR4);

    c_tree.vPrintTree();
    std::cout << std::endl;
    c_tree2.vPrintTree();
    std::cout << std::endl;
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vPrintUp();

    std::cout << "---------------------------------------------------------" << std::endl;
    c_tree2.bMoveSubtree(c_tree2.pcGetRoot()->pcGetChild(0), c_tree.pcGetRoot()->pcGetChild(0));
    std::cout << std::endl;
    c_tree.vPrintTree();
    std::cout << std::endl;
    c_tree2.vPrintTree();
    std::cout << std::endl;
    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(2)->pcGetChild(0)->vPrintUp();
    std::cout << std::endl;
    std::cout << c_tree2.iLeaves();
    std::cout << std::endl;
    CTreeDynamic<std::string> c_tree3;
    c_tree3.pcGetRoot()->vAddNewChild(C_STR4);
    c_tree3.pcGetRoot()->pcGetChild(0)->vAddNewChild(C_STR1);
    c_tree3.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild(C_STR2);
    c_tree3.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->pcGetChild(0)->vAddNewChild(C_STR3);
    c_tree3.vPrintTree();
    std::cout << std::endl;
    std::cout << c_tree3.iLeaves() << std::endl;


}

void v_tree_test1(){

    CTreeDynamic<int> c_tree4;
    c_tree4.pcGetRoot()->vAddNewChild(C_NUM1);
    c_tree4.pcGetRoot()->vAddNewChild(C_NUM2);
    c_tree4.pcGetRoot()->pcGetChild(0)->vAddNewChild(C_NUM2);
    c_tree4.pcGetRoot()->pcGetChild(1)->vAddNewChild(C_NUM3);
    c_tree4.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild(C_NUM4);
    c_tree4.vPrintTree();
    std::cout << std::endl;
    std::cout << c_tree4.iLeaves() <<std::endl;
    std::cout << std::endl;
}
void v_tree_test3(){

    CTreeDynamic<double> c_tree4;
    c_tree4.pcGetRoot()->vAddNewChild(C_NUMD1);
    c_tree4.pcGetRoot()->vAddNewChild(C_NUMD2);
    c_tree4.pcGetRoot()->pcGetChild(0)->vAddNewChild(C_NUMD2);
    c_tree4.pcGetRoot()->pcGetChild(1)->vAddNewChild(C_NUMD3);
    c_tree4.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vAddNewChild(C_NUMD4);
    c_tree4.vPrintTree();
    std::cout << std::endl;
    std::cout << c_tree4.iLeaves() <<std::endl;
    std::cout << std::endl;
}

int main() {
    v_tree_test1();
    v_tree_test2();
    v_tree_test3();
    return 0;
}