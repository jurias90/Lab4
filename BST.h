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

    void insert(Currency* newCurrency);

    BSTNode* search(Currency* currency);

    void print() const;

    BSTNode* deleteFromTree(Currency* data, BSTNode* parent);

    bool isEmpty() const{ return root == nullptr; }

private:
    BSTNode *root;
  //  BSTNode* deleteNode(BSTNode *node);
    // void rotateLeft();
    // void rotateRight();
    // void leftBalance();
    // void rightBalance();
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

// inline BSTNode* BST::deleteNode(BSTNode *node) {
//     BSTNode *current = root;
//     BSTNode *parent = nullptr;
//
//     while (current != nullptr) {
//         if(node->data->isEqual(*current->data)) {
//             if(current->right == nullptr && current->left == nullptr) {
//                 if(parent->left == current) {
//                     parent->left = nullptr;
//                 }else {
//                     parent->right = nullptr;
//                 }
//             }
//             else if(current->left ==nullptr) {
//                 BSTNode *smallest = current->right;
//                 parent = current;
//                 while(smallest->left != nullptr) {
//                     parent = smallest;
//                     smallest = smallest->left;
//                 }
//                 current->data = smallest->data;
//                 parent->left = nullptr;
//                 delete smallest;
//             }
//             else if(current->right ==nullptr) {
//                 BSTNode *largest = current->left;
//                 parent = current;
//                 while(largest->right != nullptr) {
//                     parent = largest;
//                     largest = largest->right;
//                 }
//                 current->data = largest->data;
//                 parent->right = nullptr;
//                 delete largest;
//             }
//             else {
//
//             }
//             return node;
//         }
//         parent = current;
//         if (node->data->isGreater(*current->data)) {
//             current = current->right;
//         } else {
//             current = current->left;
//         }
//     }
//     return nullptr;
// }

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
inline void BST::rotateLeft() {

}



#endif //BST_H
