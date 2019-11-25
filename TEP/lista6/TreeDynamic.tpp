//
// Created by Madatt on 15.11.2019.
//

#include "TreeDynamic.h"
#include <algorithm>

template <typename T>
CNodeDynamic<T>::CNodeDynamic(const CNodeDynamic<T> &cNode)
        : t_val(cNode.t_val), pc_parent_node(cNode.pc_parent_node), v_children(cNode.v_children) {
    for (int i = 0; i < v_children.size(); i++) {
        v_children[i]->pc_parent_node = this;
    }
}

template <typename T>
CNodeDynamic<T>::~CNodeDynamic() {
    for (int i = 0; i < v_children.size(); i++)
        delete v_children[i];
}

template <typename T>
CNodeDynamic<T> &CNodeDynamic<T>::operator=(const CNodeDynamic<T> &cNode) {
    t_val = cNode.t_val;
    pc_parent_node = cNode.pc_parent_node;
    v_children = cNode.v_children;
    for (int i = 0; i < v_children.size(); i++) {
        v_children[i]->pc_parent_node = this;
    }

    return *this;
}

template <typename T>
void CNodeDynamic<T>::vAddNewChild() {
    v_children.push_back(new CNodeDynamic());
    v_children[v_children.size() - 1]->pc_parent_node = this;
}

template <typename T>
void CNodeDynamic<T>::vAddNewChild(T tVal) {
    v_children.push_back(new CNodeDynamic());
    v_children[v_children.size() - 1]->pc_parent_node = this;
    v_children[v_children.size() - 1]->t_val = tVal;
}

template <typename T>
bool CNodeDynamic<T>::bAddNewChild(CNodeDynamic<T> *pcNode) {
    if (pcNode->pc_parent_node != NULL)
        return false;
    v_children.push_back(pcNode);
    pcNode->pc_parent_node = this;
    return true;
}

template <typename T>
CNodeDynamic<T> *CNodeDynamic<T>::pcGetChild(int iChildOffset) {
    if (iChildOffset < 0 or iChildOffset > v_children.size() - 1)
        return NULL;

    return (v_children[iChildOffset]);
}

template <typename T>
CNodeDynamic<T> *CNodeDynamic<T>::pcDisconnect() {
    if (pc_parent_node == NULL)
        return this;

    typename std::vector<CNodeDynamic<T>*>::iterator i_it = pc_parent_node->v_children.erase(
            std::remove(pc_parent_node->v_children.begin(), pc_parent_node->v_children.end(), this),
            pc_parent_node->v_children.end());
    if (i_it != v_children.end()) {
        pc_parent_node = NULL;
        return this;
    } else
        return NULL;
}

template <typename T>
CNodeDynamic<T> *CNodeDynamic<T>::pcGetRoot() {
    if (pc_parent_node == NULL)
        return this;
    else return pc_parent_node->pcGetRoot();
}

template <typename T>
void CNodeDynamic<T>::vPrintUp() {
    vPrint();
    if (pc_parent_node != NULL)
        pc_parent_node->vPrintUp();
}

template <typename T>
void CNodeDynamic<T>::vPrintAllBelow() {
    vPrint();
    for (int i = 0; i < v_children.size(); i++)
        v_children[i]->vPrintAllBelow();
}

template <typename T>
void CNodeDynamic<T>::vPrintBetter(int iL) {
    for (int i = 0; i < iL; i++)
        std::cout << "  ";
    vPrintWithParent();
    for (int i = 0; i < v_children.size(); i++)
        v_children[i]->vPrintBetter(iL + 1);
}

template <typename T>
CTreeDynamic<T>::CTreeDynamic()
        : pc_root(new CNodeDynamic<T>()) {

}

template <typename T>
CTreeDynamic<T>::~CTreeDynamic() {
    delete pc_root;
}

template <typename T>
void CTreeDynamic<T>::vPrintTree() {
    pc_root->vPrintBetter(0);
}

template <typename T>
bool CTreeDynamic<T>::bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode) {
    if (pcNewChildNode == NULL or pcParentNode == NULL or
        b_same_tree(pcParentNode, pcNewChildNode) or
        pcParentNode->pcGetRoot() != pc_root or
        pcNewChildNode->pc_parent_node == NULL)
        return false;

    pcParentNode->bAddNewChild(pcNewChildNode->pcDisconnect());
    return true;
}

template <typename T>
bool b_same_tree(CNodeDynamic<T> *pcNode1, CNodeDynamic<T> *pcNode2) {
    return pcNode1->pcGetRoot() == pcNode2->pcGetRoot();
}
