#pragma once

/// <summary>
/// Выполняет действия, определённые в func, над каждым элементом массива pArray.
/// </summary>
/// <typeparam name="T">Тип данных, хранящихся в массиве.</typeparam>
/// <param name="pArray">Массив, над которым необходимо выполнить действия.</param>
/// <param name="length">Длина массива.</param>
/// <param name="func">Функция, определяющая действия, которые нужно выполнить над каждым элементом массива.</param>
template <typename T>
void iter(T* pArray, size_t length, void (*func)(T&))
{
	for (int i = 0; i < length; i++)
	{
		func(pArray[i]);
	}
}

/// <summary>
/// Выполняет действия, определённые в func, над каждым элементом массива pArray.
/// </summary>
/// <typeparam name="T">Тип данных, хранящихся в массиве.</typeparam>
/// <param name="pArray">Массив, над которым необходимо выполнить действия.</param>
/// <param name="length">Длина массива.</param>
/// <param name="func">Функция, определяющая действия, которые нужно выполнить над каждым элементом массива.</param>
template <typename T>
void iter(const T* pArray, size_t length, void(*func)(const T))
{
	for (int i = 0; i < length; i++)
	{
		func(pArray[i]);
	}
}
