#pragma once
#include <iostream>
#include "sqrt.h"

double* solve(double a, double b, double c)
{
	double x1r, x2r;
	double x1i = 0, x2i = 0;

	if (a == 0 && b == 0 && c != 0)
	{
		std::cout << "Корней нет" << std::endl;
		return NULL;
	}

	else if (a == 0 && b == 0 && c == 0)
	{
		std::cout << "Уравнение имеет бесконечное множество решений" << std::endl;
		return NULL;
	}

	if (a == 0)
	{
		x1r = x2r = -c / b;
	}

	else
	{
		double d = b * b - 4 * a * c;

		if (d >= 0)
		{
			x1r = (-b + fastSqrt(d)) / (2 * a);
			x2r = (-b - fastSqrt(d)) / (2 * a);
		}

		else
		{
			x1r = x2r = -b / (2 * a);
			x1i = fastSqrt(-d) / (2 * a);
			x2i = -fastSqrt(-d) / (2 * a);
		}
	}

	return new double[4]{ x1r, x1i, x2r, x2i };
}
