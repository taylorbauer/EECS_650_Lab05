#include "Menu.h"
#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

Menu::Menu(BinarySearchTree tree) {
    m_tree = tree;
}

void Menu::run() {
    bool running = true;
    int selection = 0;
    cout << "\n\nWelcome!\n\n";
    while (running) {
        cout << "\n------------------------------------------------------------\n";
        cout << "Please choose one of the following commands:\n";
        cout << "1. AddItem\n";
        cout << "2. Delete\n";
        cout << "3. Leaf\n";
        cout << "4. PrintLeaf\n";
        cout << "5. TreeHeight\n";
        cout << "6. Preorder\n";
        cout << "7. Postorder\n";
        cout << "8. Inorder\n";
        cout << "9. LevelOrder\n";
        cout << "10. SearchItem\n";
        cout << "11. Exit\n";
        cout << "Your selection: ";
        cin >> selection;

        if (selection == 1) {
            char insertion = ' ';
            cout << "What value would you like to insert (single character only please)? ";
            cin >> insertion;
            m_tree.insert(insertion);
            cout << "The character \'" << insertion << "\' successfully inserted!\n";
        }
        else if (selection == 3) {
            char searchKey = ' ';
            cout << "Which node would you like to check (single character only please)? ";
            cin >> searchKey;
            if (m_tree.isLeaf(searchKey)) {
                cout << "The node containing \'" << searchKey << "\' IS a leaf.\n";
            }
            else {
                cout << "The node containing \'" << searchKey << "\' IS NOT a leaf.\n"; 
            }
        }
        else if (selection == 4) {
            cout << "Here are the leaf nodes from left to right:\n";
            m_tree.inorder(true);
            cout << endl;
        }
        else if (selection == 5) {
            cout << "The height of the tree is " << m_tree.getHeight() << ".\n";
        }
        else if (selection == 6) {
            m_tree.preorder();
        }
        else if (selection == 7) {
            m_tree.postorder();
        }
        else if (selection == 8) {
            m_tree.inorder(false);
        }
        else if (selection == 9) {
            m_tree.levelOrder(false);
        }
        else if (selection == 10) {
            char searchKey = ' ';
            cout << "What character would you like to search for? ";
            cin >> searchKey;
            if (m_tree.search(searchKey)) {
                cout << "The character \'" << searchKey << "\' was found on the tree\n";
            }
            else {
                cout << "The character \'" << searchKey << "\' was NOT found on the tree\n";
            }
        }
        else {
            running = false;
        }

    }
    cout << "\n\nGoodbye!\n\n";
}