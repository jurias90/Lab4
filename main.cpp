#include <iostream>
#include <fstream>
#include "BST.h"
#include "DrachmaCurrency.h"

using namespace std;

void writeAllTraversals(BST* tree, ostream& os);
void printMenu();
bool isValidValue(double value);
BSTNode* getNewNodeFromInput(ostream& os);

int main()
{
    BST *tree = new BST();
    BSTNode* node = NULL;
    ofstream outFile("output.txt");
    if (!outFile) {
        cerr << "Failed to open output file.\n";
        return 1;
    }
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

    // Initial Traversals
    cout << "Initial Traversals:\n";
    writeAllTraversals(tree, cout);
    writeAllTraversals(tree, outFile);

    // User interaction
    int choice;
    while (true) {
        printMenu();
        cin >> choice;

        if (choice == 5) break;

        try {
            switch (choice) {
            case 1:  // Insert
                node = getNewNodeFromInput(outFile);
                if (!node) {
                    continue;
                }
                tree->insert(node);
                cout << "Inserted.\n";
                outFile << "Inserted: " << node->getData()->toString() << endl;
                break;
            case 2: {  // Search
                node = getNewNodeFromInput(outFile);
                if (!node) {
                    continue;
                }
                BSTNode* found = tree->search(node);
                if (found) {
                    cout << "Found: " << found->getData() << endl;
                    outFile << "Found: " << found->getData() << endl;
                }
                else {
                    cout << "Not found.\n";
                    outFile << "Not found: " << node->getData()->toString() << endl;
                }
                delete node;  // cleanup since not inserted
                break;
            }
            case 3:  // Delete
                node = getNewNodeFromInput(outFile);
                if (!node) {
                    continue;
                }
                tree->deleteNode(node);
                cout << "Deleted (if existed).\n";
                outFile << "Deleted (if existed): " << node->getData()->toString() << endl;
                delete node; // cleanup since not inserted
                break;
            case 4:  // Print traversals
                writeAllTraversals(tree, cout);
                writeAllTraversals(tree, outFile);
                break;
            default:
                cout << "Invalid option." << endl;
                break;
            }

        }
        catch (string& err) {
            cout << "Error: " << err << endl;
            outFile << "Error: " << err << endl;
        }
    }

    writeAllTraversals(tree, cout);
    writeAllTraversals(tree, outFile);

    outFile.close();

    tree->print();
    delete tree;
    return 0;
}

void writeAllTraversals(BST* tree, ostream& os) {
    os << "\nBreadth-First:\n"; tree->breadthFirst(os);
    os << "\nIn-Order:\n"; tree->inOrder(os);
    os << "\nPre-Order:\n"; tree->preOrder(os);
    os << "\nPost-Order:\n"; tree->postOrder(os);
}

void printMenu() {
    cout << "\nOptions:\n";
    cout << "1. Insert\n";
    cout << "2. Search\n";
    cout << "3. Delete\n";
    cout << "4. Print Traversals\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

bool isValidValue(double value) {
    return value >= 0;
}

BSTNode* getNewNodeFromInput(ostream& os) {
    BSTNode* node = NULL;
    DrachmaCurrency* dr = NULL;
    double input;
    cout << "Enter Drachma value (e.g., 44.55): ";
    cin >> input;
    if (!isValidValue(input)) {
        cout << "Invalid input: must be >= 0\n";
        os << "Invalid input for operation: " << input << endl;
        return NULL;
    }
    dr = new DrachmaCurrency(input);
    node = new BSTNode(dr);
    return node;
}