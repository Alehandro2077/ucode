#include <iostream>
#include <cmath>
#include <windows.h>
#include "Classheader.h"

using namespace std;

class Sin : public Solution
{
private:
	virtual double Func(double x) override
	{
		return sin(x);
	}
};

class Func2 : public Solution
{
private:
	virtual double Func(double x) override
	{
		return pow(x, 3);
	}
};

using namespace std;

int main()
{
	SetConsoleOutputCP(1251);

	Sin s;
	Func2 f;
	double x1, x2, step;

	while (true)
	{
		cout << "������ ������� ���������: " << endl;
		cin >> x1;
		cout << "ʳ���� ���������: " << endl;
		cin >> x2;
		cout << "����: " << endl;
		cin >> step;

		if (x1 > x2)
		{
			cout << "����������� ��������, ������ �� �������� �� ���: " << endl;
		}
		else if ((x1 + step > x2) || (x1 + step <= x1))
		{
			cout << "����������� ����, ������ �� �������� �� ���: " << endl;
		}
		else
		{
			break;
		}
	}

	cout << "����� ������� y = sin(x)" << endl;

	cout << "����������� �������� ����� �������: " << s.MaxDif(x1, x2, step) << endl;
	cout << "����� ������� y = x^3" << endl;
	cout << "����������� �������� ����� �������: " << f.MaxDif(x1, x2, step) << endl;

	system("pause");
	return 0;
}
