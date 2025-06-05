#include <iostream>
#include <fstream>
#include "BST.h"
#include "DrachmaCurrency.h"

using namespace std;

void writeAllTraversals(BST* tree, ostream& os);
void printMenu();
bool isValidValue(double value);
DrachmaCurrency* getNewNodeFromInput(ostream& os);

int main()
{
    BST *tree = new BST();
    BSTNode* node = nullptr;
    DrachmaCurrency* newItem = nullptr;
    ofstream outFile("output.txt");
    if (!outFile) {
        cerr << "Failed to open output file.\n";
        return 1;
    }
    tree->insert(new DrachmaCurrency(57.12));
    tree->insert(new DrachmaCurrency(23.44));
    tree->insert(new DrachmaCurrency(87.43));
    tree->insert(new DrachmaCurrency(68.99));
    tree->insert(new DrachmaCurrency(111.22));
    tree->insert(new DrachmaCurrency(44.55));
    tree->insert(new DrachmaCurrency(77.77));
    tree->insert(new DrachmaCurrency(18.36));
    tree->insert(new DrachmaCurrency(345.67));
    tree->insert(new DrachmaCurrency(36.18));
    tree->insert(new DrachmaCurrency(48.48));
    tree->insert(new DrachmaCurrency(101.00));
    tree->insert(new DrachmaCurrency(11.00));

    // Initial Traversals
    cout << "Initial Traversals:\n";
    writeAllTraversals(tree, cout);
    writeAllTraversals(tree, outFile);

    // User interaction
    int choice;
    while (choice !=5) {
        printMenu();
        cin >> choice;

        try {
            switch (choice) {
            case 1: {
                // Insert
                newItem = getNewNodeFromInput(outFile);
                if (!newItem) {
                    continue;
                }
                BSTNode* found = tree->search(newItem);
                if (found) {
                    cout << "The item is already in the list"<< endl;
                    break;
                }
                tree->insert(newItem);
                cout << "Inserted.\n";
                break;
            }
            case 2: {  // Search
                newItem = getNewNodeFromInput(outFile);
                if (!newItem) {
                    continue;
                }
                BSTNode* found = tree->search(newItem);
                if (found) {
                    cout << "Found: " << found->getData()->toString() << endl;
                }
                else {
                    cout << "Not found.\n";
                }
                delete node;  // cleanup since not inserted
                break;
            }
            case 3:  // Delete
                newItem = getNewNodeFromInput(outFile);
                if (!newItem) {
                    continue;
                }
                tree->deleteNode(newItem);
                cout << "Deleted (if existed).\n";
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
        }
    }

    writeAllTraversals(tree, cout);
    writeAllTraversals(tree, outFile);

    outFile.close();
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

DrachmaCurrency* getNewNodeFromInput(ostream& os) {
    BSTNode* node = nullptr;
    DrachmaCurrency* dr = nullptr;
    double input;
    cout << "Enter Drachma value (e.g., 44.55): ";
    cin >> input;
    if (!isValidValue(input)) {
        cout << "Invalid input for operation: " << input << endl;
        os << "Invalid input for operation: " << input << endl;
        return nullptr;
    }
    dr = new DrachmaCurrency(input);
    return dr;
}