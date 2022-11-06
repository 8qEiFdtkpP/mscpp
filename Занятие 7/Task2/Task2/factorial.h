#pragma once

/// <summary>
/// Факториал числа.
/// </summary>
template<unsigned int N>
struct factorial
{
	static const unsigned int value = N * factorial<N - 1>::value;
};

template<>
struct factorial<0>
{
	static const unsigned int value = 1;
};
