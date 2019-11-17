#include <iostream>
#include "TreeStatic.h"
#include "TreeDynamic.h"

void v_tree_test()
{
    CTreeStatic c_tree;
    c_tree.pcGetRoot()->vAddNewChild();
    c_tree.pcGetRoot()->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);


    CTreeStatic c_tree2(c_tree);


    c_tree.pcGetRoot()->vPrintBetter(0);
    std::cout << std::endl;
    c_tree2.pcGetRoot()->vPrintBetter(0);
    bMoveSubtree(c_tree2.pcGetRoot()->pcGetChild(0), c_tree.pcGetRoot()->pcGetChild(1));
    std::cout << "---------------------------------------------------------" << std::endl;
    c_tree.pcGetRoot()->vPrintBetter(0);
    std::cout << std::endl;
    c_tree2.pcGetRoot()->vPrintBetter(0);
}

void v_tree_test2()
{
    std::cout << std::endl;
    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << std::endl;
    CTreeDynamic c_tree;
    c_tree.pcGetRoot()->vAddNewChild();
    c_tree.pcGetRoot()->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(11);
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(12);
    c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(21);
    c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(22);

    CTreeDynamic c_tree2;
    c_tree2.pcGetRoot()->vAddNewChild();
    c_tree2.pcGetRoot()->vAddNewChild();
    c_tree2.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    c_tree2.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();

    c_tree.pcGetRoot()->vPrintBetter(0);
    std::cout << std::endl;
    c_tree2.pcGetRoot()->vPrintBetter(0);
    std::cout << "---------------------------------------------------------" << std::endl;
    bMoveSubtree(c_tree2.pcGetRoot()->pcGetChild(0), c_tree.pcGetRoot()->pcGetChild(0));
    std::cout << std::endl;
    c_tree.pcGetRoot()->vPrintBetter(0);
    std::cout << std::endl;
    c_tree2.pcGetRoot()->vPrintBetter(0);



}
int main() {
    v_tree_test();
    v_tree_test2();
    return 0;
}