#include <iostream>
#include <assert.h>
#include "Node.h"
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
		std::cout << q.GetFront() << " ";
		q.Pop();
	}

	std::cout << std::endl;
}

int main()
{
	Queue<int> q;

	// Тестирование вставки в очередь.
	for (int i = 0; i < 5; i++)
	{
		q.Push(i);
		assert(q.GetFront()==0 && "Front is not 0");
		assert(q.GetBack() == i && "Back is not i");
		assert(q.GetSize() == (i + 1) && "Size is not i+1");
		assert(!q.IsEmpty() && "Queue is empty");
	}

	PrintQueue(q);

	// Тестирование удаления из очереди.
	for (size_t i = 0; i < 4; i++)
	{
		q.Pop();
		assert(q.GetFront() == i+1 && "Front is not i+1");
		assert(q.GetBack() == 4 && "Back is not 4");
		assert(q.GetSize() == (4-i) && "Size is not 4-i");
		assert(!q.IsEmpty() && "Queue is empty");
	}

	q.Pop();
	assert(q.GetSize() == 0 && "Size is not 0");
	assert(q.IsEmpty() && "Queue is not empty");

	PrintQueue(q);

	// Тестирование элемента очереди.
	Node<int*> nodeInt1(NULL, NULL, NULL);
	assert(nodeInt1.value == NULL && "Node1's value is not NULL");
	assert(nodeInt1.prev == NULL && "Node1's prev is not NULL");
	assert(nodeInt1.next == NULL && "Node1's next is not NULL");

	int node2IntValue = 5;
	Node<int*> nodeInt2(&node2IntValue, &nodeInt1, NULL);
	assert(*nodeInt2.value == 5 && "Node2's value is not 5");
	assert(nodeInt2.prev == &nodeInt1 && "Node2's prev is not Node1");
	assert(nodeInt2.next == NULL && "Node2's next is not NULL");

	nodeInt1.next = &nodeInt2;
	assert(nodeInt1.value == NULL && "Node1's value is not NULL");
	assert(nodeInt1.prev == NULL && "Node1's prev is not NULL");
	assert(nodeInt1.next == &nodeInt2 && "Node1's next is not Node2");
	assert(*nodeInt1.next->value == node2IntValue && "Node1's next value is not 5");
}
