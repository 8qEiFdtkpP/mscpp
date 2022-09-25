#pragma once

class Matrix
{
private:
	double** elements;
	int rows = 3, cols = 3;

public:
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

	int GetRowsCount()
	{
		return rows;
	}

	int GetColumnsCount()
	{
		return cols;
	}

	double GetElement(int i, int j)
	{
		if (i < 0 || i >= rows || j < 0 || j >= cols)
		{
			throw 1;
		}

		return elements[i][j];
	}

	void SetElement(int i, int j, double value)
	{
		if (i < 0 || i >= rows || j < 0 || j >= cols)
		{
			throw 1;
		}

		elements[i][j] = value;
	}

	~Matrix()
	{
		for (int i = 0; i < rows; i++)
		{
			delete[]elements[i];
		}

		delete[]elements;
	}
};
