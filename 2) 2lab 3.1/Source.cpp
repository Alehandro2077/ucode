#include <iostream>
#include <vector>
#include "Vector.h"

using namespace std;

void InputData(int& row, int& col)
{
	for (;;)
	{
		cout << "Input rows & cols: ";
		cin >> row >> col;
		if (row <= 0 || col <= 0)
		{
			cout << "Wrong size" << endl;
			continue;
		}
		break;
	}
}
void IndFunc(MyVector& v)
{
	for (int i = 0; i < v.GetRow(); i++)
	{
		for (int j = 0; j < v.GetCol(); j++)
		{
			if (v(i, j) % 2 != 0)
			{
				v(i, j) *= 2;
			}
		}
	}
}

int main()
{
	int row, col;



	MyVector v1 = { {-1,-2, -3},
	 {4,5,6} };

	/*MyVector v2 = { {5,6},
	{7,8} };*/

	
	/*MyVector v1(row, col);
	cin >> v1;*/


	InputData(row, col);
	MyVector v2(row, col);
	cin >> v2;

	cout << "First array" << endl;
	cout << v1;
	cout << "Second array" << endl;
	cout << v2;
	try {
		cout << "Sum\n" << v1 + v2;
		cout << "Diff\n" << v1 - v2;
	}
	catch (BadSize& e)
	{
		e.ShowError();
	}
	try
	{
		cout << "Multiplication\n" << v1 * v2;
	}
	catch (BadSize& e)
	{
		e.ShowError();
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "Index: ";
		cin >> row >> col;
		try
		{
			cout << "Index " << '(' << row << ';' << col << ") = " << v1(row, col) << endl;
		}
		catch (BadIndex& e)
		{
			e.ShowError();
		}
	}

	IndFunc(v1);

	cout << "\nIndividual func" << endl;
	cout << v1;

	system("pause");
	return 0;
}