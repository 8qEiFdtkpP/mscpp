#pragma once
template <typename T>
void swap(T& a, T& b)
{
	T tempA = a;
	a = b;
	b = tempA;
}
