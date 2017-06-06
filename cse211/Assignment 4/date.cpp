#include "date.h"


int date::days_since_0() const
{

	const int monthDays[12] = { 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };
	long int days = year * 365 + day;
	int years = year;
	for (int i = 0; i<month - 1; i++) days += monthDays[i];
	if (month <= 2) years--;
	days+= years / 4 - years / 100 + years / 400; // days+= count of leap years
	return days;
}



date::date()
{

	day = 0;
	month = 0;
	year = 0;
}

date::date(int d, int m, int y)
{	

	day = d;
	month = m;
	year = y;
}

void date::set_day(int value)
{
	day = value;
}

void date::set_month(int value)
{
	month = value;
}

void date::set_year(int value)
{
	year = value;
}

int date::get_day() const
{
	return day;
}

int date::get_month() const
{
	return month;
}

int date::get_year() const
{
	return year;
}

std::string date::get_string() const
{
	std::string _day=std::to_string(day);
	std::string _year=std::to_string(year);
	std::string _month;
	
	switch (month)
	{
	case 1:
		_month = "January";
		break;

	case 2:
		_month = "February";
		break;

	case 3:
		_month = "March";
		break;

	case 4:
		_month = "April";
		break;

	case 5:
		_month = "May";
		break;

	case 6:
		_month = "June";
		break;

	case 7:
		_month = "July";
		break;

	case 8:
		_month = "August";
		break;

	case 9:
		_month = "September";
		break;

	case 10:
		_month = "October";
		break;

	case 11:
		_month = "November";
		break;

	case 12:
		_month = "December";
		break;

	default:
		break;
	}
	
	return std::string(_day+" "+_month+" "+_year);
}

int date::compare(const date & d) const
{
	return days_since_0() - d.days_since_0();
}
