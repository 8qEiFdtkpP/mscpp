#include <iostream>
#include "Person.h"


template <typename T>
T Next(T value)
{
	return value + 1;
}

template <>
const char* Next(const char* value)
{
	if (value == NULL || strlen(value) <= 0)
	{
		throw 2;
	}

	size_t valueLen = strlen(value);
	char* res = new char[valueLen + 1];

	strcpy(res, value);

	if (res != NULL)
	{
		res[valueLen-1] += 1;
	}

	return res;
}

Person* Next(Person* p)
{
	if (p == NULL)
	{
		throw 2;
	}

	Person* res = new Person(p->GetName(), p->GetAge() + 1);

	delete p;
	return res;
}

int main()
{
	int a = Next(-2);
	std::cout << a << "; ";

	a = Next(a);
	std::cout << a << "; ";

	a = Next(a);
	std::cout << a << std::endl;


	double b = Next(-2.25);
	std::cout << b << "; ";

	b = Next(b);
	std::cout << b << "; ";

	b = Next(b);
	std::cout << b << std::endl;


	const char* str1 = Next("a");
	std::cout << str1 << "; ";

	str1 = Next(str1);
	std::cout << Next(str1) << "; ";

	str1 = Next(str1);
	std::cout << Next(str1) << std::endl;


	Person* ivan = new Person("Ivan", 21);

	ivan = Next(ivan);
	std::cout << ivan->GetName() << "; " << ivan->GetAge() << std::endl;

	ivan = Next(ivan);
	std::cout << ivan->GetName() << "; " << ivan->GetAge() << std::endl;
}
