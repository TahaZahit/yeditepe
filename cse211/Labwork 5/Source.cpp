#include <iostream>
#include <stdio.h>
#include <string>
#include "priority_queue.h"

using namespace std;
struct user
{
	string name;
	int priority;
}x;

int main() {
	PriorityQueue<string> pq;
	do
	{
		cout << "name:";
		cin >> x.name;
		cout << "priorty:";
		cin >> x.priority;

		if (x.priority == -1) break;

		pq.enqueue(x.name, x.priority);
		cout<< endl << pq<< endl;
	} while (x.priority);



	getchar();
}