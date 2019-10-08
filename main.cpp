//
//  Author: Taylor Bauer
//  Date: October 7, 2019
//

#include <iostream>
#include <fstream>
#include "Menu.h"
#include "BinarySearchTree.h"
#include "BinaryNode.h"
using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 2) {
        cout << "\nPlease make sure you are including a filename in the command line!\n";
        cout << "Ex: ./Lab05 data.txt\n\n";
        return 0;
    }

    fstream myFile;
    myFile.open(argv[1]);

    if (!myFile) {
        cout << "\nError opening file! Please make sure it is a valid file and try again.\n\n";
        return 0;
    }
    else {
        cout << "\nSuccessfully opened file.\n\n";
    }

    int valueCount = 0;
    char currentValue = ' ';
    while (!myFile.eof()){
        myFile >> currentValue;
        valueCount ++;
    }

    myFile.close();
    myFile.open(argv[1]);

    char* tempArr = new char[valueCount];
    for (int i; i < valueCount; i++) {
        myFile >> tempArr[i];
    }
    myFile.close();

    BinarySearchTree myTree;
    for (int i; i < valueCount; i++) {
       myTree.insert(tempArr[i]);
    }

    Menu mainMenu(myTree);
    mainMenu.run();

    delete[] tempArr;
    return 0;
}