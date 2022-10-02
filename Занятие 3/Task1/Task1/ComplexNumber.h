#pragma once

#include<iostream>

// Представляет комплексное число.
class ComplexNumber
{
public:
	// Вещественная часть комплексного числа.
	double real;

	// Мнимая часть комплексного числа.
	double imaginary;

	// Создаёт комплексное число с параметрами по умолчанию.
	ComplexNumber();

	// Создаёт комплексное число с указанными параметрами.
	ComplexNumber(double real, double imaginary);
};

// Переопределение вывода на консоль.
inline std::ostream& operator<<(std::ostream& str, ComplexNumber const& v)
{
	if (v.imaginary > 0)
	{
		if (v.imaginary == 1)
		{
			return str << v.real << " + i";
		}

		else
		{
			return str << v.real << " + " << v.imaginary << "i";
		}
	}

	else if (v.imaginary < 0)
	{
		if (v.imaginary == -1)
		{
			return str << v.real << " - i";
		}

		else
		{
			return str << v.real << " - " << -v.imaginary << "i";
		}
		
	}

	else
	{
		return str << v.real;
	}
}
