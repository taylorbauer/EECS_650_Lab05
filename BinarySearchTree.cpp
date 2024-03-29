//
//  Author: Taylor Bauer
//  Date: October 7, 2019
//


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

void BinarySearchTree::inorder(bool leafFlag) {
    cout << "Printing in in-order: ";
    inorder(m_root, leafFlag);
    cout << '\n';
}

void BinarySearchTree::inorder(BinaryNode* root, bool leafFlag) {
    if (root == nullptr) {
        return;
    }
    else {
        inorder(root->getLeft(), leafFlag);
        if (leafFlag == false || root->childrenCount() == 0){
            cout << root->getValue() << ' ';
        }
        inorder(root->getRight(), leafFlag);
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

BinaryNode* BinarySearchTree::searchReturnNode(char key, BinaryNode* root) {
    if (root->getValue() == key) {
        return root;
    }
    else {
        if (root->getLeft() != nullptr){
            BinaryNode* leftResult = searchReturnNode(key, root->getLeft());
            if (leftResult != nullptr) {
                return leftResult;
            }
            else {
                if (root->getRight() != nullptr) {
                    BinaryNode* rightResult = searchReturnNode(key, root->getRight());
                    if (rightResult != nullptr) {
                        return rightResult;
                    }
                }
            }
        }
        return nullptr;
    }
}

bool BinarySearchTree::isLeaf(char key) {
    if (!search(key, m_root)) {
        return false;
    }
    else {
        BinaryNode* nodeInQuestion = searchReturnNode(key, m_root);
        if (nodeInQuestion->childrenCount() == 0) {
            return true;
        }
        else {
            return false;
        }
    }
}

void BinarySearchTree::remove(char key) {
    remove(m_root, key);
}

bool BinarySearchTree::remove(BinaryNode* root, char key) {
    BinaryNode* toBeDeleted = searchReturnNode(key, m_root);
    BinaryNode* nonEmptyChild = nullptr;
    if (isLeaf(key) && toBeDeleted != m_root) {
        if (toBeDeleted->getParent()->getLeft() == toBeDeleted) {
            toBeDeleted->getParent()->setLeft(nullptr);
        }
        else {
            toBeDeleted->getParent()->setRight(nullptr);
        }
        delete toBeDeleted;
    }
    else if (toBeDeleted->childrenCount() == 1 && toBeDeleted != m_root) {
        if (toBeDeleted->getRight() == nullptr) {
            nonEmptyChild = toBeDeleted->getLeft();
        }
        else {
            nonEmptyChild = toBeDeleted->getRight();
        }
        if (toBeDeleted->getParent()->getLeft() == toBeDeleted) { //AKA, toBeDeleted is the left child of its parent
            toBeDeleted->getParent()->setLeft(nonEmptyChild);
        }
        else {
            toBeDeleted->getParent()->setRight(nonEmptyChild);
        }
        nonEmptyChild->setParent(toBeDeleted->getParent());
        delete toBeDeleted;
    }
    return true;
}