//
//  Author: Taylor Bauer
//  Date: September 28, 2019
//

#ifndef BINARY_NODE_H
#define BINARY_NODE_H

class BinaryNode{
public:

    //  Basic constructor
    BinaryNode(char value);

    //  Returns the number of children that the node has
    int childrenCount();

    //  Returns pointers to various family  nodes
    BinaryNode* getParent();
    BinaryNode* getLeft();
    BinaryNode* getRight();

    void setParent(BinaryNode* parent);
    bool setLeft(BinaryNode* child);
    bool setRight(BinaryNode* child);

    //  Returns the value of the node
    char getValue();

private:
    char m_value;
    BinaryNode* m_parent;
    BinaryNode* m_left;
    BinaryNode* m_right;
};


#endif