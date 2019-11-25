#include <iostream>
#include "TreeStatic.h"
#include "TreeDynamic.h"
#include "test_vals.h"

void v_tree_test()
{
    CTreeStatic c_tree;
    c_tree.pcGetRoot()->vAddNewChild();
    c_tree.pcGetRoot()->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    c_tree.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(C_NUM1);
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(C_NUM2);
    c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(C_NUM3);
    c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(C_NUM4);


    CTreeStatic c_tree2(c_tree);


    c_tree.vPrintTree();
    std::cout << std::endl;
    c_tree2.vPrintTree();
    c_tree2.bMoveSubtree(c_tree2.pcGetRoot()->pcGetChild(0), c_tree.pcGetRoot()->pcGetChild(1));
    std::cout << "---------------------------------------------------------" << std::endl;
    c_tree.vPrintTree();
    std::cout << std::endl;
    c_tree2.vPrintTree();
    std::cout << std::endl;
    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(2)->pcGetChild(1)->vPrintUp();


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
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(C_NUM1);
    c_tree.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(C_NUM2);
    c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(1)->vAddNewChild();
    c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(0)->vSetValue(C_NUM3);
    c_tree.pcGetRoot()->pcGetChild(1)->pcGetChild(1)->vSetValue(C_NUM4);

    CTreeDynamic c_tree2;
    c_tree2.pcGetRoot()->vAddNewChild();
    c_tree2.pcGetRoot()->vAddNewChild();
    c_tree2.pcGetRoot()->pcGetChild(0)->vSetValue(1);
    c_tree2.pcGetRoot()->pcGetChild(1)->vSetValue(2);
    c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
    c_tree2.pcGetRoot()->pcGetChild(0)->vAddNewChild();

    c_tree.vPrintTree();
    std::cout << std::endl;
    c_tree2.vPrintTree();
    std::cout << "---------------------------------------------------------" << std::endl;
    c_tree2.bMoveSubtree(c_tree2.pcGetRoot()->pcGetChild(0), c_tree.pcGetRoot()->pcGetChild(0));
    std::cout << std::endl;
    c_tree.vPrintTree();
    std::cout << std::endl;
<<<<<<< HEAD
    c_tree2.pcGetRoot()->vPrintBetter(0);
    std::cout << std::endl;
    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(2)->pcGetChild(0)->vPrintUp();

=======
    c_tree2.vPrintTree();
    std::cout << std::endl;
    c_tree2.pcGetRoot()->pcGetChild(0)->pcGetChild(2)->pcGetChild(0)->vPrintUp();
>>>>>>> 3ba0b82edb9f6b03e334a5b28d3e79a9122e8dd8


}
int main() {
    v_tree_test();
    v_tree_test2();
    return 0;
}