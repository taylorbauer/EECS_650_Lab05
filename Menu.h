#ifndef MENU_H
#define MENU_H
#include "BinarySearchTree.h"

class Menu {
    public:
        Menu(BinarySearchTree tree);
        void run();
    private:
        BinarySearchTree m_tree;
};

#endif