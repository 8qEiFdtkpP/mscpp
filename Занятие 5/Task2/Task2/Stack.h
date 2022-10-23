#pragma once
#include <vector>
#include <iostream>

template <typename T>
class Stack;
template <typename T>
std::ostream& operator<<(std::ostream&, Stack<T> const&);

// Стек (LIFO).
template <typename T>
class Stack
{
	friend std::ostream& operator<<<T>(std::ostream& str, Stack<T> const& v);

private:
	/// <summary>
	/// Элементы стека.
	/// </summary>
	std::vector<T> elements;

public:
	/// <summary>
	/// Добавляет элемент.
	/// </summary>
	/// <param name="value">Добавляемый элемент.</param>
	void push(T value);

	/// <summary>
	/// Удаляет элемент.
	/// </summary>
	void pop();

	/// <summary>
	/// Возвращает элемент на вершине.
	/// </summary>
	/// <returns>Элемент на вершине.</returns>
	T top();

	/// <summary>
	/// Возвращает признак пустоты.
	/// </summary>
	/// <returns>Признак пустоты</returns>
	bool empty();
};

/// <summary>
/// Добавляет элемент.
/// </summary>
/// <typeparam name="T">Тип хранимых данных.</typeparam>
/// <param name="value">Добавляемое значение.</param>
template <typename T>
void Stack<T>::push(T value)
{
	elements.push_back(value);
}

/// <summary>
/// Удаляет элемент.
/// </summary>
/// <typeparam name="T">Тип хранимых данных.</typeparam>
template <typename T>
void Stack<T>::pop()
{
	if (!elements.empty())
	{
		elements.pop_back();
	}
}

/// <summary>
/// Возвращает элемент на вершине.
/// </summary>
/// <typeparam name="T">Тип хранимых данных.</typeparam>
/// <returns>Элемент на вершине.</returns>
template <typename T>
T Stack<T>::top()
{
	return elements.back();
}

/// <summary>
/// Возвращает признак пустоты.
/// </summary>
/// <typeparam name="T">Тип хранимых данных</typeparam>
/// <returns>Признак пустоты.</returns>
template <typename T>
bool Stack<T>::empty()
{
	return elements.empty();
}

// Переопределение вывода на консоль.
template <typename T>
inline std::ostream& operator<<(std::ostream& str, Stack<T> const& v)
{
	size_t length = v.elements.size();

	for (int i = length - 1; i > -1; i--)
	{
		str << v.elements[i] << " ";
	}

	return str;
}

// -------------------------------------------------------------------------------------------
// Специализация стека.
// -------------------------------------------------------------------------------------------
template <typename T1, typename T2>
class Stack<std::pair<T1, T2>>;
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& str, Stack<std::pair<T1, T2>> const& v);

template <typename T1, typename T2>
class Stack<std::pair<T1, T2>>
{
	friend std::ostream& operator<<<T1, T2>(std::ostream& str, Stack<std::pair<T1, T2>> const& v);

private:
	/// <summary>
	/// Элементы стека.
	/// </summary>
	std::vector<std::pair<T1, T2>> elements;

public:
	/// <summary>
	/// Добавляет элемент.
	/// </summary>
	/// <param name="value">Добавляемый элемент.</param>
	void push(std::pair<T1, T2> value);

	/// <summary>
	/// Удаляет элемент.
	/// </summary>
	void pop();

	/// <summary>
	/// Возвращает элемент на вершине.
	/// </summary>
	/// <returns>Элемент на вершине.</returns>
	std::pair<T1, T2> top();

	/// <summary>
	/// Возвращает признак пустоты.
	/// </summary>
	/// <returns>Признак пустоты</returns>
	bool empty();
};

/// <summary>
/// Добавляет элемент.
/// </summary>
/// <typeparam name="T1">Первый тип данных в паре.</typeparam>
/// <typeparam name="T2">Второй тип данных в паре.</typeparam>
/// <param name="value">Добавляемое значение.</param>
template <typename T1, typename T2>
void Stack<std::pair<T1, T2>>::push(std::pair<T1, T2> value)
{
	elements.push_back(value);
}

/// <summary>
/// Удаляет элемент.
/// </summary>
/// <typeparam name="T1">Первый тип данных в паре.</typeparam>
/// <typeparam name="T2">Второй тип данных в паре.</typeparam>
template <typename T1, typename T2>
void Stack<std::pair<T1, T2>>::pop()
{
	if (!elements.empty())
	{
		elements.pop_back();
	}
}

/// <summary>
/// Возвращает элемент на вершине.
/// </summary>
/// <typeparam name="T1">Первый тип данных в паре.</typeparam>
/// <typeparam name="T2">Второй тип данных в паре.</typeparam>
/// <returns>Элемент на вершине.</returns>
template <typename T1, typename T2>
std::pair<T1, T2> Stack<std::pair<T1, T2>>::top()
{
	return elements.back();
}

/// <summary>
/// Возвращает признак пустоты.
/// </summary>
/// <typeparam name="T1">Первый тип данных в паре.</typeparam>
/// <typeparam name="T2">Второй тип данных в паре.</typeparam>
/// <returns>Признак пустоты.</returns>
template <typename T1, typename T2>
bool Stack<std::pair<T1, T2>>::empty()
{
	return elements.empty();
}

// Переопределение вывода на консоль.
template <typename T1, typename T2>
inline std::ostream& operator<<(std::ostream& str, Stack<std::pair<T1, T2>> const& v)
{
	size_t length = v.elements.size();

	for (int i = length - 1; i > -1; i--)
	{
		str << "("<<v.elements[i].first<<"; "<<v.elements[i].second << ") ";
	}

	return str;
}
