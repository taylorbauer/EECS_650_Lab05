#include "BinarySearchTree.h"
#include "BinaryNode.h"
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree() {
    m_root = nullptr;
}

void BinarySearchTree::insert(char value) {
    BinaryNode* newNode = new BinaryNode(value);
    if (isEmpty()) {
        m_root = newNode;
    }
    else {
        insert(m_root, newNode);
    }
    return;
}
void BinarySearchTree::insert(BinaryNode* root, BinaryNode* newNode) {
    if (newNode->getValue() < root->getValue()) {
        if (root->getLeft() == nullptr) {
            root->setLeft(newNode);
        }
        else {
            insert(root->getLeft(), newNode);
        }
    }
    else {
        if (root->getRight() == nullptr) {
            root->setRight(newNode);
        }
        else {
            insert(root->getRight(), newNode);
        }
    }
}

int BinarySearchTree::getHeight() {
    return getHeight(m_root);
}

int BinarySearchTree::getHeight(BinaryNode* root) {
    if (root == nullptr) {
        return 0;
    }
    else {
        int leftHeight = getHeight(root->getLeft());
        int rightHeight = getHeight(root->getRight());
        if (leftHeight > rightHeight) {
            return (leftHeight + 1);
        }
        else {
            return (rightHeight + 1);
        }
    }
}

void BinarySearchTree::preorder() {
    cout << "Printing in pre-order: ";
    preorder(m_root);
    cout << '\n';
}

void BinarySearchTree::preorder(BinaryNode* root) {
    if (root == nullptr) {
        return;
    }
    else {
        cout << root->getValue() << ' ';
        preorder(root->getLeft());
        preorder(root->getRight());
    }
}

void BinarySearchTree::inorder() {
    cout << "Printing in in-order: ";
    inorder(m_root);
    cout << '\n';
}

void BinarySearchTree::inorder(BinaryNode* root) {
    if (root == nullptr) {
        return;
    }
    else {
        inorder(root->getLeft());
        cout << root->getValue() << ' ';
        inorder(root->getRight());
    }
}

void BinarySearchTree::postorder() {
    cout << "Printing in post-order: ";
    postorder(m_root);
    cout << '\n';
}

void BinarySearchTree::postorder(BinaryNode* root) {
    if (root == nullptr) {
        return;
    }
    else {
        postorder(root->getLeft());
        postorder(root->getRight());
        cout << root->getValue() << ' ';
    }
}

void BinarySearchTree::levelOrder(bool leafFlag) {
    int height = getHeight(m_root);
    for (int i = 0; i < height; i++) {
        levelOrder(leafFlag, m_root, i);
    }
}

void BinarySearchTree::levelOrder(bool leafFlag, BinaryNode* node, int level) {
    if (node == nullptr) {
        return;
    }
    else if (level == 0) {
        if (leafFlag == true) {
            if (node->childrenCount() == 0) {
                cout << node->getValue() << ' ';
            }
        }
        else{
            cout << node->getValue() << ' ';
        }
    }
    else {
        levelOrder(leafFlag, node->getLeft(), level - 1);
        levelOrder(leafFlag, node->getRight(), level - 1);
    }
}

bool BinarySearchTree::isEmpty(){
    return (m_root == nullptr);
}
 
bool BinarySearchTree::search(char key) {
    return search(key, m_root);
}

bool BinarySearchTree::search(char key, BinaryNode* root) {
    if (root == nullptr) {
        return false;
    }
    if (root->getValue() == key) {
        return true;
    }
    else {
        if (search(key, root->getLeft())) {
            return true;
        }
        else {
            return search(key, root->getRight());
        }
        
    }
}