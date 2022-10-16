#pragma once
#include <iostream>
#include "sqrt.h"

/// <summary>
/// Решает квадратное уравнение с заданными вещественными коэффициентами.
/// </summary>
/// <param name="a">Коэффициент при x^2.</param>
/// <param name="b">Коэффициент при x.</param>
/// <param name="c">Свободный член уравнения.</param>
/// <returns>Решения уравнения x1 и x2 с вещественными и комплексными значениями 
/// x1 + x1i и x2 + x2i.</returns>
double* solve(double a, double b, double c)
{
	double x1r, x2r;
	double x1i = 0, x2i = 0;

	if (a == 0 && b == 0 && c != 0)
	{
		setlocale(LC_ALL, "Russian");
		std::cout << "Корней нет" << std::endl;
		return NULL;
	}

	else if (a == 0 && b == 0 && c == 0)
	{
		setlocale(LC_ALL, "Russian");
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
