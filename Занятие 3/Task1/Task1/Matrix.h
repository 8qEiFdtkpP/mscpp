#pragma once
#include <stdexcept>
#include <sstream>

// Представляет матрицу.
class Matrix
{
private:
	// Количество строк.
	int _rowsCount;

	// Количество столбцов.
	int _colsCount;
	
	// Элементы матрицы.
	double** _elements;

public:
	// Создаёт матрицу с указанными параметрами.
	Matrix(int rowsCount, int colsCount);

	// Копирует матрицу.
	Matrix(const Matrix&);

	// Присваивает матрицу.
	Matrix& operator=(const Matrix& other);

	// Возвращает количество строк.
	int GetRowsCount();

	// Возвращает количество столбцов.
	int GetColsCount();

	// Возвращает элемент по указанным индексам.
	double GetElement(int rowIndex, int colIndex);

	// Устанавливает элемент по указанным индексам.
	void SetElement(int rowIndex, int colIndex, double value);

	// Уничтожает матрицу.
	~Matrix();
};

// Переопределяет вывод матрицы на консоль.
inline std::ostream& operator<<(std::ostream& str, Matrix& v)
{
	std::stringstream res;

	for (int i = 0; i < v.GetRowsCount(); i++)
	{
		for (int j = 0; j < v.GetColsCount(); j++)
		{
			res << v.GetElement(i, j);

			if (j != v.GetColsCount() - 1)
			{
				res << " ";
			}
		}

		res << "; \n";
	}

	return str << res.str();
}
