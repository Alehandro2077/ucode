#include <iostream>
#include "Student.h"

using namespace std;

int main()
{

	int students = 0;
	cout << "Input amount of students: ";
	cin >> students;
	Group gr;
	for (int i = 0; i < students; i++)
	{
		cin >> gr;
	}

	system("cls");

	cout << gr;
	cout << "\n\nSort test" << endl;
	gr.SortSt();
	cout << gr;

	cout << "Condition:\n";
	gr.Cond();

	cout << "Queue:\n";

	gr.Queue();
}