#include <iostream>
#include <stdexcept>
#include "ComplexNumber.h"
#include "Matrix.h"

// Сложение двух значений любого типа по значениям.
template <typename T>
T Add(T value1, T value2)
{
	std::cout << "adding any type (" << value1 << ") + (" << value2 << ") values by values" << std::endl;
	return value1 + value2;
}

// Сложение двух комплексных чисел по значениям.
template <>
ComplexNumber Add(ComplexNumber value1, ComplexNumber value2)
{
	std::cout << "adding complex numbers (" << value1 << ") + (" << value2 << ") by values" << std::endl;
	return ComplexNumber(value1.real + value2.real, value1.imaginary + value2.imaginary);
}

// Сложение двух матриц по значениям.
template<>
Matrix Add(Matrix value1, Matrix value2)
{
	int resRowsCount = value1.GetRowsCount();
	int resColsCount = value1.GetColsCount();

	if (resRowsCount != value2.GetRowsCount() || resColsCount != value2.GetColsCount())
	{
		throw std::invalid_argument("Matrices dimensions are inconsistent");
	}

	std::cout << "adding matrices " << resRowsCount << "x" << resColsCount << " by values" << std::endl;
	Matrix res(resRowsCount, resColsCount);

	for (int i = 0; i < resRowsCount; i++)
	{
		for (int j = 0; j < resColsCount; j++)
		{
			res.SetElement(i, j, value1.GetElement(i, j) + value2.GetElement(i, j));
		}
	}

	return res;
}

// Сложение двух строк по значениям.
std::string Add(std::string value1, std::string value2)
{
	std::cout << "adding strings (" << value1 << ") + (" << value2 << ") by values" << std::endl;
	return value1 + value2;
}

// Сложение двух значений любого типа по указателям.
template <typename T>
T* Add(T* value1, T* value2)
{
	if (value1 == NULL || value2 == NULL)
	{
		throw std::nullptr_t();
	}

	std::cout << "adding any type (" << *value1 << ") + (" << *value2 << ") values by pointers" << std::endl;

	T* res = new T[1];
	*res = (*value1) + (*value2);

	return res;
}

// Сложение двух си-строк по указателям.
const char* Add(const char* value1, const char* value2)
{
	if (value1 == NULL || value2 == NULL)
	{
		throw std::nullptr_t();
	}

	std::cout << "adding c-strings (" << value1 << ") + (" << value2 << ") by pointers" << std::endl;
	char* result = new char[strlen(value1) + strlen(value2) + 1];

	strcpy(result, value1);
	strcat(result, value2);

	return result;
}

// Сложение двух комплексных чисел по указателям.
template <>
ComplexNumber* Add(ComplexNumber* value1, ComplexNumber* value2)
{
	if (value1 == NULL || value2 == NULL)
	{
		throw std::nullptr_t();
	}

	std::cout << "adding (" << *value1 << ") + (" << *value2 << ") by pointers" << std::endl;

	return new ComplexNumber(value1->real + value2->real, value1->imaginary + value2->imaginary);
}

// Сложение двух матриц по указателям.
template <>
Matrix* Add(Matrix* value1, Matrix* value2)
{
	if (value1 == NULL || value2 == NULL)
	{
		throw std::nullptr_t();
	}

	int resRowsCount = value1->GetRowsCount();
	int resColsCount = value1->GetColsCount();

	if (resRowsCount != value2->GetRowsCount() || resColsCount != value2->GetColsCount())
	{
		throw std::invalid_argument("Matrices dimensions are inconsistent");
	}

	std::cout << "adding matrices " << resRowsCount << "x" << resColsCount << " by pointers" << std::endl;
	Matrix* res = new Matrix(resRowsCount, resColsCount);

	for (int i = 0; i < resRowsCount; i++)
	{
		for (int j = 0; j < resColsCount; j++)
		{
			res->SetElement(i, j, value1->GetElement(i, j) + value2->GetElement(i, j));
		}
	}

	return res;
}

int main()
{
	// Комплексные числа.
	ComplexNumber c1(2, 4);
	ComplexNumber c2(1, -3);
	ComplexNumber* c3 = new ComplexNumber(3, 1);
	ComplexNumber* c4 = new ComplexNumber(-1, 3);

	ComplexNumber cnRes;
	ComplexNumber* pCnRes = NULL;


	// Сложение комплексных чисел по значениям.
	cnRes = Add(c1, c2);
	std::cout << "(" << c1 << ") + (" << c2 << ") = " << cnRes << std::endl << std::endl;

	cnRes = Add(c1, *c3);
	std::cout << "(" << c1 << ") + (" << *c3 << ") = " << cnRes << std::endl << std::endl;

	cnRes = Add(*c4, c2);
	std::cout << "(" << *c4 << ") + (" << c2 << ") = " << cnRes << std::endl << std::endl;

	cnRes = Add(*c3, *c4);
	std::cout << "(" << *c3 << ") + (" << *c4 << ") = " << cnRes << std::endl << std::endl;


	// Сложение комплексных чисел по указателям.
	pCnRes = Add(c3, c4);
	std::cout << "(" << *c3 << ") + (" << *c4 << ") = " << *pCnRes << std::endl << std::endl;
	delete pCnRes;

	pCnRes = Add(c3, &c2);
	std::cout << "(" << *c3 << ") + (" << c2 << ") = " << *pCnRes << std::endl << std::endl;
	delete pCnRes;

	pCnRes = Add(&c1, c4);
	std::cout << "(" << c1 << ") + (" << *c4 << ") = " << *pCnRes << std::endl << std::endl;
	delete pCnRes;

	pCnRes = Add(&c2, &c1);
	std::cout << "(" << c2 << ") + (" << c1 << ") = " << *pCnRes << std::endl << std::endl;
	delete pCnRes;


	// Матрицы.
	Matrix m1(2, 2);
	m1.SetElement(0, 0, 1.5); m1.SetElement(0, 1, -0.5);
	m1.SetElement(1, 0, -12.245); m1.SetElement(1, 1, 0);

	Matrix m2(2, 2);
	m2.SetElement(0, 0, -7.12); m2.SetElement(0, 1, 0);
	m2.SetElement(1, 0, 0.52); m2.SetElement(1, 1, -2.5);

	Matrix* m3 = new Matrix(2, 2);
	m3->SetElement(0, 0, 2.34); m3->SetElement(0, 1, 0);
	m3->SetElement(1, 0, -2.52); m3->SetElement(1, 1, 1.23);

	Matrix* m4 = new Matrix(2, 2);
	m4->SetElement(0, 0, 5.24); m4->SetElement(0, 1, -1);
	m4->SetElement(1, 0, -5.53); m4->SetElement(1, 1, 2.15);


	// Сложение матриц по значениям.
	Matrix mRes = Add(m1, m2);
	std::cout << "res = " << mRes << std::endl;

	mRes = Add(m1, *m3);
	std::cout << "res = " << mRes << std::endl;

	mRes = Add(*m4, m2);
	std::cout << "res = " << mRes << std::endl;

	mRes = Add(*m3, *m4);
	std::cout << "res = " << mRes << std::endl;


	//Сложение матриц по указателям.
	Matrix* pMRes = Add(m3, m4);
	std::cout << "res = " << *pMRes << std::endl;
	delete pMRes;

	pMRes = Add(m3, &m1);
	std::cout << "res = " << *pMRes << std::endl;
	delete pMRes;

	pMRes = Add(&m2, m4);
	std::cout << "res = " << *pMRes << std::endl;
	delete pMRes;

	pMRes = Add(&m1, &m2);
	std::cout << "res = " << *pMRes << std::endl;
	delete pMRes;


	// Си-строки.
	const char* cStr1 = "Test";
	const char* cStr2 = "ing";

	// Сложение си-строк.
	const char* pCStrRes = Add(cStr1, cStr2);
	std::cout << "res = " << pCStrRes << std::endl << std::endl;


	// Строки.
	std::string str1 = "Test";
	std::string str2 = "ing";

	// Сложение строк.
	std::string sRes = Add(str1, str2);
	std::cout << "res = " << sRes << std::endl << std::endl;


	// Числа.
	int a = 5;
	int b = 7;

	// Сложение чисел по значению.
	int iRes = Add(a, b);
	std::cout << "res = " << iRes << std::endl << std::endl;

	// Сложение чисел по указателю.
	int* pIRes = Add(&a, &b);
	std::cout << "res = " << *pIRes << std::endl << std::endl;
}
