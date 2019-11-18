//
// Created by Madatt on 15.11.2019.
//

#ifndef LISTA5_TREEDYNAMIC_H
#define LISTA5_TREEDYNAMIC_H

#include <iostream>
#include <vector>


class CTreeDynamic
{
    class CNodeDynamic
    {
    public:
        CNodeDynamic() {i_val = 0; pc_parent_node = NULL;};
        CNodeDynamic(const CNodeDynamic& cNode);
        ~CNodeDynamic();

        CNodeDynamic& operator=(const CNodeDynamic& cNode);

        void vSetValue(int iNewVal) {i_val = iNewVal;};
        int iGetChildrenNumber() {return(v_children.size());};
        void vAddNewChild();
        bool bAddNewChild(CNodeDynamic* pcNode);
        CNodeDynamic *pcGetChild(int iChildOffset);
        CNodeDynamic *pcGetParent() {return pc_parent_node;};
        CNodeDynamic* pcDisconnect();
        CNodeDynamic* pcGetRoot();

        void vPrintWithParent() {std::cout << " " << i_val << " " << pc_parent_node << std::endl;};
        void vPrint() {std::cout << " " << i_val << std::endl;};
        void vPrintAllBelow();
        void vPrintUp();
        void vPrintBetter(int iL);
    private:
        std::vector<CNodeDynamic *> v_children;
        CNodeDynamic *pc_parent_node;
        int i_val;
    };

public:
    CTreeDynamic();;
    ~CTreeDynamic();
    CNodeDynamic *pcGetRoot() {return(pc_root);}
    void vPrintTree();

    bool bMoveSubtree(CNodeDynamic *pcParentNode, CNodeDynamic *pcNewChildNode);
private:

    CNodeDynamic *pc_root;
};



#endif //LISTA5_TREEDYNAMIC_H
