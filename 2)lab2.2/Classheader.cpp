#include "Classheader.h"
#include <cmath>
#include <iostream>


using namespace std;

double Solution::MaxDif(double x1, double x2, double step)
{
	double h = 0.0000001, maxd = 0, f;
	for (double x = x1; x <= x2; x += step)
	{
		cout << "x= " << x1++ << endl;
		f = (Func(x + h) - Func(x - h)) / (2 * h);
		cout << "2 похідна " << f << endl;
		if (f > maxd)
		{
			maxd = f;
		}
	}
	return maxd;
}