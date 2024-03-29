#include "pch.h"
#include <iostream>
using namespace std;

struct List {
	double value;
	List* next;
};
List* start=NULL;
List* tail=NULL;

void push(double val);
void printAll();
double tmp = 0;

int main()
{
	push(23);
	tmp = tail->value;
	push(-12);
	push(9);
	push(7);
	printAll();
}

void push(double val) 
{
	if (start != NULL) 
	{
		tail->next = new List();
		tail->next->value = val;
		tail = tail->next;
		tail->next = NULL;
	}
		else 
		{
			start = new List();
			start->value = val;
			start->next = NULL;
			tail = start;
		}
}

void printAll()
{
	cout << "Data in the queue:\t";
	for (List* temp = start; temp != NULL; temp = temp->next)
	{
		cout << temp->value << "\t";
		if (temp->next != NULL)
		{
			if (temp->next->value < tmp)
				tmp = temp->next->value;
		}
	}
	cout <<"\nMin:\t"<< tmp << endl;
}

