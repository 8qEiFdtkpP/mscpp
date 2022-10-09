#pragma once

/// <summary>
/// Ёлемент очереди.
/// </summary>
/// <typeparam name="T">“ип данных, хранимый в элементе.</typeparam>
template <typename T>
struct Node
{
	/// <summary>
	/// «начение, хранимое в элементе.
	/// </summary>
	T value;

	/// <summary>
	/// ”казатель на следующий элемент.
	/// </summary>
	Node* next = NULL;

	/// <summary>
	/// ”казатель на предыдущий элемент.
	/// </summary>
	Node* prev = NULL;

	/// <summary>
	/// —оздаЄт элемент очереди.
	/// </summary>
	/// <param name="value">«начение элемента.</param>
	/// <param name="prev">”казатель на предудщий элемент.</param>
	/// <param name="next">”казатель на следующий элемент.</param>
	Node(T value, Node* prev = NULL, Node* next = NULL)
		: value(value), prev(prev), next(next) {}

	/// <summary>
	/// ”ничтожает элемент очереди.
	/// </summary>
	~Node()
	{
		next = NULL;
		prev = NULL;
	}
};
