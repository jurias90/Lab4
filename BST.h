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

    ~BST() {
        empty();
    }

    void insert(BSTNode *newNode);

    BSTNode* search(BSTNode *node);

    void print() const;

    BSTNode* deleteNode(BSTNode *node);

    bool isEmpty() const{ return root == nullptr; }
    void destroyTree(BSTNode* node);
    void empty();
    void breadthFirst(std::ostream& os) const;
    void inOrder(std::ostream& os) const { inOrder(root, os); }
    void preOrder(std::ostream& os) const { preOrder(root, os); }
    void postOrder(std::ostream& os) const { postOrder(root, os); }

private:
    BSTNode *root;
    BSTNode* findLargest(BSTNode *parent) const{ return parent->right == nullptr ? parent : findLargest(parent->right); }
    BSTNode* findSmallest(BSTNode *parent) const{ return parent->left == nullptr ? parent : findSmallest(parent->left); }
    void rotateLeft();
    void rotateRight();
    void leftBalance();
    void rightBalance();
    void printNode(BSTNode *node,int tabulation) const;

    void inOrder(BSTNode* node, std::ostream& os) const;
    void preOrder(BSTNode* node, std::ostream& os) const;
    void postOrder(BSTNode* node, std::ostream& os) const;
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

inline void BST::destroyTree(BSTNode* node) {
    if (!node) return;
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}

inline void BST::empty() {
    destroyTree(root);
    root = nullptr;
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

inline void BST::breadthFirst(std::ostream& os) const {
    // TODO
}

inline void BST::inOrder(BSTNode* node, std::ostream& os) const {
    if (!node) return;
    inOrder(node->left, os);
    os << node->data->toString() << '\n';
    inOrder(node->right, os);
}

inline void BST::preOrder(BSTNode* node, std::ostream& os) const {
    if (!node) return;
    os << node->data->toString() << '\n';
    preOrder(node->left, os);
    preOrder(node->right, os);
}

inline void BST::postOrder(BSTNode* node, std::ostream& os) const {
    if (!node) return;
    postOrder(node->left, os);
    postOrder(node->right, os);
    os << node->data->toString() << '\n';
}

#endif //BST_H
