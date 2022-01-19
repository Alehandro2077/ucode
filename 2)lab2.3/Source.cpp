#include <iostream>
#include <windows.h>
#include "ArrayHeader.h"
#include "Fraction.h"

using namespace std;

void Func(Array<int>& arr)
{
	for (int i = 0; i < arr.GetRow(); i++)
	{
		for (int j = 0; j < arr.GetCol(); j++)
		{
			if (arr(i, j) % 2 != 0)
			{
				arr(i, j) *= 2;
			}
		}
	}
}

void Func(Array<double>& arr)
{
	for (int i = 0; i < arr.GetRow(); i++)
	{
		for (int j = 0; j < arr.GetCol(); j++)
		{
			if (fmod(arr(i, j), 2) != 0)
			{
				arr(i, j) *= 2;
			}
		}
	}
}

void Func(Array<Fraction>& arr)
{
	for (int i = 0; i < arr.GetRow(); i++)
	{
		for (int j = 0; j < arr.GetCol(); j++)
		{
			if (arr(i, j).IsEvNum())
			{
				arr(i, j) = arr(i, j) * 2;
			}
		}
	}
}

template <typename T> 
T getMin(Array<T>& arr)
{
	T min = arr(0, 0);
	for (int i = 0; i < arr.GetRow(); i++)
	{
		for (int j = 0; j < arr.GetCol(); j++)
		{
			if (min > arr(i, j))
			{
				min = arr(i, j);
			}
		}
	}
	return min;
}

void Input(int& row, int& col)
{
	for (;;)
	{
		cout << "Введіть кількість рядків й стовпців: ";
		cin >> row >> col;
		if (row <= 0 || col <= 0)
		{
			cout << "Некоректне значення спробуйте ще раз\n";
			system("pause");
			system("cls");
			continue;
		}
		break;
	}
}

int main()
{
	SetConsoleOutputCP(1251);

	int row = 0, col = 0;

	cout << "Розмір першого масиву\n";
	Input(row, col);
	Array<int> arrn1(row, col);
	Array<double> arrd1(row, col);
	Array<Fraction> arrf1(row, col);
	cout << "Введіть I масив цілих" << endl;
	cin >> arrn1;
	cout << "Введіть I масив дійсних" << endl;
	cin >> arrd1;
	cout << "Введіть I масив простих дробів" << endl;
	cin >> arrf1;

	cout << "Розмір другого масиву\n";

	Input(row, col);

	Array<int> arrn2(row, col);
	Array<double> arrd2(row, col);
	Array<Fraction> arrf2(row, col);

	cout << "Введіть IІ масив цілих" << endl;
	cin >> arrn2;
	cout << "Введіть IІ масив дійсних" << endl;
	cin >> arrd2;
	cout << "Введіть IІ масив простих дробів" << endl;
	cin >> arrf2;
    system("cls");

	cout << "I масив цілих:\n" << arrn1 << endl;
	cout << "I масив дійсних:\n" << arrd1 << endl;
	cout << "I масив простих дробів:\n" << arrf1 << endl;

	cout << "II масив цілих:\n" << arrn2 << endl;
	cout << "II масив дійсних:\n" << arrd2 << endl;
	cout << "II масив простих дробів:\n" << arrf2 << endl;

	try {
		cout << "Сума цілих\n" << arrn1 + arrn2 << endl;
		cout << "Різниця цілих\n" << arrn1 - arrn2 << endl;
		cout << "Сума дійсних\n" << arrd1 + arrd2 << endl;
		cout << "Різниця дійсних\n" << arrd1 - arrd2 << endl;
		cout << "Сума дробів\n" << arrf1 + arrf2 << endl;
		cout << "Різниця дробів\n" << arrf1 - arrf2 << endl;
	}
	catch (BadSize& e)
	{
		e.ShowError();
	}
	try {
		cout << "Добуток цілих\n" << arrn1 * arrn2 << endl;
		cout << "Добуток дійсних\n" << arrd1 * arrd2 << endl;
		cout << "Добуток дробів\n" << arrf1 * arrf2 << endl;
	}
	catch (BadSize& e)
	{
		e.ShowError();
	}
	try
	{
		cout << "Масив цілих, індекс (1,1): " << arrn1(1, 1) << endl;
		cout << "Масив дійсних, індекс (1,1): " << arrd1(1, 1) << endl;
		cout << "Масив дробів, індекс (1,1): " << arrf1(1, 1) << endl;
	}
	catch (BadIndex& e)
	{
		e.ShowError();
	}
	cout << "Мінімальний елемент масиву цілих: " << getMin(arrn1) << endl;
	cout << "Мінімальний елемент масиву дійсних: " << getMin(arrd1) << endl;
	cout << "Мінімальний елемент масиву дробів: " << getMin(arrf1) << endl;

	cout << "Усі елементи з непарними значеннями збільшені в два рази" << endl << endl;

	Func(arrn1);
	Func(arrd1);
	Func(arrf1);

	cout << "Масив цілих:" << endl << endl;
	cout << arrn1 << endl << endl;
	cout << "Масив дійсних:" << endl << endl;
	cout << arrd1 << endl << endl;
	cout << "Масив дробів:" << endl << endl;
	cout << arrf1 << endl << endl;

	system("pause");
	return 0;
}