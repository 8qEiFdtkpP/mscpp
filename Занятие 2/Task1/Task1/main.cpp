#include <iostream>
#include "Matrix.h"
#include "Complex.h"

template <typename T>
double Abs(T value)
{
	return (value >= 0) ? value : -value;
}

double GetDeterminant3x3(Matrix& m)
{
	return m.GetElement(0, 0) * m.GetElement(1, 1) * m.GetElement(2, 2)
		- m.GetElement(0, 0) * m.GetElement(1, 2) * m.GetElement(2, 1)
		- m.GetElement(0, 1) * m.GetElement(1, 0) * m.GetElement(2, 2)
		+ m.GetElement(0, 1) * m.GetElement(1, 2) * m.GetElement(2, 0)
		+ m.GetElement(0, 2) * m.GetElement(1, 0) * m.GetElement(2, 1)
		- m.GetElement(0, 2) * m.GetElement(1, 1) * m.GetElement(2, 0);
}

template <>
double Abs(Matrix* m)
{
	if (m == NULL)
	{
		throw 2;
	}

	if (m->GetRowsCount() != 3 && m->GetColumnsCount() != 3)
	{
		throw 1;
	}

	return GetDeterminant3x3(*m);
}

template <>
double Abs(Matrix m)
{
	if (m.GetRowsCount() != 3 && m.GetColumnsCount() != 3)
	{
		throw 1;
	}

	return GetDeterminant3x3(m);
}

template <>
double Abs(Complex* c)
{
	if (c == NULL)
	{
		throw 2;
	}

	return sqrt(c->real * c->real + c->imaginary * c->imaginary);
}

template <>
double Abs(Complex c)
{
	return sqrt(c.real * c.real + c.imaginary * c.imaginary);
}

int main()
{
	// Первая матрица.
	Matrix m1;

	m1.SetElement(0, 0, 2);
	m1.SetElement(0, 1, 5);
	m1.SetElement(0, 2, -3);

	m1.SetElement(1, 0, 1);
	m1.SetElement(1, 1, 4);
	m1.SetElement(1, 2, -2);

	m1.SetElement(2, 0, -7);
	m1.SetElement(2, 1, 3);
	m1.SetElement(2, 2, 0);

	std::cout << Abs(m1) << std::endl;

	// Вторая матрица.
	Matrix* m2 = new Matrix();

	m2->SetElement(0, 0, 5);
	m2->SetElement(0, 1, 7);
	m2->SetElement(0, 2, 1);

	m2->SetElement(1, 0, -4);
	m2->SetElement(1, 1, 1);
	m2->SetElement(1, 2, 0);

	m2->SetElement(2, 0, 2);
	m2->SetElement(2, 1, 0);
	m2->SetElement(2, 2, 3);

	std::cout << Abs(m2) << std::endl;

	// Первое комплексное число.
	Complex c1(3, -4);
	std::cout << Abs(c1) << std::endl;

	// Второе комплексное число.
	Complex* c2 = new Complex(1, sqrt(3));
	std::cout << Abs(c2) << std::endl;

	// Целые числа.
	int i1 = 5, i2 = -100, i3 = 0;
	std::cout << Abs(i1) << "; " << Abs(i2) << "; " << Abs(i3) << std::endl;

	float f1 = 3.24, f2 = -1.55, f3 = 0;
	std::cout << Abs(f1) << "; " << Abs(f2) << "; " << Abs(f3) << std::endl;

	return 0;
}