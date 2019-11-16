//
// Created by Madatt on 15.11.2019.
//

#ifndef LISTA5_TREEDYNAMIC_H
#define LISTA5_TREEDYNAMIC_H

#include <iostream>
#include <vector>

class CNodeDynamic
{
public:
    CNodeDynamic() {i_val = 0; pc_parent_node = NULL;};
    ~CNodeDynamic();
    void vSetValue(int iNewVal) {i_val = iNewVal;};
    int iGetChildrenNumber() {return(v_children.size());};
    void vAddNewChild();
    bool bAddNewChild(CNodeDynamic* pcNode);
    CNodeDynamic *pcGetChild(int iChildOffset);
    CNodeDynamic *pcGetParent() {return pc_parent_node;};
    CNodeDynamic *pcDisconnectChild(int iChildOffset);
    CNodeDynamic *pcDisconnectChild(CNodeDynamic * pcNode);

    void vPrint() {std::cout << " " << i_val;};
    void vPrintAllBelow();
private:
    std::vector<CNodeDynamic *> v_children;
    CNodeDynamic *pc_parent_node;
    int i_val;
};

class CTreeDynamic
{
public:
    CTreeDynamic();
    ~CTreeDynamic();
    CNodeDynamic *pcGetRoot() {return(pc_root);}
    void vPrintTree();
private:
    CNodeDynamic *pc_root;
};

bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode);

#endif //LISTA5_TREEDYNAMIC_H
