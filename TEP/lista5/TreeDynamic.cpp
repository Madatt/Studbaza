//
// Created by Madatt on 15.11.2019.
//

#include "TreeDynamic.h"
#include <algorithm>

CNodeDynamic::CNodeDynamic(const CNodeDynamic &cNode)
        : i_val(cNode.i_val), pc_parent_node(cNode.pc_parent_node), v_children(cNode.v_children) {
    for (int i = 0; i < v_children.size(); i++) {
        v_children[i]->pc_parent_node = this;
    }
}

CNodeDynamic::~CNodeDynamic() {
    for (int i = 0; i < v_children.size(); i++)
        delete v_children[i];
}

CNodeDynamic &CNodeDynamic::operator=(const CNodeDynamic &cNode) {
    i_val = cNode.i_val;
    pc_parent_node = cNode.pc_parent_node;
    v_children = cNode.v_children;
    for (int i = 0; i < v_children.size(); i++) {
        v_children[i]->pc_parent_node = this;
    }

    return *this;
}

void CNodeDynamic::vAddNewChild() {
    v_children.push_back(new CNodeDynamic());
    v_children[v_children.size() - 1]->pc_parent_node = this;
}

bool CNodeDynamic::bAddNewChild(CNodeDynamic *pcNode) {
    if (pcNode->pc_parent_node != NULL)
        return false;
    v_children.push_back(pcNode);
    pcNode->pc_parent_node = this;
    return true;
}

CNodeDynamic *CNodeDynamic::pcGetChild(int iChildOffset) {
    if (iChildOffset < 0 or iChildOffset > v_children.size() - 1)
        return NULL;

    return (v_children[iChildOffset]);
}


CNodeDynamic *CNodeDynamic::pcDisconnect() {
    if (pc_parent_node == NULL)
        return NULL;

    std::vector<CNodeDynamic *>::iterator i_it = pc_parent_node->v_children.erase(
            std::remove(pc_parent_node->v_children.begin(), pc_parent_node->v_children.end(), this), pc_parent_node->v_children.end());
    if (i_it != v_children.end())
    {
        pc_parent_node = NULL;
        return this;
    }
    else
        return NULL;


}


CNodeDynamic *CNodeDynamic::pcGetRoot() {
    if (pc_parent_node == NULL)
        return this;
    else return pc_parent_node->pcGetRoot();
}

void CNodeDynamic::vPrintUp() {
    vPrint();
    if (pc_parent_node != NULL)
        pc_parent_node->vPrintUp();
}


void CNodeDynamic::vPrintAllBelow() {
    vPrint();
    for (int i = 0; i < v_children.size(); i++)
        v_children[i]->vPrintAllBelow();
}

void CNodeDynamic::vPrintBetter(int iL) {
    for (int i = 0; i < iL; i++)
        std::cout << "  ";
    vPrint();
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
    pc_root->vPrintAllBelow();
}

bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode) {
    if (pcNewChildNode == NULL or pcParentNode == NULL)
        return false;

    if (pcParentNode->pcGetRoot() == pcNewChildNode->pcGetRoot())
        return false;

    pcParentNode->bAddNewChild(pcNewChildNode->pcDisconnect());
    return true;
}
