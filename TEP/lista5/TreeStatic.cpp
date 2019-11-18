//
// Created by Madatt on 15.11.2019.
//

#include <algorithm>
#include "TreeStatic.h"


CTreeStatic::CTreeStatic()
        : c_root() {

}

CTreeStatic::CTreeStatic(CNodeStatic cNode) {
    c_root = cNode;
}


CTreeStatic::~CTreeStatic() {
    //tak samo
}

void CTreeStatic::vPrintTree() {
    c_root.vPrintAllBelow();
}

CTreeStatic::CNodeStatic::CNodeStatic(const CNodeStatic &cNode)
        : i_val(cNode.i_val), pc_parent_node(cNode.pc_parent_node), v_children(cNode.v_children) {
    for (int i = 0; i < v_children.size(); i++)
        v_children[i].pc_parent_node = this;
}

CTreeStatic::CNodeStatic::~CNodeStatic() {
    //std::vector sam usuwa swoje obiekty
}

CTreeStatic::CNodeStatic &CTreeStatic::CNodeStatic::operator=(const CNodeStatic &cNode) {
    pc_parent_node = cNode.pc_parent_node;
    i_val = cNode.i_val;
    v_children = cNode.v_children;
    for (int i = 0; i < v_children.size(); i++)
        v_children[i].pc_parent_node = this;

    return *this;
}

bool CTreeStatic::CNodeStatic::operator!=(const CTreeStatic::CNodeStatic &cNode) {
    return !(*this == cNode);
}

bool CTreeStatic::CNodeStatic::operator==(const CNodeStatic &cNode) const{
    return (i_val == cNode.i_val &&
            pc_parent_node == cNode.pc_parent_node &&
            v_children == cNode.v_children);
}

void CTreeStatic::CNodeStatic::vAddNewChild() {
    v_children.push_back(CNodeStatic());
    v_children[v_children.size() - 1].pc_parent_node = this;
}

void CTreeStatic::CNodeStatic::vAddNewChild(CNodeStatic pcNode) {
    v_children.push_back(pcNode);
    v_children[v_children.size() - 1].pc_parent_node = this;
}

CTreeStatic::CNodeStatic *CTreeStatic::CNodeStatic::pcGetChild(int iChildOffset) {
    if (iChildOffset < 0 or iChildOffset > v_children.size() - 1)
        return NULL;

    return &(v_children[iChildOffset]);
}


CTreeStatic::CNodeStatic CTreeStatic::CNodeStatic::pcDisconnect() {
    if (pc_parent_node == NULL)
        return CNodeStatic();

    for (int i = 0; i < v_children.size(); i++) {
        if (pc_parent_node->v_children[i] == *this) {
            CNodeStatic pc_tmp = *this;
            pc_parent_node->v_children.erase(v_children.begin() + i);
            pc_tmp.pc_parent_node = NULL;
            return pc_tmp;
        }

    }
    return CNodeStatic();
}

CTreeStatic::CNodeStatic *CTreeStatic::CNodeStatic::pcGetRoot() {
    if (pc_parent_node == NULL)
        return this;
    else return pc_parent_node->pcGetRoot();
}

void CTreeStatic::CNodeStatic::vPrintAllBelow() {
    vPrint();
    for (int i = 0; i < v_children.size(); i++)
        v_children[i].vPrintAllBelow();
}

void CTreeStatic::CNodeStatic::vPrintUp() {
    vPrint();
    if (pc_parent_node != NULL)
        pc_parent_node->vPrintUp();
}

void CTreeStatic::CNodeStatic::vPrintBetter(int iL) {
    for (int i = 0; i < iL; i++)
        std::cout << "  ";
    vPrint();
    for (int i = 0; i < v_children.size(); i++)
        v_children[i].vPrintBetter(iL + 1);
}

bool CTreeStatic::bMoveSubtree(CTreeStatic::CNodeStatic *pcParentNode, CTreeStatic::CNodeStatic *pcNewChildNode) {
    if (pcNewChildNode == NULL or pcParentNode == NULL or
        pcParentNode->pcGetRoot() == pcNewChildNode->pcGetRoot() or
        *(pcParentNode->pcGetRoot()) != c_root)
        return false;

    pcParentNode->vAddNewChild(pcNewChildNode->pcDisconnect());
    return true;
}

