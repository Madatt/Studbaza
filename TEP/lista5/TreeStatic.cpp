//
// Created by Madatt on 15.11.2019.
//

#include "TreeStatic.h"


CTreeStatic::CTreeStatic()
        : c_root() {

}

CTreeStatic::~CTreeStatic() {
    //tak samo
}

void CTreeStatic::vPrintTree() {
    c_root.vPrintAllBelow();
}

CNodeStatic::~CNodeStatic() {
    //std::vector sam usuwa swoje obiekty
}

void CNodeStatic::vAddNewChild() {
    v_children.push_back(CNodeStatic());
    v_children[v_children.size() - 1].pc_parent_node = this;
}

void CNodeStatic::vAddNewChild(CNodeStatic pcNode) {
    v_children.push_back(pcNode);
    v_children[v_children.size() - 1].pc_parent_node = this;
}

CNodeStatic *CNodeStatic::pcGetChild(int iChildOffset) {
    if (iChildOffset < 0 or iChildOffset > v_children.size() - 1)
        return NULL;

    return &(v_children[iChildOffset]);
}

CNodeStatic CNodeStatic::pcDisconnectChild(int iChildOffset) {
    if (iChildOffset < 0 or iChildOffset > v_children.size() - 1)
        return CNodeStatic();

    CNodeStatic *pc_node = pcGetChild(iChildOffset);
    v_children.erase(v_children.begin() + iChildOffset);
    pc_node->pc_parent_node = NULL;
    return *pc_node;
}

CNodeStatic CNodeStatic::pcDisconnectChild(CNodeStatic pcNode) {
    for (int i = 0; i < v_children.size(); i++)
        if (v_children[i].i_val == pcNode.i_val and pcNode.pc_parent_node == this) {
            v_children.erase(v_children.begin() + i);
            pcNode.pc_parent_node = NULL;
            return pcNode;
        }

    return CNodeStatic();
}

void CNodeStatic::vPrintAllBelow() {
    vPrint();
    for (int i = 0; i < v_children.size(); i++)
        v_children[i].vPrintAllBelow();
}

void CNodeStatic::vPrintUp() {
    vPrint();
    if (pc_parent_node != NULL)
        pc_parent_node->vPrintUp();
}

bool bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode) {
    if (pcNewChildNode == NULL or pcParentNode == NULL)
        return false;

    if (pcNewChildNode->pcGetParent() != NULL)
        pcNewChildNode->pcGetParent()->pcDisconnectChild(*pcNewChildNode);
    pcParentNode->vAddNewChild(*pcNewChildNode);
    return true;
}

