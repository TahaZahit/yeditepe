#include <iostream>
#include "intSLList.h"
using namespace std;


class Grades
{
private:
	std::string courseName;
	IntSLList gradeList;
public:
	Grades(std::string name)
	{
		courseName = name;
	}
	void add_grade(int);
	int get_min();
	int get_max();
	double get_average();
	int get_num_grades();
	void remove_all_grades();

};