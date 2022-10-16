#pragma once

/// <summary>
/// Комплексное число.
/// </summary>
class Complex
{
public:
	/// <summary>
	/// Вещественная и мнимая части числа.
	/// </summary>
	double real = 0, imaginary = 0;

	/// <summary>
	/// Создаёт экземпляр с указанными параметрами
	/// </summary>
	/// <param name="real">Вещественная часть.</param>
	/// <param name="imaginary">Мнимая часть.</param>
	Complex(double real, double imaginary)
	{
		this->real = real;
		this->imaginary = imaginary;
	}
};
