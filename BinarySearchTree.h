//
//  Author: Taylor Bauer
//  Date: October 7, 2019
//


#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "BinaryNode.h"

//  This class is an ADT of type Binary Search Tree
class BinarySearchTree{
    public:

        //  Default constructor
        BinarySearchTree();

        //  Inserts a node onto the tree with the value passed as a parameter
        //  Follows the rules of a Binary Search Tree
        void insert(char value);

        //  Returns true if the tree is empty (if root does not exist)
        //  False otherwise
        bool isEmpty();

        //  Prints the tree, traversing in pre-order
        void preorder();

        //  Prints the tree, traversing in in-order
        //  When the leafFlag is set to true, it will only print the leaves
        void inorder(bool leafFlag);

        //  Prints the tree, traversing in post-order
        void postorder();

        //  Prints the tree, traversing in level-order
        //  When the leafFlag is set to true, it will only print the leaves
        void levelOrder(bool leafFlag);

        //  Returns the height of the tree
        int getHeight();

        //  Returns true if the key is found, false otherwise
        bool search(char key);

        //  Searches for a node with the indicated key
        //  If the node is found and is a leaf, it returns true
        //  Returns false otherwise
        bool isLeaf(char key);

        //  Removes the given node, appropriately reconstructing the tree afterwards
        //  TODO: This works for nodes with 0 or 1 children, but not yet 2
        void remove(char key);

    private:
        BinaryNode* m_root;

        //  The following are all recursive functions called by their associated function above
        void insert(BinaryNode* root, BinaryNode* newNode);
        void preorder(BinaryNode* root);
        void inorder(BinaryNode* root, bool leafFlag);
        void postorder(BinaryNode* root);
        void levelOrder(bool leafFlag, BinaryNode* node, int level);
        int getHeight(BinaryNode* root);
        bool search(char key, BinaryNode* root);
        bool remove(BinaryNode* root, char key);

        //  This searches for a node in the same way as search, except it returns a node pointer instead of a bool
        BinaryNode* searchReturnNode(char key, BinaryNode* root);

};

#endif