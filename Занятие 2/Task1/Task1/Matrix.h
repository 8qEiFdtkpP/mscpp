#pragma once

/// <summary>
/// Матрица.
/// </summary>
class Matrix
{
private:
	double** elements;
	int rows = 3, cols = 3;

public:
	/// <summary>
	/// Создаёт матрицу.
	/// </summary>
	Matrix()
	{
		if (rows <= 0 || cols <= 0)
		{
			throw 1;
		}

		elements = new double* [rows];

		for (int i = 0; i < rows; i++)
		{
			elements[i] = new double[cols];
		}
	}

	/// <summary>
	/// Создаёт матрицу копированием.
	/// </summary>
	/// <param name="object"></param>
	Matrix(const Matrix& object)
	{
		rows = object.rows;
		cols = object.cols;

		if (object.elements == NULL) 
		{
			throw 2;
		}

		elements = new double* [object.rows];

		for (int i = 0; i < rows; i++)
		{
			elements[i] = new double[cols];

			for (int j = 0; j < cols; j++)
			{
				elements[i][j] = object.elements[i][j];
			}
		}
	}

	/// <summary>
	/// Возвращает количество строк.
	/// </summary>
	/// <returns>Количество строк.</returns>
	int GetRowsCount()
	{
		return rows;
	}

	/// <summary>
	/// Возвращает количество столбцов.
	/// </summary>
	/// <returns>Количество столбцов.</returns>
	int GetColumnsCount()
	{
		return cols;
	}

	/// <summary>
	/// Возвращает элемент с указанными индексами.
	/// </summary>
	/// <param name="i">Индекс строки.</param>
	/// <param name="j">Индекс столбца.</param>
	/// <returns>Элемент с указанными индексами.</returns>
	double GetElement(int i, int j)
	{
		if (i < 0 || i >= rows || j < 0 || j >= cols)
		{
			throw 1;
		}

		return elements[i][j];
	}

	/// <summary>
	/// Устанавливает элемент с указанными индексами.
	/// </summary>
	/// <param name="i">Индекс строки.</param>
	/// <param name="j">Индекс столбца.</param>
	/// <param name="value">Назначаемое значение.</param>
	void SetElement(int i, int j, double value)
	{
		if (i < 0 || i >= rows || j < 0 || j >= cols)
		{
			throw 1;
		}

		elements[i][j] = value;
	}

	// Уничтожает матрицу.
	~Matrix()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[]elements[i];
		}

		delete[]elements;
	}
};
