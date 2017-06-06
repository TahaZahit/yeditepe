#include <iostream>
#include "genDLList.h"
using namespace std;


int main() {

	DoublyLinkedList<int> A;
	DoublyLinkedList<int> B;
	DoublyLinkedList<int> * C;

	A.addToDLLTail(5);
	A.addToDLLTail(8);
	A.addToDLLTail(2);
	A.addToDLLTail(4);

	B.addToDLLTail(6);
	B.addToDLLTail(7);
	B.addToDLLTail(11);
	B.addToDLLTail(0);

	A.append(B);

	cout << A << endl;		// 5 8 2 4 6 7 11 0
	cout << B << endl;		// 6 7 11 0

	A.addToDLLTail(15);
	C = A.split();

	cout << A << endl;		// 5 8 2 4 6
	cout << *C << endl;		// 7 11 0 15


	getchar();

	return 0;
}