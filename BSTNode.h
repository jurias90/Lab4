//
// Created by jesus on 5/30/2025.
//

#ifndef BSTNODE_H
#define BSTNODE_H

#include "Currency.h"

class BST;

class BSTNode {
public:
    BSTNode() =default;
    explicit BSTNode(Currency* newData) : data(newData) {};
    ~BSTNode() { delete data; }
    Currency* getData() {
        return data;
    }
    BSTNode* getRight() {
        return right;
    }
    BSTNode* getLeft() {
        return left;
    }
    void setData(Currency* data) {
        this->data = data;
    }
    void setRight(BSTNode* node) {
        right = node;
    }
    void setLeft(BSTNode* node) {
        left = node;
    }

    friend class BST;
private:
    Currency *data=nullptr;
    BSTNode *right=nullptr;
    BSTNode *left=nullptr;
};

#endif //BSTNODE_H
