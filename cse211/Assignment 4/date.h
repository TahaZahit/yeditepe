#pragma once

#include <string>

class date{
private:
	int day;
	int month;
	int year;

	int days_since_0() const;

public:
	date();
	date(int, int, int);

	void set_day(int);
	void set_month(int);
	void set_year(int);

	int get_day() const;
	int get_month() const;
	int get_year() const;

	std::string get_string() const;
	int compare(const date &) const;


};