//
// Created by jesus on 5/30/2025.
//

#ifndef BSTNODE_H
#define BSTNODE_H

#include "DrachmaCurrency.h"

class BST;

class BSTNode {
public:
    BSTNode() =default;
    explicit BSTNode(Currency* newData) : data(newData) {};
    ~BSTNode() { delete data; }
    /**
    Method getData()
        -The point of this method is to safely retrieve the private of the class
        Pre:
        Post:
        Return: unsigned int data
    **/
    Currency* getData() {
        return data;
    }
    BSTNode* getRight() {
        return right;
    }
    BSTNode* getLeft() {
        return left;
    }
    /**
    Method setData(data)
        -The point of this method is to safely save into the private of the class
        Pre: data - the new data
        Post: data - new data is saved into data
        Return:
    **/
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
    Currency *data = nullptr;
    BSTNode *right=nullptr;
    BSTNode *left=nullptr;
};

#endif //BSTNODE_H
