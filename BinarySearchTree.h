#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include "BinaryNode.h"

class BinarySearchTree{
    public:
        BinarySearchTree();
        void insert(char value);
        bool isEmpty();
        void preorder();
        void inorder();
        void postorder();
        void levelOrder(bool leafFlag);
        int getHeight();
        bool search(char key);
        bool isLeaf(char key);

    private:
        BinaryNode* m_root;
        void insert(BinaryNode* root, BinaryNode* newNode);
        void preorder(BinaryNode* root);
        void inorder(BinaryNode* root);
        void postorder(BinaryNode* root);
        void levelOrder(bool leafFlag, BinaryNode* node, int level);
        int getHeight(BinaryNode* root);
        bool search(char key, BinaryNode* root);
        BinaryNode* searchReturnNode(char key, BinaryNode* root);

};

#endif