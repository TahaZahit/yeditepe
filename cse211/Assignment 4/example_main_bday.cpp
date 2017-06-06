#include <iostream>
#include "date.h"
#include "bday.h"

int main() {

	bday b1("Test Subject", date(24, 11, 1971));

	std::cout << b1.get_string() << std::endl;		//	Test Subject, 24 November 1971

	b1.set_name("John Doe");

	std::cout << b1.get_string() << std::endl;		//	John Doe, 24 November 1971

	b1.set_birthday(date(7, 6, 1980));

	std::cout << b1.get_string() << std::endl;		//	John Doe, 7 June 1980

	getchar();
	return 0;
}