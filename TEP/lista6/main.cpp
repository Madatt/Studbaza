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
    c_tree2.pcGetRoot()->pcGetChild(0)->vSetValue(C_STR1);
    c_tree2.pcGetRoot()->pcGetChild(1)->vSetValue(C_STR2);
    c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild(C_STR3);
    c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild(C_STR4);

    c_tree.vPrintTree();
    std::cout << std::endl;
    c_tree2.vPrintTree();
    std::cout << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
    c_tree2.bMoveSubtree(c_tree2.pcGetRoot()->pcGetChild(0), c_tree.pcGetRoot()->pcGetChild(0));
    std::cout << std::endl;
    c_tree.vPrintTree();
    std::cout << std::endl;

    c_tree2.pcGetRoot()->vPrintBetter(0);
    std::cout << std::endl;
    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(2)->pcGetChild(0)->vPrintUp();

    std::cout << std::endl;
    c_tree2.vPrintTree();
    std::cout << std::endl;
    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(2)->pcGetChild(0)->vPrintUp();


}
int main() {
    v_tree_test2();
    return 0;
}