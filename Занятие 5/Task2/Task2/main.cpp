#include <iostream>
#include "Stack.h"

int main()
{
	// Стек из целых чисел.
	Stack<int> st;
	size_t length = 5;

	// Печать с использованием перегруженного оператора.
	std::cout << st << std::endl;

	// Вставка значений
	for (int i = 0; i < length; i++)
	{
		st.push(i + 1);
		std::cout << st << std::endl;
	}

	// Проверка на пустоту.
	std::cout << "is empty? " << st.empty() << std::endl;

	// Извлечение и удаление.
	for (size_t i = 0; i < length; i++)
	{
		std::cout << "popping " << st.top() << std::endl;
		st.pop();

		std::cout << st << std::endl;
	}

	// Проверка на пустоту.
	std::cout << "is empty? " << st.empty() << std::endl << std::endl;

	// pairs
	Stack<std::pair<int, float>> st2;

	// Печать с использованием перегруженного оператора.
	std::cout << st2 << std::endl;

	// Вставка значений.
	for (size_t i = 0; i < length; i++)
	{
		st2.push(std::pair<int, float>(i + 1, (i + 1) * 1.1));
		std::cout << st2 << std::endl;
	}

	// Проверка на пустоту.
	std::cout << "is empty? " << st2.empty() << std::endl;

	// Извлечение и удаление.
	for (size_t i = 0; i < length; i++)
	{
		std::cout << "popping (" << st2.top().first << "; " << st2.top().second << ")" << std::endl;		
		st2.pop();

		std::cout << st2 << std::endl;
	}

	// Проверка на пустоту.
	std::cout << "is empty? " << st2.empty() << std::endl;

	return 0;
}