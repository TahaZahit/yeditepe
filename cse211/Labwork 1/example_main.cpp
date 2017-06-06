#include <iostream>
#include "intSLList.h"
using namespace std;


int main() {

	IntSLList list;

	list.addToTail(2);
	list.addToTail(6);
	list.addToTail(5);
	list.addToTail(8);
	list.addToTail(5);
	list.addToTail(4);

	list.remove_even();
	list.printAll();		// 5 7 5
	list.duplicate_fives();
	list.printAll();		// 5 5 7 5 5
	list.addToTail(8);
	list.printAll();		// 5 5 7 5 5 8

	return 0;
}