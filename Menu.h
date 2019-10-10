//
//  Author: Taylor Bauer
//  Date: October 7, 2019
//

#ifndef MENU_H
#define MENU_H
#include "BinarySearchTree.h"

//  This is the class that manages all the user interaction.
//  It has a member Binary Search Tree and only one function: run()
class Menu {
    public:

        //  Constructs a Menu object with a Binary Search Tree passed by value
        Menu(BinarySearchTree tree);

        //  Run the menu and all user interaction
        //  The program exits when this function is done.
        void run();
    private:
        BinarySearchTree m_tree;
};

#endif