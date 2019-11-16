//
// Created by Madatt on 15.11.2019.
//

#include "TreeDynamic.h"

CNodeDynamic::~CNodeDynamic() {
    for(int i = 0; i < v_children.size(); i++)
        delete v_children[i];

    v_children.clear();
}

void CNodeDynamic::vAddNewChild() {
    v_children.push_back(new CNodeDynamic());
    v_children[v_children.size() - 1]->pc_parent_node = this;
}

bool CNodeDynamic::bAddNewChild(CNodeDynamic *pcNode) {
    if(pcNode->pc_parent_node != NULL)
        return false;
    v_children.push_back(pcNode);
    pcNode->pc_parent_node = this;
    return true;
}

CNodeDynamic *CNodeDynamic::pcGetChild(int iChildOffset) {
    if(iChildOffset < 0 or iChildOffset > v_children.size() - 1)
        return NULL;

    return (v_children[iChildOffset]);
}

CNodeDynamic *CNodeDynamic::pcDisconnectChild(int iChildOffset) {
    if(iChildOffset < 0 or iChildOffset > v_children.size() - 1)
        return NULL;

    CNodeDynamic* pc_node = pcGetChild(iChildOffset);
    v_children.erase(v_children.begin() + iChildOffset);
    pc_node->pc_parent_node = NULL;
    return pc_node;
}


CNodeDynamic *CNodeDynamic::pcDisconnectChild(CNodeDynamic *pcNode) {
    for(int i = 0; i < v_children.size(); i++)
        if(v_children[i] == pcNode)
        {
            v_children.erase(v_children.begin() + i);
            pcNode->pc_parent_node = NULL;
            return pcNode;
        }

    return NULL;
}

void CNodeDynamic::vPrintAllBelow() {
    vPrint();
    for(int i = 0; i < v_children.size(); i++)
        v_children[i]->vPrintAllBelow();
}


CTreeDynamic::CTreeDynamic()
:pc_root(new CNodeDynamic())
{

}

CTreeDynamic::~CTreeDynamic() {
    delete pc_root;
}

void CTreeDynamic::vPrintTree() {
    pc_root->vPrintAllBelow();
}

bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode) {
    if(pcNewChildNode == NULL or pcParentNode == NULL)
        return false;

    if(pcNewChildNode->pcGetParent() != NULL)
        pcNewChildNode->pcGetParent()->pcDisconnectChild(pcNewChildNode);
    pcParentNode->bAddNewChild(pcNewChildNode);
    return true;
}
