#pragma once

/// <summary>
/// Элемент очереди.
/// </summary>
/// <typeparam name="T">Тип данных, хранимый в элементе.</typeparam>
template <typename T>
struct Node
{
	/// <summary>
	/// Значение, хранимое в элементе.
	/// </summary>
	T value;

	/// <summary>
	/// Указатель на следующий элемент.
	/// </summary>
	Node* next = NULL;

	/// <summary>
	/// Указатель на предыдущий элемент.
	/// </summary>
	Node* prev = NULL;

	/// <summary>
	/// Создаёт элемент очереди.
	/// </summary>
	/// <param name="value">Значение элемента.</param>
	/// <param name="prev">Указатель на предудщий элемент.</param>
	/// <param name="next">Указатель на следующий элемент.</param>
	Node(T value, Node* prev = NULL, Node* next = NULL)
		: value(value), prev(prev), next(next) {}

	/// <summary>
	/// Уничтожает элемент очереди.
	/// </summary>
	~Node()
	{
		next = NULL;
		prev = NULL;
	}
};
