#pragma once

#include "date.h"
#include <string>


class bday {
private:
	std::string name;
	date birthdate;

public:

	bday(std::string, const date &);
	
	std::string get_name() const;
	const date & get_birthdate() const;

	void set_name(std::string);
	void set_birthday(const date &);

	std::string get_string() const;
};