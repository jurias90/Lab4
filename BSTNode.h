//
// Created by jesus on 5/30/2025.
//

#ifndef BSTNODE_H
#define BSTNODE_H

#include "Currency.h"

struct BSTNode {
    BSTNode() =default;
    explicit BSTNode(Currency* newData) : data(newData) {};
    ~BSTNode() {}
    Currency *data=nullptr;
    BSTNode *right=nullptr;
    BSTNode *left=nullptr;
};

#endif //BSTNODE_H
