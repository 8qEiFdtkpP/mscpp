#pragma once

/// <summary>
/// Очередь (FIFO).
/// </summary>
/// <typeparam name="T">Тип данных, хранящихся в очереди.</typeparam>
template <typename T>
class Queue
{
	/// <summary>
	/// Указатель на первый элемент очереди.
	/// </summary>
	Node<T>* head = NULL;

	/// <summary>
	/// Указатель на последний элемент очереди.
	/// </summary>
	Node<T>* tail = NULL;

	/// <summary>
	/// Размер очереди.
	/// </summary>
	unsigned int size = 0;

	/// <summary>
	/// Удаляет первый элемент очереди и уменьшает размер на единицу.
	/// </summary>
	void DeleteHead()
	{
		if (size == 0)
		{
			return;
		}

		assert(head != NULL && "head was NULL when popping from non-empty queue");

		// Указатель на удаляемую "голову".
		Node<T>* oldHead = head;

		// Перемещение "головы" на следующий элемент (для очереди размером 1 устанавливает NULL).
		head = head->next;

		// Удаление старой "головы".
		delete oldHead;

		// Если после перемещения "голова" не указывает на NULL, тогда установить предыдущий равным NULL
		if (head != NULL)
		{
			head->prev = NULL;
		}

		size--;
	}

	/// <summary>
	/// Добавляет элемент в конец очереди и увеличивает размер на единицу.
	/// </summary>
	/// <param name="value">Добавляемое значение.</param>
	void AddTail(T value)
	{
		if (size > 0)
		{
			assert(tail != NULL && "tail was NULL when pushing to non-empty queue");

			// Добавить в конец новый элемент, указать в нём предыдущий, равный этому "хвосту".
			tail->next = new Node<T>(value, tail);

			// Передвинуть "хвост" на новый элемент.
			tail = tail->next;
		}

		// Создание первого элемента.
		else
		{			
			head = new Node<T>(value);
			tail = head;
		}

		size++;
	}

	/// <summary>
	/// Выполняет копирование, используя другую очередь.
	/// </summary>
	/// <param name="other">Копируемая очередь.</param>
	void CopyOther(const Queue& other)
	{
		// Временный элемент для прохода по копируемой очереди.
		const Node<T>* curNode = other.head;

		for (size_t i = 0; i < other.size; i++)
		{
			assert(curNode != NULL && "curNode was NULL when copying queue");
			AddTail(curNode->value);
			curNode = curNode->next;
		}
	}

public:
	/// <summary>
	/// Конструктор по умолчанию.
	/// </summary>
	Queue() {}

	/// <summary>
	/// Конструктор копирования.
	/// </summary>
	/// <param name="other">Копируемая очередь.</param>
	Queue(const Queue& other)
	{
		CopyOther(other);
	}

	/// <summary>
	/// Конструктор перемещения.
	/// </summary>
	/// <param name="other">Перемещаемая очередь.</param>
	Queue(Queue&& other)
	{
		head = other.head;
		tail = other.tail;
		size = other.size;
	}

	/// <summary>
	/// Оператор присваивания копированием.
	/// </summary>
	/// <param name="other">Присваеваемая очередь.</param>
	/// <returns>Полученная после выполнения присваивания очередь.</returns>
	Queue& operator=(const Queue& other)
	{
		if (this == &other)
		{
			return *this;
		}

		while (!IsEmpty())
		{
			DeleteHead();
		}

		CopyOther(other);

		return *this;
	}

	/// <summary>
	/// Оператор присваивания перемещениемю
	/// </summary>
	/// <param name="other">Перемещаемая очередь.</param>
	/// <returns>Полученная после выполнения перемещения очередь.</returns>
	Queue& operator=(Queue&& other)
	{
		if (this == &other)
		{
			return *this;
		}

		while (!IsEmpty())
		{
			DeleteHead();
		}

		head = other.head;
		tail = other.tail;
		size = other.size;

		delete other;

		return *this;
	}

	/// <summary>
	/// Добавление нового элемента в конец очереди.
	/// </summary>
	/// <param name="value">Добавляемый элемент.</param>
	void Push(T value)
	{
		AddTail(value);
	}

	/// <summary>
	/// Удаление первого элемента в очереди.
	/// </summary>
	void Pop()
	{
		if (size > 0)
		{
			DeleteHead();
		}

		else
		{
			return;
		}
	}

	/// <summary>
	/// Возвращает первый элемент очереди (nullptr exception, если очередь пуста).
	/// </summary>
	/// <returns></returns>
	T GetFront()
	{
		return head->value;
	}

	/// <summary>
	/// Возвращает последний элемент очереди (nullptr exception, если очередь пуста).
	/// </summary>
	/// <returns></returns>
	T GetBack()
	{
		return tail->value;
	}

	/// <summary>
	/// Возвращает признак пустоты очереди.
	/// </summary>
	/// <returns>true, если очередь пуста, false в противном случае.</returns>
	bool IsEmpty()
	{
		return size == 0;
	}

	/// <summary>
	/// Возвращает размер очереди.
	/// </summary>
	/// <returns>Размер очереди.</returns>
	unsigned int GetSize()
	{
		return size;
	}

	/// <summary>
	/// Уничтожает очередь.
	/// </summary>
	~Queue()
	{
		while (!IsEmpty())
		{
			DeleteHead();
		}
	}
};
