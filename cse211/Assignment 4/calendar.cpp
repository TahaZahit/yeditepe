#include "calendar.h"

void calendar::add(const bday & value)
{
	for (std::list<bday>::iterator it = bdaylist.begin(); it !=bdaylist.end(); ++it)
	{
		if (it->get_name() == value.get_name())
		{

			it->set_birthday(value.get_birthdate());
			return;

		}
	}
	bdaylist.push_back(value);
}

void calendar::remove(std::string value)
{
	
	for (std::list<bday>::iterator it = bdaylist.begin(); it != bdaylist.end(); ++it)
		if (it->get_name() == value) {
			bdaylist.erase(it);
			return;
		}
}

void calendar::print_incoming(const date & current) const
{
	std::list<bday> x = bdaylist;
	int d;
	for(std::list<bday>::iterator it = x.begin();it!=x.end();it++)
	{
		d = (-1)*current.compare(it->get_birthdate());
		if ( d<= 7 &&d>0 )
			std::cout << it->get_string()<< std::endl;
	}
	
	
}

void calendar::print() const
{
	std::list<bday> x = bdaylist;
	for (std::list<bday>::iterator it = x.begin(); it!= x.end(); it++)
	{
		std::cout << it->get_string()<< std::endl;
	}

}
