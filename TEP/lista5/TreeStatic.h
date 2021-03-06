//
// Created by Madatt on 15.11.2019.
//

#ifndef LISTA5_TREESTATIC_H
#define LISTA5_TREESTATIC_H

#include <vector>
#include <iostream>

<<<<<<< HEAD
class CNodeStatic
{
public:
    CNodeStatic() {i_val = 0; pc_parent_node = NULL;};
    CNodeStatic(const CNodeStatic& cNode);
    ~CNodeStatic();

    CNodeStatic& operator=(const CNodeStatic& cNode);
    bool operator==(const CNodeStatic& cNode);

    void vSetValue(int iNewVal) {i_val = iNewVal;};
    int iGetChildrenNumber() {return(v_children.size());};
    void vAddNewChild();
    void vAddNewChild(CNodeStatic pcNode);
    CNodeStatic *pcGetChild(int iChildOffset);
    CNodeStatic *pcGetParent() {return pc_parent_node;};
    CNodeStatic pcDisconnect();
    CNodeStatic* pcGetRoot();

    void vPrint() {std::cout << " " << i_val << std::endl;};
    void vPrintWithParent() {std::cout << " " << i_val << "|" << pc_parent_node << std::endl;};
    void vPrintAllBelow();
    void vPrintUp();
    void vPrintBetter(int iL);

private:
    std::vector<CNodeStatic> v_children;
    CNodeStatic *pc_parent_node;
    int i_val;
};

=======
>>>>>>> c39a600e367a5e2e27cff570000e8904dd24acf2
class CTreeStatic
{
public:
    class CNodeStatic
    {
        friend class CTreeStatic;

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
        CNodeStatic* pcGetRoot();

        void vPrint() {std::cout << " " << i_val << std::endl;};
        void vPrintWithParent() {std::cout << " " << i_val << "       ->       " << pc_parent_node << std::endl;};
        void vPrintAllBelow();
        void vPrintUp();
        void vPrintBetter(int iL);

    private:
        std::vector<CNodeStatic> v_children;
        CNodeStatic *pc_parent_node;
        int i_val;

        CNodeStatic pcDisconnect();
    };


    CTreeStatic();
    CTreeStatic(CNodeStatic cNode);
    ~CTreeStatic();
    CNodeStatic *pcGetRoot() {return(&c_root);}
    void vPrintTree();

    bool bMoveSubtree(CNodeStatic *pcParentNode, CNodeStatic *pcNewChildNode);

private:
    CNodeStatic c_root;
};


bool b_same_tree(CTreeStatic::CNodeStatic *pcNode1, CTreeStatic::CNodeStatic *pcNode2);

#endif //LISTA5_TREESTATIC_H
