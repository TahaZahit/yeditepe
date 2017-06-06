#include <string>
#include <iostream>
using namespace std;
#include "genBST.h"

int main(){

	BST<std::string> tree;

	tree.insert("F");
	tree.insert("B");
	tree.insert("A");
	tree.insert("D");
	tree.insert("C");
	tree.insert("E");
	tree.insert("G");
	tree.insert("I");
	tree.insert("H");

	tree.printsmallerthan("F");		// A B C D E
	tree.printsmallerthan("D");		// A B C

	std::cout << tree.getnthelement(2) << std::endl;		// B
	std::cout << tree.getnthelement(7) << std::endl;		// G

	std::cout << tree.isbalanced() << std::endl;			// 0

}