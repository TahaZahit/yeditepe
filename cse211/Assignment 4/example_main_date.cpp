#include <iostream>
#include "date.h"

int main(){

	date d1(17, 3, 2017);
	date d2(5, 2, 2017);

	std::cout <<
		"Time between " << d1.get_string() <<
		" and " << d2.get_string() << " is " << 
		d1.compare(d2) << " days\n";

	// Time between 17 March 2017 and 5 February 2017 is 40 days

	std::cout <<
		"Time between " << d2.get_string() <<
		" and " << d1.get_string() << " is " <<
		d2.compare(d1) << " days\n";

	// Time between 5 February 2017 and 17 March 2017 is -40 days


	d2.set_day(1);
	d2.set_month(11);
	d2.set_year(3229);

	std::cout << "Second date changed to " << d2.get_string() << std::endl;

	// Second date changed to 1 November 3229

	getchar();
	return 0;
}