#include "bday.h"

bday::bday(std::string _name, const date & _birthdate)
{
	name = _name;
	birthdate = _birthdate;
}

std::string bday::get_name() const
{
	return std::string(name);
}

const date & bday::get_birthdate() const
{
	return birthdate;
}

void bday::set_name(std::string value)
{
	name = value;
}

void bday::set_birthday(const date & value)
{
	birthdate = value;
}

std::string bday::get_string() const
{
	
	return std::string(name+", "+birthdate.get_string());
}
