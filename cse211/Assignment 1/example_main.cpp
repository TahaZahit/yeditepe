#include <iostream>
#include "Grades.h"
#include <string>
using namespace std;


int main() {
	Grades g("cse 211");

	g.add_grade(70);
	g.add_grade(20);
	g.add_grade(60);
	g.add_grade(101);
	g.add_grade(42);

	cout << "Maximum grade is: " << g.get_max() << endl;					// 70
	cout << "Minimum grade is: " << g.get_min() << endl;					// 20
	cout << "Average grade is: " << g.get_average() << endl;				// 48
	cout << "Number of grades: " << g.get_num_grades() << endl << endl;		// 4

	g.remove_all_grades();

	g.add_grade(15);
	g.add_grade(36);



	cout << "Maximum grade is: " << g.get_max() << endl;		// 36
	cout << "Minimum grade is: " << g.get_min() << endl;		// 15
	cout << "Average grade is: " << g.get_average() << endl;	// 25.5
	cout << "Number of grades: " << g.get_num_grades() << endl;	// 2

	int select;
	int not;
	string name;
	Grades *temp=NULL;

	while(true)
	{
		cout << "1) Create a classroom" << endl;
		cout << "2) Enter a grade" << endl;
		cout << "3) Show stats" << endl;
		cout << "4) Clear classroom" << endl;
		cout << "5) Exit" << endl;
		cin >> select;
		if(select==1)
		{
			delete temp;
			cout << "enter name:"<< endl;
			cin >> name;
			temp = new Grades(name);

		}
		else if (select == 2)
		{
			if (temp != NULL)
			{
				cout << "grade:";
				cin >> (int)not;
				temp->add_grade(not);
			}
				
		}
		else if (select == 3)
		{
			cout << "Maximum grade is: " << temp->get_max() << endl;		
			cout << "Minimum grade is: " << temp->get_min() << endl;		
			cout << "Average grade is: " << temp->get_average() << endl;	
			cout << "Number of grades: " << temp->get_num_grades() << endl;	
		}
		else if (select == 4)
		{
			temp->remove_all_grades();
		}
		else if (select == 5)
		{
			return 0;
		}
		else cout << "Wrong selection"<< endl;
	}
	

	getchar();
	return 0;
}