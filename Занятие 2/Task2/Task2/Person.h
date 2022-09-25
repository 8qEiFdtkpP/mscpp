#pragma once

#include <cstddef>
#include <string.h>

class Person
{
private:
	const char* name;
	int age;
public:
	Person(const char* name, int age)
	{
		if (name == NULL || strlen(name) <= 0)
		{
			throw 2;
		}

		if (age <= 0 || age > 120)
		{
			throw 1;
		}

		this->name = name;
		this->age = age;
	}

	const char* GetName()
	{
		return name;
	}

	int GetAge()
	{
		return age;
	}
};
