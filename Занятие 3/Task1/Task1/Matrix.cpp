#include "Matrix.h"
#include <iostream>

// Создаёт матрицу с указанными параметрами.
Matrix::Matrix(int rowsCount, int colsCount)
{
	if (rowsCount <= 0 || colsCount <= 0)
	{
		throw std::out_of_range("Rows or columns count was less than zero or equal to zero");
	}

	_rowsCount = rowsCount;
	_colsCount = colsCount;

	_elements = new double* [rowsCount];

	for (int i = 0; i < rowsCount; i++)
	{
		_elements[i] = new double[colsCount];
	}
}

// Копирует матрицу.
Matrix::Matrix(const Matrix& other)
{
	_rowsCount = other._rowsCount;
	_colsCount = other._colsCount;

	_elements = new double* [_rowsCount];

	for (int i = 0; i < _rowsCount; i++)
	{
		_elements[i] = new double[_colsCount];

		for (int j = 0; j < _colsCount; j++)
		{
			_elements[i][j] = other._elements[i][j];
		}
	}
}

// Присваивает матрицу.
Matrix& Matrix::operator=(const Matrix& other)
{
	if (this == &other)
	{
		return *this;
	}

	for (int i = 0; i < _rowsCount; i++)
	{
		delete[] _elements[i];
	}

	delete[] _elements;

	_rowsCount = other._rowsCount;
	_colsCount = other._colsCount;

	_elements = new double* [_rowsCount];

	for (int i = 0; i < _rowsCount; i++)
	{
		_elements[i] = new double[_colsCount];

		for (int j = 0; j < _colsCount; j++)
		{
			_elements[i][j] = other._elements[i][j];
		}
	}

	return *this;
}

// Возвращает количество строк.
int Matrix::GetRowsCount()
{
	return _rowsCount;
}

// Возвращает количество столбцов.
int Matrix::GetColsCount()
{
	return _colsCount;
}

// Возвращает элемент по указанным индексам.
double Matrix::GetElement(int rowIndex, int colIndex)
{
	if (rowIndex < 0 || rowIndex >= _rowsCount || colIndex < 0 || colIndex >= _colsCount)
	{
		throw std::out_of_range("Rows or columns index was out of bounds");
	}

	return _elements[rowIndex][colIndex];
}

// Устанавливает элемент по указанным индексам.
void Matrix::SetElement(int rowIndex, int colIndex, double value)
{
	if (rowIndex < 0 || rowIndex >= _rowsCount || colIndex < 0 || colIndex >= _colsCount)
	{
		throw std::out_of_range("Rows or columns index was out of bounds");
	}

	_elements[rowIndex][colIndex] = value;
}

// Уничтожает матрицу.
Matrix::~Matrix()
{
	for (int i = 0; i < _rowsCount; i++)
	{
		delete[] _elements[i];
	}

	delete[] _elements;
}
