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
		cout << "Введіть початок інтервалу: " << endl;
		cin >> x1;
		cout << "Кінець інтервалу: " << endl;
		cin >> x2;
		cout << "Крок: " << endl;
		cin >> step;

		if (x1 > x2)
		{
			cout << "Некоректний інтервал, введіть всі значення ще раз: " << endl;
		}
		else if ((x1 + step > x2) || (x1 + step <= x1))
		{
			cout << "Некоректний крок, введіть всі значення ще раз: " << endl;
		}
		else
		{
			break;
		}
	}

	cout << "Перша функція y = sin(x)" << endl;

	cout << "Максимальне значення другої похідної: " << s.MaxDif(x1, x2, step) << endl;
	cout << "Друга функція y = x^3" << endl;
	cout << "Максимальне значення другої похідної: " << f.MaxDif(x1, x2, step) << endl;

	system("pause");
	return 0;
}
