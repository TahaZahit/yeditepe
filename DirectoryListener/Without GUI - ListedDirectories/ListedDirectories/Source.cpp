#include "ListDir.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	ListDir list;
	string dir;
	int s;
	Info info;

	cout << "enter your directory: ";
	cin >> dir;
	list.Directory(dir);
	list.PrintByName();
	while (true)
	{
		/// TODO: addNode için bir seçenek eklenebilir.
		cout << "0-)Change directory" << endl;
		cout << "1-)Print by size" << endl;
		cout << "2-)Print by name" << endl;
		cout << "3-)Print by type" << endl;
		cout << "4-)Remove by size" << endl;
		cout << "5-)Remove by name" << endl;
		cout << "6-)Remove by type" << endl;
		cout << "7-)Search by size" << endl;
		cout << "8-)Search by name" << endl;
		cout << "9-)Search by type" << endl;
		cin >> s;
		switch (s)
		{
		case 0:
			list.RemoveAll();
			cout << "enter your directory: ";
			cin >> dir;
			list.Directory(dir);
			system("CLS");
		case 1:
			system("CLS");
			list.PrintBySize();
			break;
		case 2:
			system("CLS");
			list.PrintByName();
			break;
		case 3:
			system("CLS");
			list.PrintByType();
			break;
		case 4:
			cout << "enter size: ";
			cin >> info.size;
			list.RemoveBySize(info.size);
			system("CLS");
			list.PrintBySize();
			break;
		case 5:
			cout << "enter name: ";
			cin >> info.name;
			list.RemoveByName(info.name);
			system("CLS");
			list.PrintByName();
			break;
		case 6:
			cout << "enter type: ";
			cin >> info.type;
			list.RemoveByType(info.type);
			system("CLS");
			list.PrintByType();
			break;
		case 7:
			system("CLS");
			cout << "enter size: ";
			cin >> info.size;
			list.SearchBySize(info.size);
			break;
		case 8:
			system("CLS");
			cout << "enter name: ";
			cin >> info.name;
			list.SearchByName(info.name);
			break;
		case 9:
			system("CLS");
			cout << "enter type: ";
			cin >> info.type;
			list.SearchByType(info.type);
			break;
		default:
			break;
		}
		cout << endl << endl;
	}
}
