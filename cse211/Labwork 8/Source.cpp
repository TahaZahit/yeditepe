#include "heap.h"
#include <iostream>

using namespace std;

int main() {

	int data[] = { 13,10,9,12,55,23,34,1,2 };
	heap h(data,size(data));
	
	h.print();
	cout << endl;

	int i = 9;
	while (i) {
		h.delete_min();
		h.print();
		i--;
	}
	


	getchar();
	return 0;
}