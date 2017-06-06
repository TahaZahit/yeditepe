#include <iostream>
#include "Grades.h"

using namespace std;


void Grades::add_grade(int value)
{
	if(value<=100 && value >=0)
		gradeList.addToTail(value);
}

int Grades::get_min()
{
	if (gradeList.head == NULL) return NULL;
	int min = gradeList.head->info;
	IntSLLNode * current = gradeList.head->next;

	while (current!=NULL)
	{
		if (current->info < min) min = current->info;
		current = current->next;
	}
	return min;
}
int Grades::get_max()
{
	if (gradeList.head == NULL) return NULL;
	int max = gradeList.head->info;
	IntSLLNode * current = gradeList.head->next;

	while (current != NULL)
	{
		if (current->info > max) max = current->info;
		current = current->next;
	}
	return max;
}
double Grades::get_average()
{
	if (gradeList.head == NULL) return 0;
	double sum = gradeList.head->info;
	int n = 1;
	IntSLLNode * current = gradeList.head->next;
	while (current!=NULL)
	{
		sum += current->info;
		n++;
		current = current->next;

	}
	return sum / n;
	
}
int Grades::get_num_grades()
{
	if (gradeList.head == NULL) return 0;
	int n = 1;
	IntSLLNode * current = gradeList.head->next;
	while (current != NULL)
	{
		n++;
		current = current->next;

	}
	return  n;
}
void Grades::remove_all_grades()
{
	while (gradeList.head!=NULL)
	{
		gradeList.deleteFromHead();
	}
}

