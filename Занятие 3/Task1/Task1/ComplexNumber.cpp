#include "ComplexNumber.h"

// Создаёт комплексное число с параметрами по умолчанию.
ComplexNumber::ComplexNumber() : real(0), imaginary(0)
{

}

// Создаёт комплексное число с указанными параметрами.
ComplexNumber::ComplexNumber(double real, double imaginary) : real(real), imaginary(imaginary)
{

}
