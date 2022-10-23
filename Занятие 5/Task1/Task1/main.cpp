#include <iostream>
#include <assert.h>
#include "Queue.h"

/// <summary>
/// Печатает содержимое очереди.
/// </summary>
/// <typeparam name="T">Тип данных, хранящихся в очереди.</typeparam>
/// <param name="q">Печатаемая очередь.</param>
template <typename T>
void PrintQueue(Queue<T> q)
{
	if (q.IsEmpty())
	{
		std::cout << "Queue is empty";
	}

	while (!q.IsEmpty())
	{
		if (q.GetFront() != NULL)
		{
			std::cout << *q.GetFront() << " ";
		}

		else
		{
			std::cout << "NULL ";
		}

		q.Pop();
	}

	std::cout << std::endl;
}

int main()
{
	Queue<int*> q;

	// Массив указателей на int.
	int** numbers = new int*[5];

	// Тестирование вставки в очередь.
	for (int i = 0; i < 5; i++)
	{
		// Создание указателя на int.
		numbers[i] = new int[1] {i};

		q.Push(numbers[i]);

		assert(q.GetFront() == numbers[0] && "Front does not point to 0");
		assert(q.GetBack() == numbers[i] && "Back does not point to i");
		assert(q.GetSize() == (i + 1) && "Size is not i+1");
		assert(!q.IsEmpty() && "Queue is empty");
	}

	// Замена значения, на которое указывает последний элемент очереди.
	*q.GetBack() = 5;
	assert(*q.GetBack() == 5 && "Back is not 5");

	PrintQueue(q);

	// Тестирование удаления из очереди.
	for (size_t i = 0; i < 4; i++)
	{
		q.Pop();

		assert(q.GetFront() == numbers[i + 1] && "Front does not point to i+1");
		assert(q.GetBack() == numbers[4] && "Back does not point to 4");
		assert(q.GetSize() == (4 - i) && "Size is not 4-i");
		assert(!q.IsEmpty() && "Queue is empty");
	}

	q.Pop();
	assert(q.GetSize() == 0 && "Size is not 0");
	assert(q.IsEmpty() && "Queue is not empty");

	PrintQueue(q);
}
