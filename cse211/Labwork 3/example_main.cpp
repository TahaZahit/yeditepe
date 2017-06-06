#include <iostream>
#include <string>
#include "genDLList.h"
using namespace std;


bool is_palindrome(const string & el)
{
	DoublyLinkedList<char> s;
	
	for (int i = 0; i < el.size(); i++)s.push(el[i]);


	for (int i = 0; i < el.size(); i++)
	{
		if (el[i] != s.top()) return false;
		s.pop();
	}
	return true;
}


int main() {

	cout << is_palindrome("ey edip adanada pide ye") << endl;		// 1
	cout << is_palindrome("test") << endl;							// 0
	cout << is_palindrome("mum") << endl;							// 1
	getchar();

	return 0;
}