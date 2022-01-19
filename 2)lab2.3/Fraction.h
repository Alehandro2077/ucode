#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

using namespace std;

class Fraction
{
	friend istream& operator>>(istream& in, Fraction& f)
	{
		while (true)
		{
			in >> f.num >> f.den;
			if (f.den == 0)
			{
				cout << "Знаменник не може дорівнювати нулю. Спробуйте ще раз" << endl;
				continue;
			}
			f.Simplify();
			return in;
		}
	}
	friend ostream& operator<<(ostream& out, const Fraction& f)
	{
		if (f.num % f.den == 0)
		{
			return out << f.num / f.den;
		}
		else if (f.den < 0)
		{
			return out << -f.num << '/' << -f.den;
		}
		else
		{
			return out << f.num << '/' << f.den;
		}
	}
	friend Fraction operator+(Fraction f1, Fraction f2)
	{
		Fraction res(f1.num * f2.den + f2.num * f1.den, f1.den * f2.den);
		res.Simplify();
		return res;
	}
	friend Fraction operator-(Fraction f1, Fraction f2)
	{
		Fraction res(f1.num * f2.den - f2.num * f1.den, f1.den * f2.den);
		res.Simplify();
		return res;
	}
	friend Fraction operator*(Fraction f1, Fraction f2)
	{
		Fraction res(f1.num * f2.num, f2.den * f1.den);
		res.Simplify();
		return res;
	}
	friend Fraction operator*(const Fraction& f, const int& value)
	{
		Fraction res(f.num * value, f.den);
		res.Simplify();
		return res;
	}
	friend Fraction operator*(const int& value, const Fraction& f)///////////////
	{
		return operator*(f, value);
	}
	friend Fraction operator/(Fraction f1, Fraction f2)
	{
		if (f2.num == 0)
		{
			throw "Ділення на нуль неможливе";
		}
		else
		{
			Fraction res(f1.num * f2.den, f1.den * f2.num);
			res.Simplify();
			return res;
		}
	}
private:
	int num;
	int den;

public:
	Fraction()
	{
		num = 0; den = 1;
	}
	Fraction(int num, int den) : num(num), den(den) {}
	int GetNum() const { return num; }
	int GetDen() const { return den; }
	void SetNum(int num) { this->num = num; }
	void SetDen(int den) { this->den = den; }
	bool operator <(const Fraction& f);
	bool operator >(const Fraction& f);
	Fraction& operator=(int value); 

	bool IsEvNum()
	{
		return (this->num % this->den == 0) ? 1 : 0;
	}

	void Simplify()
	{
		int gcd = 1;
		if (abs(num) > abs(den))
		{
			for (int i = 2; i <= abs(den); i++)
			{
				if (num % i == 0 && den % i == 0)
				{
					gcd = i;
				}
			}
		}
		else
		{
			for (int i = 2; i <= abs(num); i++)
			{
				if (num % i == 0 && den % i == 0)
				{
					gcd = i;
				}
			}
		}
		num /= gcd;
		den /= gcd;
	}
};

bool Fraction::operator<(const Fraction& f)
{
	return this->num * f.den < this->den* f.num;
}
bool Fraction::operator>(const Fraction& f)
{
	return this->num * f.den > this->den * f.num;
}
Fraction& Fraction::operator=(int value)
{
	Fraction f(value, 1);
	return f;
}
#endif