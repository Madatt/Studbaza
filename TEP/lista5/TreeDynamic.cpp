//
// Created by Madatt on 15.11.2019.
//

#include "TreeDynamic.h"
#include <algorithm>

CTreeDynamic::CNodeDynamic::CNodeDynamic(const CTreeDynamic::CNodeDynamic &cNode)
        : i_val(cNode.i_val), pc_parent_node(cNode.pc_parent_node), v_children(cNode.v_children) {
    for (int i = 0; i < v_children.size(); i++) {
        v_children[i]->pc_parent_node = this;
    }
}

CTreeDynamic::CNodeDynamic::~CNodeDynamic() {
    for (int i = 0; i < v_children.size(); i++)
        delete v_children[i];
}

CTreeDynamic::CNodeDynamic &CTreeDynamic::CNodeDynamic::operator=(const CTreeDynamic::CNodeDynamic &cNode) {
    i_val = cNode.i_val;
    pc_parent_node = cNode.pc_parent_node;
    v_children = cNode.v_children;
    for (int i = 0; i < v_children.size(); i++) {
        v_children[i]->pc_parent_node = this;
    }

    return *this;
}

void CTreeDynamic::CNodeDynamic::vAddNewChild() {
    v_children.push_back(new CTreeDynamic::CNodeDynamic());
    v_children[v_children.size() - 1]->pc_parent_node = this;
}

bool CTreeDynamic::CNodeDynamic::bAddNewChild(CTreeDynamic::CNodeDynamic *pcNode) {
    if (pcNode->pc_parent_node != NULL)
        return false;
    v_children.push_back(pcNode);
    pcNode->pc_parent_node = this;
    return true;
}

CTreeDynamic::CNodeDynamic *CTreeDynamic::CNodeDynamic::pcGetChild(int iChildOffset) {
    if (iChildOffset < 0 or iChildOffset > v_children.size() - 1)
        return NULL;

    return (v_children[iChildOffset]);
}


CTreeDynamic::CNodeDynamic *CTreeDynamic::CNodeDynamic::pcDisconnect() {
    if (pc_parent_node == NULL)
        return this;

    std::vector<CTreeDynamic::CNodeDynamic *>::iterator i_it = pc_parent_node->v_children.erase(
            std::remove(pc_parent_node->v_children.begin(), pc_parent_node->v_children.end(), this),
            pc_parent_node->v_children.end());
    if (i_it != v_children.end()) {
        pc_parent_node = NULL;
        return this;
    } else
        return NULL;
}


CTreeDynamic::CNodeDynamic *CTreeDynamic::CNodeDynamic::pcGetRoot() {
    if (pc_parent_node == NULL)
        return this;
    else return pc_parent_node->pcGetRoot();
}

void CTreeDynamic::CNodeDynamic::vPrintUp() {
    vPrint();
    if (pc_parent_node != NULL)
        pc_parent_node->vPrintUp();
}


void CTreeDynamic::CNodeDynamic::vPrintAllBelow() {
    vPrint();
    for (int i = 0; i < v_children.size(); i++)
        v_children[i]->vPrintAllBelow();
}

void CTreeDynamic::CNodeDynamic::vPrintBetter(int iL) {
    for (int i = 0; i < iL; i++)
        std::cout << "  ";
    vPrintWithParent();
    for (int i = 0; i < v_children.size(); i++)
        v_children[i]->vPrintBetter(iL + 1);
}


CTreeDynamic::CTreeDynamic()
        : pc_root(new CNodeDynamic()) {

}


CTreeDynamic::~CTreeDynamic() {
    delete pc_root;
}


void CTreeDynamic::vPrintTree() {
    pc_root->vPrintBetter(0);
}

bool CTreeDynamic::bMoveSubtree(CTreeDynamic::CNodeDynamic *pcParentNode, CTreeDynamic::CNodeDynamic *pcNewChildNode) {
    if (pcNewChildNode == NULL or pcParentNode == NULL or
        b_same_tree(pcParentNode, pcNewChildNode) or
        pcParentNode->pcGetRoot() != pc_root or
        pcNewChildNode->pc_parent_node == NULL)
        return false;

    pcParentNode->bAddNewChild(pcNewChildNode->pcDisconnect());
    return true;
}

bool b_same_tree(CTreeDynamic::CNodeDynamic *pcNode1, CTreeDynamic::CNodeDynamic *pcNode2) {
    return pcNode1->pcGetRoot() == pcNode2->pcGetRoot();
}
