//
// Created by jesus on 5/30/2025.
//

#ifndef BST_H
#define BST_H
#include "BSTNode.h"
#include "Queue.h"


class BST {
public:
    BST(): root(nullptr) {
    };
    ~BST();
    void insert(Currency* newCurrency);
    BSTNode* search(Currency* currency);
    void print() const;
    BSTNode* deleteFromTree(Currency* data, BSTNode* parent);
    bool isEmpty() const{ return root == nullptr; }
    void traverseBreath(Queue *list, BSTNode *node);
    void traverseInorder(Queue* list, BSTNode* node);
    void traversePreorder(Queue* list, BSTNode* node);
    void traversePostorder(Queue* list,BSTNode* node);

private:
    BSTNode *root;
    void printNode(BSTNode *node,int tabulation) const;
};

inline void BST::insert(Currency* newCurrency) {
    BSTNode *newNode = new BSTNode(newCurrency);
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

inline BSTNode* BST::search(Currency* currency) {
    BSTNode *current = root;
    while (current != nullptr) {
        if(currency->isEqual(*current->data)) {
            return current;
        }
        if (currency->isGreater(*current->data)) {
            current = current->right;
        } else {
            current = current->left;
        }
    }
    return nullptr;
}

inline BSTNode* BST::deleteFromTree(Currency* data, BSTNode *newRoot = nullptr) {
    if(root == nullptr) {
        return nullptr;
    }
    if(newRoot == nullptr) {
        newRoot = root;
    }
    if(data->isGreater(*newRoot->data)) {
        std::cout << "Entering the Right Branch" << std::endl;
        newRoot->right = deleteFromTree(data, newRoot->right);
    }else if(newRoot->data->isGreater(*data)) {
        std::cout << "Entering the Left Branch" << std::endl;
        newRoot->left = deleteFromTree(data, newRoot->left);
    }else {
        if(newRoot->left == nullptr) {
            return newRoot->right;
        }
        if(newRoot->right == nullptr) {
            return newRoot->left;
        }
        BSTNode *current = newRoot->right;
        while (current->left != nullptr) {
            current = current->left;
        }
        newRoot->data = current->data;
        newRoot->right = deleteFromTree(newRoot->data, newRoot->right);
    }
    return newRoot;
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

inline void BST::traverseBreath(Queue* list, BSTNode *node = nullptr) {
    if(root == nullptr) {
        return;
    }
    if(node != nullptr) {
        node = root;
    }

}

inline void BST::traverseInorder(Queue* list, BSTNode *node = nullptr) {
    if(root == nullptr) {
        return;
    }
    if(node != nullptr) {
        node = root;
    }
    traverseBreath(list, node->left);
    list->enqueue(node->data);
    traverseBreath(list, node->right);
}
inline void BST::traversePreorder(Queue* list, BSTNode *node = nullptr) {
    if(root == nullptr) {
        return;
    }
    if(node != nullptr) {
        node = root;
    }
    list->enqueue(node->data);
    traverseBreath(list, node->left);
    traverseBreath(list, node->right);
}

inline void BST::traversePostorder(Queue* list, BSTNode *node = nullptr) {
    if(root == nullptr) {
        return;
    }
    if(node != nullptr) {
        node = root;
    }
    traverseBreath(list, node->left);
    traverseBreath(list, node->right);
    list->enqueue(node->data);
}




#endif //BST_H
