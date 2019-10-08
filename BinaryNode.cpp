//
//  Author: Taylor Bauer
//  Date: September 28, 2019
//

#include "BinaryNode.h"

BinaryNode::BinaryNode(char value) {
    m_value = value;
    m_parent = nullptr;
    m_left = nullptr;
    m_right = nullptr;
}

int BinaryNode::childrenCount() {
    if (m_left == nullptr && m_right == nullptr) {
        return 0;
    }
    else if (m_left == nullptr ^ m_right == nullptr) {
        return 1;
    }
    else {
        return 2;
    }
}

void BinaryNode::setParent(BinaryNode* parent) {
    m_parent = parent;
}

bool BinaryNode::setLeft(BinaryNode* child) {
    if (m_left != nullptr) {
        return false;
    }
    else {
       m_left = child;
       child->setParent(this);
    }
    return true;
}

bool BinaryNode::setRight(BinaryNode* child) {
    if (m_right != nullptr) {
        return false;
    }
    else {
       m_right = child;
       child->setParent(this);
    }
    return true;
}

BinaryNode* BinaryNode::getLeft() {
    return m_left;
}
BinaryNode* BinaryNode::getRight() {
    return m_right;
}
BinaryNode* BinaryNode::getParent() {
    return m_parent;
}
char BinaryNode::getValue() {
    return m_value;
}
