//
// Created by Madatt on 15.11.2019.
//

#ifndef LISTA5_TREESTATIC_H
#define LISTA5_TREESTATIC_H

#include <vector>
#include <iostream>

class CNodeStatic
{
public:
    CNodeStatic() {i_val = 0; pc_parent_node = NULL;};
    ~CNodeStatic();
    void vSetValue(int iNewVal) {i_val = iNewVal;};

    int iGetChildrenNumber() {return(v_children.size());};
    void vAddNewChild();
    void vAddNewChild(CNodeStatic pcNode);
    CNodeStatic *pcGetChild(int iChildOffset);
    CNodeStatic *pcGetParent() {return pc_parent_node;};
    CNodeStatic pcDisconnectChild(int iChildOffset);
    CNodeStatic pcDisconnectChild(CNodeStatic pcNode);
    void vPrint() {std::cout << " " << i_val;};
    void vPrintAllBelow();
    void vPrintUp();
private:
    std::vector<CNodeStatic> v_children;
    CNodeStatic *pc_parent_node;
    int i_val;
};

class CTreeStatic
{
public:
    CTreeStatic();
    ~CTreeStatic();
    CNodeStatic *pcGetRoot() {return(&c_root);}
    void vPrintTree();
private:
    CNodeStatic c_root;
};

bool bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode);


#endif //LISTA5_TREESTATIC_H
