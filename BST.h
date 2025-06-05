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
    /**
    Method insert(new currency)
        -This method will add a new node to the tree and reject it if it is already in the tree
        Pre: node - the node to be added
        Post: parent->left - the node from where the new node will be added if it is smaller then the parent.
             parent->right - the node from where the new node will be added if it is bigger then the parent.
             root - it will save onto this node if the tree is empty.
        Return:
    **/
    void insert(Currency *target);
    /**
    Method search(currency)
        -This method will search for a value to see if it exists
        Pre: currency - the node to be added
        Post:
        Return: foundNode - it will return a node if it has the same value
    **/
    BSTNode* search(Currency *target);
    /**
    Method print()
        -This method will take the data from the node and print it to the console.
        Pre:
        Post:
        Return:
    **/
    void print() const;
    /**
    Method deleteNode(target)
        -deleteNode will take a value and find it in the tree, and delete it.
        Pre: target - the currency that is being looked for.
        Post:parent->left - the node from where the new node will be deleted if it is smaller then the parent.
             parent->right - the node from where the new node will be deleted if it is bigger then the parent.
             root - it will delete  this node if the tree is in the tree.
        Return:
    **/
    void deleteNode(Currency *target);
    /**
    Method isEmpty()
        -This method checks to see if the tree is empty.
        Pre:
        Post:
        Return:true or false
    **/
    bool isEmpty() const{ return root == nullptr; }
    /**
    Method empty()
        -This method will delete the entire tree
        Pre:
        Post:root - will completely delete the node and every node attached to it.
        Return:
    **/
    void empty();
    //Traversal Functions
    //These were made to keep the root unaccessible to the user and call the private function instead with  given root.
    /**
    Algorithm breadthFirst(outputStream)
        -This algorithm searches traverses the tree in breadth first order and prints out the data to the stream given
        Pre:outputStream - the given ostream to stream the data to
        Post: node - its data will be access and printed out
        Return:
    **/
    void breadthFirst(std::ostream& os) const;
    /**
    Algorithm inOrder(outputStream)
        -This algorithm searches traverses the tree in order from smallest to biggest and prints out to the given ostream
        Pre:outputStream - the given ostream to stream the data to
        Post: node - its data will be access and printed out
        Return:
    **/
    void inOrder(std::ostream& os) const { inOrder(root, os); }
    /**
    Algorithm preOrder(outputStream)
        -This algorithm searches traverses the tree pre order from smallest to biggest and prints out to the given ostream
        Pre:outputStream - the given ostream to stream the data to
        Post: node - its data will be access and printed out
        Return:
    **/
    void preOrder(std::ostream& os) const { preOrder(root, os); }
    /**
    Algorithm postOrder(outputStream)
        -This algorithm searches traverses the tree post order from smallest to biggest and prints out to the given ostream
        Pre:outputStream - the given ostream to stream the data to
        Post: node - its data will be access and printed out
        Return:
    **/
    void postOrder(std::ostream& os) const { postOrder(root, os); }
private:
    BSTNode *root;
     //Recursive functions
    /**
    Algorithm removeVal(node,target)
        -This recursive algorithm calls itself to delete the correct node and save the new node to root to balance
        Pre:node - the current node in check
            target - the value for deletion
        Post: current-> the data that will be deleted
              root - New data will be saved into the root upon deletion
        Return:
    **/
    BSTNode* removeVal(BSTNode *node, const Currency *target);
    /**
    Method printNode(node, tabulation)
        -This recursive function will find the nodes in the tree and print it sideways
        Pre: node - the node for traversal and access to data
            tabulation - the amount of tabs needed to keep an image of the tree
        Post:
        Return:
    **/
    void printNode(BSTNode *node,int tabulation) const;
    //The Recursive Traversal Functions
    void inOrder(BSTNode* node, std::ostream& os) const;
    void preOrder(BSTNode* node, std::ostream& os) const;
    void postOrder(BSTNode* node, std::ostream& os) const;
    void destroyTree(BSTNode* node);
};


inline void BST::insert(Currency* target) {
    BSTNode *newNode = new BSTNode(target);
    if (root == nullptr) {
        root = newNode;
    } else {
        BSTNode *current = root;
        BSTNode *parent = nullptr;
        while (current != nullptr) {
            parent = current;
            if (newNode->data->isEqual(*current->data)) {
                return;
            }
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

inline BSTNode* BST::search(Currency* target) {
    BSTNode *current = root;
    BSTNode *node = new BSTNode(target);
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
inline void BST::deleteNode(Currency *target) {
    BSTNode *current = search(target);
    if (current == nullptr) {
        return;
    }
    root = removeVal(root, target);
}

inline BSTNode* BST::removeVal(BSTNode* node, const Currency* target) {
    if (!node) return nullptr;

    if (node->data->isGreater(*target))
        node->left = removeVal(node->left, target);
    else if (target->isGreater(*node->data))
        node->right = removeVal(node->right, target);
    else {
        // Case: 0 or 1 child
        if (!node->left) {
            BSTNode* temp = node->right;
            delete node;
            return temp;
        }
         if (!node->right) {
            BSTNode* temp = node->left;
            delete node;
            return temp;
        }

        // Case: 2 children - find inorder successor (smallest in right subtree)
        BSTNode* minNode = node->right;
        while (minNode->left)
            minNode = minNode->left;
        // free node data
        delete node->data;
        node->setData(new DrachmaCurrency(minNode->data));
        node->right = removeVal(node->right, minNode->data);  // Delete duplicate node
    }

    return node;
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
    if(!root) return;
    //I choose size of 100, not because I thought we would use that many points in the array
    //but mostly due to paranoia. I know it will be 8 at most.
    int size = 100,front = 0, rear = 0;
    //I had a problem coming up with an idea of how to use a queue without creating an entire new linked list
    //so I decided to make my ADT from an array and treat it like a queue.
    BSTNode **queue = new BSTNode*[size];
    queue[rear++] = root;
    while(front < rear) {
        BSTNode *current = queue[front++];
        os << current->data->toString() << std::endl;

        // resize queue
        if(rear + 2 >= size) {
            size *= 2;
            BSTNode **newQueue = new BSTNode*[size];
            for(int i=0;i<rear;i++) {
                newQueue[i] = queue[i];
            }
            delete[] queue;
            queue = newQueue;
        }

        if(current->left != nullptr) {
            queue[rear++] = current->left;
        }
        if(current->right != nullptr) {
            queue[rear++] = current->right;
        }
    }

    delete[] queue;
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
