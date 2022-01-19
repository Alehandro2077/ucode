#ifndef CLASSHEADER_H
#define CLASSHEADER_H
class Solution
{
public:
	double MaxDif(double x1, double x2, double step);
	virtual double Func(double x) = 0;
	virtual ~Solution() {}
};
#endif