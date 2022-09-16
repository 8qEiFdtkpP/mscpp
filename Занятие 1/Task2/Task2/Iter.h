#pragma once

template <typename T>
void iter(T* pArray, size_t length, void (*func)(T&))
{
	for (int i = 0; i < length; i++)
	{
		func(pArray[i]);
	}
}

template <typename T>
void iter(const T* pArray, size_t length, void(*func)(const T))
{
	for (int i = 0; i < length; i++)
	{
		func(pArray[i]);
	}
}
