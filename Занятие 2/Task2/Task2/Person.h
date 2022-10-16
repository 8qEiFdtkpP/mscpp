#pragma once

#include <cstddef>
#include <string.h>

/// <summary>
/// Человек.
/// </summary>
class Person
{
private:
	const char* name;
	int age;

public:
	/// <summary>
	/// Создаёт экземпляр с указанными параметрами.
	/// </summary>
	/// <param name="name">Имя.</param>
	/// <param name="age">Возраст.</param>
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

	/// <summary>
	/// Возврщает имя человека.
	/// </summary>
	/// <returns>Имя человека.</returns>
	const char* GetName()
	{
		return name;
	}

	/// <summary>
	/// Возвращает возраст человека.
	/// </summary>
	/// <returns>Возраст человека.</returns>
	int GetAge()
	{
		return age;
	}
};
