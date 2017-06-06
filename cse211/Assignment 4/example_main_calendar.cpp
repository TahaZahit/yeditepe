#include <iostream>
#include "calendar.h"
#include "date.h"
#include "bday.h"


int main() {

	calendar cal;
	cal.add(bday("John Doe", date(2, 5, 2017)));
	cal.add(bday("Jane Doe", date(13, 9, 2016)));
	cal.add(bday("Mr. Brown", date(21, 3, 1999)));

	cal.print();		// John Doe, 2 May 2017
						// Jane Doe, 13 September 2016
						// Mr.Brown, 21 March 1999

	std::cout << std::endl;
	cal.add(bday("Jane Doe", date(14, 9, 2016)));

	cal.print();		// John Doe, 2 May 2017
						// Jane Doe, 14 September 2016
						// Mr.Brown, 21 March 1999

	std::cout << std::endl;
	cal.remove("John Doe");

	cal.print();		// Jane Doe, 14 September 2016
						// Mr.Brown, 21 March 1999

	std::cout << std::endl;
	cal.remove("Some Guy");

	cal.print();		// Jane Doe, 14 September 2016
						// Mr.Brown, 21 March 1999

	std::cout << std::endl;
	cal.add(bday("New Person", date(11, 9, 2016)));
	cal.add(bday("Another Person", date(9, 9, 2016)));

	cal.print();		// Jane Doe, 14 September 2016
						// Mr.Brown, 21 March 1999
						// New Person, 11 September 2016
						// Another Person, 9 September 2016

	std::cout << std::endl;
	cal.print_incoming(date(10, 9, 2016));		// Jane Doe, 14 September 2016
												// New Person, 11 September 2016 
	return 0;
}