#pragma once

/// <summary>
/// ������� �������.
/// </summary>
/// <typeparam name="T">��� ������, �������� � ��������.</typeparam>
template <typename T>
struct Node
{
	/// <summary>
	/// ��������, �������� � ��������.
	/// </summary>
	T value;

	/// <summary>
	/// ��������� �� ��������� �������.
	/// </summary>
	Node* next = NULL;

	/// <summary>
	/// ��������� �� ���������� �������.
	/// </summary>
	Node* prev = NULL;

	/// <summary>
	/// ������ ������� �������.
	/// </summary>
	/// <param name="value">�������� ��������.</param>
	/// <param name="prev">��������� �� ��������� �������.</param>
	/// <param name="next">��������� �� ��������� �������.</param>
	Node(T value, Node* prev = NULL, Node* next = NULL)
		: value(value), prev(prev), next(next) {}

	/// <summary>
	/// ���������� ������� �������.
	/// </summary>
	~Node()
	{
		next = NULL;
		prev = NULL;
	}
};
