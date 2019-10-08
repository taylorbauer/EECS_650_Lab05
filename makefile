Lab05: main.o Menu.o BinarySearchTree.o BinaryNode.o
	g++ -std=c++11 main.o Menu.o BinarySearchTree.o BinaryNode.o -o Lab05
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
Menu.o: Menu.cpp Menu.h
	g++ -std=c++11 -c Menu.cpp
BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h
	g++ -std=c++11 -c BinarySearchTree.cpp
BinaryNode.o: BinaryNode.cpp BinaryNode.h
	g++ -std=c++11 -c BinaryNode.cpp

clean:
	rm -f test *.o