#include <iostream>
#include "Stack.h"

int main()
{
	// ���� �� ����� �����.
	Stack<int> st;
	size_t length = 5;

	// ������ � �������������� �������������� ���������.
	std::cout << st << std::endl;

	// ������� ��������
	for (int i = 0; i < length; i++)
	{
		st.push(i + 1);
		std::cout << st << std::endl;
	}

	// �������� �� �������.
	std::cout << "is empty? " << st.empty() << std::endl;

	// ���������� � ��������.
	for (size_t i = 0; i < length; i++)
	{
		std::cout << "popping " << st.top() << std::endl;
		st.pop();

		std::cout << st << std::endl;
	}

	// �������� �� �������.
	std::cout << "is empty? " << st.empty() << std::endl << std::endl;

	// pairs
	Stack<std::pair<int, float>> st2;

	// ������ � �������������� �������������� ���������.
	std::cout << st2 << std::endl;

	// ������� ��������.
	for (size_t i = 0; i < length; i++)
	{
		st2.push(std::pair<int, float>(i + 1, (i + 1) * 1.1));
		std::cout << st2 << std::endl;
	}

	// �������� �� �������.
	std::cout << "is empty? " << st2.empty() << std::endl;

	// ���������� � ��������.
	for (size_t i = 0; i < length; i++)
	{
		std::cout << "popping (" << st2.top().first << "; " << st2.top().second << ")" << std::endl;		
		st2.pop();

		std::cout << st2 << std::endl;
	}

	// �������� �� �������.
	std::cout << "is empty? " << st2.empty() << std::endl;

	return 0;
}