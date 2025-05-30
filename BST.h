//
// Created by jesus on 5/30/2025.
//

#ifndef BST_H
#define BST_H
#include "BSTNode.h"


class BST {
public:
    BST(): root(nullptr) {
    };

    ~BST();

    void insert(BSTNode *newNode);

    BSTNode* search(BSTNode *node);

    void print() const;

    BSTNode* deleteNode(BSTNode *node);

    bool isEmpty() const{ return root == nullptr; }

private:
    BSTNode *root;
    BSTNode* findLargest(BSTNode *parent) const{ return parent->right == nullptr ? parent : findLargest(parent->right); }
    BSTNode* findSmallest(BSTNode *parent) const{ return parent->left == nullptr ? parent : findSmallest(parent->left); }
    void rotateLeft();
    void rotateRight();
    void leftBalance();
    void rightBalance();
    void printNode(BSTNode *node,int tabulation) const;
};

inline void BST::insert(BSTNode *newNode) {
    if (root == nullptr) {
        root = newNode;
    } else {
        BSTNode *current = root;
        BSTNode *parent = nullptr;
        while (current != nullptr) {
            parent = current;
            if (newNode->data->isGreater(*current->data)) {
                current = parent->right;
            } else {
                current = parent->left;
            }
        }
        if (newNode->data->isGreater(*parent->data)) {
            parent->right = newNode;

        } else {
            parent->left = newNode;

        }
    }
}

inline BSTNode* BST::search(BSTNode *node) {
    BSTNode *current = root;
    while (current != nullptr) {
        if(node->data->isEqual(*current->data)) {
            return current;
        }
        if (node->data->isGreater(*current->data)) {
            current = current->right;
        } else {
            current = current->left;
        }
    }
    return nullptr;
}
inline BSTNode* BST::deleteNode(BSTNode *node) {
    BSTNode *current = search(node);
    if (current == nullptr) {
        return nullptr;
    }

}

inline void BST::print() const{
    if(root == nullptr) {
        return;
    }
    if(root->left != nullptr) {
        printNode(root->left,1);

    }
    root->data->print();
    std::cout << std::endl;
    if(root->right != nullptr) {
        printNode(root->right,1);
    }
}
inline void BST::printNode(BSTNode *node,int tabulation) const {
    if(node->left != nullptr) {
        printNode(node->left,tabulation+1);
    }
    for(int i=0;i<tabulation;i++) {
        std::cout << "\t";
    }
    node->data->print();
    std::cout << std::endl;
    if(node->right != nullptr) {
        printNode(node->right,tabulation+1);
    }
}


#endif //BST_H
