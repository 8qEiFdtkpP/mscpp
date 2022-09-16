#include <iostream>
#include "Iter.h"

template<typename T>
void print(T* pArray, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << pArray[i] << " ";
	}
}

int main()
{
	size_t aLength = 5;
	int a[] = { 1, 2, 3, 4, 5 };

	iter<int>(a, aLength, [](int& element) {
		element = (element%2==0)? element*2 : -element;
	});

	print(a, aLength);
	std::cout << std::endl;


	size_t stringLength = 4;
	const char* string = "test";

	iter<char>(string, stringLength, [](char element) {
		std::cout << element;
	});
	std::cout << std::endl;


	size_t fractionsCount = 3;
	float* fractions = new float[fractionsCount];

	fractions[0] = 4.4;
	fractions[1] = 2.7;
	fractions[2] = 5;

	iter<float>(fractions, fractionsCount, [](float& element)
	{
		element /= 2;
	});

	print(fractions, fractionsCount);
}