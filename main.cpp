#include <iostream>
#include "BST.h"
#include "DrachmaCurrency.h"

int main()
{
    BST *tree = new BST();
    tree->insert(new BSTNode(new DrachmaCurrency(57.12)));
    tree->insert(new BSTNode(new DrachmaCurrency(23.44)));
    tree->insert(new BSTNode(new DrachmaCurrency(87.43)));
    tree->insert(new BSTNode(new DrachmaCurrency(68.99)));
    tree->insert(new BSTNode(new DrachmaCurrency(111.22)));
    tree->insert(new BSTNode(new DrachmaCurrency(44.55)));
    tree->insert(new BSTNode(new DrachmaCurrency(77.77)));
    tree->insert(new BSTNode(new DrachmaCurrency(18.36)));
    tree->insert(new BSTNode(new DrachmaCurrency(345.67)));
    tree->insert(new BSTNode(new DrachmaCurrency(36.18)));
    tree->insert(new BSTNode(new DrachmaCurrency(48.48)));
    tree->insert(new BSTNode(new DrachmaCurrency(101.00)));
    tree->insert(new BSTNode(new DrachmaCurrency(11.00)));

    tree->print();
    return 0;
}
