//
// Created by Madatt on 15.11.2019.
//

#ifndef LISTA5_TREESTATIC_H
#define LISTA5_TREESTATIC_H

#include <vector>
#include <iostream>

class CTreeStatic
{
    class CNodeStatic
    {
    public:
        CNodeStatic() {i_val = 0; pc_parent_node = NULL;};
        CNodeStatic(const CNodeStatic& cNode);
        ~CNodeStatic();

        CNodeStatic& operator=(const CNodeStatic& cNode);
        bool operator==(const CNodeStatic& cNode) const;
        bool operator!=(const CNodeStatic& cNode);

        void vSetValue(int iNewVal) {i_val = iNewVal;};
        int iGetChildrenNumber() {return(v_children.size());};
        void vAddNewChild();
        void vAddNewChild(CNodeStatic pcNode);
        CNodeStatic *pcGetChild(int iChildOffset);
        CNodeStatic *pcGetParent() {return pc_parent_node;};
        CNodeStatic pcDisconnect();
        CNodeStatic* pcGetRoot();

        void vPrint() {std::cout << " " << i_val << std::endl;};
        void vPrintWithParent() {std::cout << " " << i_val << " " << pc_parent_node << std::endl;};
        void vPrintAllBelow();
        void vPrintUp();
        void vPrintBetter(int iL);

    private:
        std::vector<CNodeStatic> v_children;
        CNodeStatic *pc_parent_node;
        int i_val;
    };

public:
    CTreeStatic();
    CTreeStatic(CNodeStatic cNode);
    ~CTreeStatic();
    CNodeStatic *pcGetRoot() {return(&c_root);}
    void vPrintTree();

    bool bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode);

private:
    CNodeStatic c_root;
};

#endif //LISTA5_TREESTATIC_H
