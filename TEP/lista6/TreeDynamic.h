//
// Created by Madatt on 15.11.2019.
//

#ifndef LISTA5_TREEDYNAMIC_H
#define LISTA5_TREEDYNAMIC_H

#include <iostream>
#include <vector>

template <typename T>
class CNodeDynamic
{
    template<typename U>
    friend class CTreeDynamic;
public:
    CNodeDynamic() {pc_parent_node = NULL;};
    CNodeDynamic(const CNodeDynamic<T>& cNode);
    ~CNodeDynamic();

    CNodeDynamic& operator=(const CNodeDynamic& cNode);

    void vSetValue(T tNewVal) {t_val = tNewVal;};
    int iGetChildrenNumber() {return(v_children.size());};
    void vAddNewChild();
    void vAddNewChild(T tVal);
    bool bAddNewChild(CNodeDynamic<T>* pcNode);
    CNodeDynamic<T> *pcGetChild(int iChildOffset);
    CNodeDynamic<T> *pcGetParent() {return pc_parent_node;};
    CNodeDynamic<T>* pcGetRoot();

    void vPrintWithParent() {std::cout << " " << t_val << "       ->       " << pc_parent_node << std::endl;};
    void vPrint() {std::cout << " " << t_val << std::endl;};
    void vPrintAllBelow();
    void vPrintUp();
    void vPrintBetter(int iL);
private:
    std::vector<CNodeDynamic<T>*> v_children;
    CNodeDynamic<T> *pc_parent_node;
    T t_val;

    CNodeDynamic<T>* pcDisconnect();
};


template <typename T>
class CTreeDynamic
{
public:
    CTreeDynamic();;
    ~CTreeDynamic();
    CNodeDynamic<T> *pcGetRoot() {return(pc_root);}
    void vPrintTree();

    bool bMoveSubtree(CNodeDynamic<T> *pcParentNode, CNodeDynamic<T> *pcNewChildNode);
private:

    CNodeDynamic<T> *pc_root;
};

template <typename T>
bool b_same_tree(CNodeDynamic<T>* pcNode1, CNodeDynamic<T>* pcNode2);

#include "TreeDynamic.tpp"


#endif //LISTA5_TREEDYNAMIC_H
