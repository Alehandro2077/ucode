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
		cout << "������ ������� ����� � ��������: ";
		cin >> row >> col;
		if (row <= 0 || col <= 0)
		{
			cout << "���������� �������� ��������� �� ���\n";
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

	cout << "����� ������� ������\n";
	Input(row, col);
	Array<int> arrn1(row, col);
	Array<double> arrd1(row, col);
	Array<Fraction> arrf1(row, col);
	cout << "������ I ����� �����" << endl;
	cin >> arrn1;
	cout << "������ I ����� ������" << endl;
	cin >> arrd1;
	cout << "������ I ����� ������� �����" << endl;
	cin >> arrf1;

	cout << "����� ������� ������\n";

	Input(row, col);

	Array<int> arrn2(row, col);
	Array<double> arrd2(row, col);
	Array<Fraction> arrf2(row, col);

	cout << "������ I� ����� �����" << endl;
	cin >> arrn2;
	cout << "������ I� ����� ������" << endl;
	cin >> arrd2;
	cout << "������ I� ����� ������� �����" << endl;
	cin >> arrf2;
    system("cls");

	cout << "I ����� �����:\n" << arrn1 << endl;
	cout << "I ����� ������:\n" << arrd1 << endl;
	cout << "I ����� ������� �����:\n" << arrf1 << endl;

	cout << "II ����� �����:\n" << arrn2 << endl;
	cout << "II ����� ������:\n" << arrd2 << endl;
	cout << "II ����� ������� �����:\n" << arrf2 << endl;

	try {
		cout << "���� �����\n" << arrn1 + arrn2 << endl;
		cout << "г����� �����\n" << arrn1 - arrn2 << endl;
		cout << "���� ������\n" << arrd1 + arrd2 << endl;
		cout << "г����� ������\n" << arrd1 - arrd2 << endl;
		cout << "���� �����\n" << arrf1 + arrf2 << endl;
		cout << "г����� �����\n" << arrf1 - arrf2 << endl;
	}
	catch (BadSize& e)
	{
		e.ShowError();
	}
	try {
		cout << "������� �����\n" << arrn1 * arrn2 << endl;
		cout << "������� ������\n" << arrd1 * arrd2 << endl;
		cout << "������� �����\n" << arrf1 * arrf2 << endl;
	}
	catch (BadSize& e)
	{
		e.ShowError();
	}
	try
	{
		cout << "����� �����, ������ (1,1): " << arrn1(1, 1) << endl;
		cout << "����� ������, ������ (1,1): " << arrd1(1, 1) << endl;
		cout << "����� �����, ������ (1,1): " << arrf1(1, 1) << endl;
	}
	catch (BadIndex& e)
	{
		e.ShowError();
	}
	cout << "̳�������� ������� ������ �����: " << getMin(arrn1) << endl;
	cout << "̳�������� ������� ������ ������: " << getMin(arrd1) << endl;
	cout << "̳�������� ������� ������ �����: " << getMin(arrf1) << endl;

	cout << "�� �������� � ��������� ���������� ������� � ��� ����" << endl << endl;

	Func(arrn1);
	Func(arrd1);
	Func(arrf1);

	cout << "����� �����:" << endl << endl;
	cout << arrn1 << endl << endl;
	cout << "����� ������:" << endl << endl;
	cout << arrd1 << endl << endl;
	cout << "����� �����:" << endl << endl;
	cout << arrf1 << endl << endl;

	system("pause");
	return 0;
}