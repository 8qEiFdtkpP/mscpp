#pragma once

/// <summary>
/// ������� (FIFO).
/// </summary>
/// <typeparam name="T">��� ������, ���������� � �������.</typeparam>
template <typename T>
class Queue
{
	/// <summary>
	/// ��������� �� ������ ������� �������.
	/// </summary>
	Node<T>* head = NULL;

	/// <summary>
	/// ��������� �� ��������� ������� �������.
	/// </summary>
	Node<T>* tail = NULL;

	/// <summary>
	/// ������ �������.
	/// </summary>
	unsigned int size = 0;

	/// <summary>
	/// ������� ������ ������� ������� � ��������� ������ �� �������.
	/// </summary>
	void DeleteHead()
	{
		if (size == 0)
		{
			return;
		}

		assert(head != NULL && "head was NULL when popping from non-empty queue");

		// ��������� �� ��������� "������".
		Node<T>* oldHead = head;

		// ����������� "������" �� ��������� ������� (��� ������� �������� 1 ������������� NULL).
		head = head->next;

		// �������� ������ "������".
		delete oldHead;

		// ���� ����� ����������� "������" �� ��������� �� NULL, ����� ���������� ���������� ������ NULL
		if (head != NULL)
		{
			head->prev = NULL;
		}

		size--;
	}

	/// <summary>
	/// ��������� ������� � ����� ������� � ����������� ������ �� �������.
	/// </summary>
	/// <param name="value">����������� ��������.</param>
	void AddTail(T value)
	{
		if (size > 0)
		{
			assert(tail != NULL && "tail was NULL when pushing to non-empty queue");

			// �������� � ����� ����� �������, ������� � �� ����������, ������ ����� "������".
			tail->next = new Node<T>(value, tail);

			// ����������� "�����" �� ����� �������.
			tail = tail->next;
		}

		// �������� ������� ��������.
		else
		{			
			head = new Node<T>(value);
			tail = head;
		}

		size++;
	}

	/// <summary>
	/// ��������� �����������, ��������� ������ �������.
	/// </summary>
	/// <param name="other">���������� �������.</param>
	void CopyOther(const Queue& other)
	{
		// ��������� ������� ��� ������� �� ���������� �������.
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
	/// ����������� �� ���������.
	/// </summary>
	Queue() {}

	/// <summary>
	/// ����������� �����������.
	/// </summary>
	/// <param name="other">���������� �������.</param>
	Queue(const Queue& other)
	{
		CopyOther(other);
	}

	/// <summary>
	/// ����������� �����������.
	/// </summary>
	/// <param name="other">������������ �������.</param>
	Queue(Queue&& other)
	{
		head = other.head;
		tail = other.tail;
		size = other.size;
	}

	/// <summary>
	/// �������� ������������ ������������.
	/// </summary>
	/// <param name="other">������������� �������.</param>
	/// <returns>���������� ����� ���������� ������������ �������.</returns>
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
	/// �������� ������������ �������������
	/// </summary>
	/// <param name="other">������������ �������.</param>
	/// <returns>���������� ����� ���������� ����������� �������.</returns>
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
	/// ���������� ������ �������� � ����� �������.
	/// </summary>
	/// <param name="value">����������� �������.</param>
	void Push(T value)
	{
		AddTail(value);
	}

	/// <summary>
	/// �������� ������� �������� � �������.
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
	/// ���������� ������ ������� ������� (nullptr exception, ���� ������� �����).
	/// </summary>
	/// <returns></returns>
	T GetFront()
	{
		return head->value;
	}

	/// <summary>
	/// ���������� ��������� ������� ������� (nullptr exception, ���� ������� �����).
	/// </summary>
	/// <returns></returns>
	T GetBack()
	{
		return tail->value;
	}

	/// <summary>
	/// ���������� ������� ������� �������.
	/// </summary>
	/// <returns>true, ���� ������� �����, false � ��������� ������.</returns>
	bool IsEmpty()
	{
		return size == 0;
	}

	/// <summary>
	/// ���������� ������ �������.
	/// </summary>
	/// <returns>������ �������.</returns>
	unsigned int GetSize()
	{
		return size;
	}

	/// <summary>
	/// ���������� �������.
	/// </summary>
	~Queue()
	{
		while (!IsEmpty())
		{
			DeleteHead();
		}
	}
};
