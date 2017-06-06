#pragma once

#include <iostream>
#include <list>
#include "date.h"
#include "bday.h"

class calendar {
private:
	std::list<bday> bdaylist;

public:

	void add(const bday &);
	void remove(std::string);
	void print_incoming(const date &) const;
	void print() const;

};

